
#include "MacEmuLib.h"
#include "vector_array.h"

PixMap screenBits;

console_options_type console_options;

extern struct Library		 	*DOSBase ;
extern struct DOSIFace		*IDOS ;

struct DebugIFace		*IDebug = NULL;

struct Library 			*AHIBase = NULL;
struct AHIIFace			*IAHI = NULL;

struct Library 			*AslBase = NULL;
struct AslIFace			*IAsl = NULL;

struct LocaleIFace		*ILocale  = NULL;
struct Library			*LocaleBase = NULL;

struct Library			*DiskfontBase = NULL;
struct DiskfontIFace		*IDiskfont = NULL;

struct Library			*GadToolsBase = NULL;
struct DiskfontIFace		*IGadTools = NULL;

struct KeymapIFace		*IKeymap = NULL;
struct Library			*KeymapBase = NULL;

struct Locale			*_locale = NULL;
ULONG				*codeset_page = NULL;

struct Library 			* RetroModeBase = NULL;
struct RetroModeIFace 	*IRetroMode = NULL;

struct WorkbenchIFace	*IWorkbench = NULL;
struct Library			*WorkbenchBase = NULL;

struct IconIFace		*IIcon = NULL;
struct Library			*IconBase = NULL;

struct Library			*IntuitionBase = NULL;
struct IntuitionIFace		*IIntuition = NULL;

struct Library			*GraphicsBase = NULL;
struct GraphicsIFace		*IGraphics = NULL;

struct Library			*LayersBase = NULL;
struct LayersIFace		*ILayers = NULL;

#define m(name) __mac__ ## name

// we work with arrays, just makes it easy to cleanup, (looks like MacOS program suck, at this.)

struct _vector_array * m(fd) = NULL;
struct _vector_array * m(windows) = NULL;


void mac_fd_destructor (void *item)
{
	FClose( (BPTR) item );
}

void cleanup_fd()
{
	if (IDOS)
	{
		while (m(fd) -> used)
		{
			_vector_array_erase(m(fd), m(fd) -> array, mac_fd_destructor );
		}
	}
}

void macWindow_destructor(void *item)
{
	WindowPtr macWindow = (WindowPtr) item;

	if (macWindow->AmigaWindow)
	{
		CloseWindow(macWindow->AmigaWindow);
	}
	free(macWindow);
}

void cleanup_windows()
{
	if (IIntuition == NULL)  return;

	while (m(windows)->used)
	{
		_vector_array_erase(m(windows), m(windows) -> array, macWindow_destructor );
	}
}


BOOL open_lib( const char *name, int ver , const char *iname, int iver, struct Library **base, struct Interface **interface)
{
	*interface = NULL;
	*base = OpenLibrary( name , ver);

	if (*base)
	{
		 *interface = GetInterface( *base,  iname , iver, TAG_END );
		if (!*interface) printf("Unable to getInterface %s for %s %ld!\n",iname,name,ver);
	}
	else
	{
	   	printf("Unable to open the %s %ld!\n",name,ver);
	}
	return (*interface) ? TRUE : FALSE;
}

static bool init()
{
	if ( ! open_lib( "asl.library", 0L , "main", 1, &AslBase, (struct Interface **) &IAsl  ) ) return FALSE;
	if ( ! open_lib( "locale.library", 53 , "main", 1, &LocaleBase, (struct Interface **) &ILocale  ) ) return FALSE;
	if ( ! open_lib( "keymap.library", 53, "main", 1, &KeymapBase, (struct Interface **) &IKeymap) ) return FALSE;
	if ( ! open_lib( "diskfont.library", 50L, "main", 1, &DiskfontBase, (struct Interface **) &IDiskfont  ) ) return FALSE;
	if ( ! open_lib( "gadtools.library", 53L , "main", 1, &GadToolsBase, (struct Interface **) &IGadTools  ) ) return FALSE;
	if ( ! open_lib( "intuition.library", 51L , "main", 1, &IntuitionBase, (struct Interface **) &IIntuition  ) ) return FALSE;
	if ( ! open_lib( "graphics.library", 54L , "main", 1, &GraphicsBase, (struct Interface **) &IGraphics  ) ) return FALSE;
	if ( ! open_lib( "layers.library", 54L , "main", 1, &LayersBase, (struct Interface **) &ILayers  ) ) return FALSE;
	if ( ! open_lib( "workbench.library", 53 , "main", 1, &WorkbenchBase, (struct Interface **) &IWorkbench ) ) return FALSE;
	if ( ! open_lib( "icon.library", 53, "main", 1, &IconBase, (struct Interface **) &IIcon) ) return FALSE;

	return TRUE;
}

static void cleanup()
{

	if (IDebug) DropInterface((struct Interface*) IDebug); IDebug = 0;

	if (IIcon) DropInterface((struct Interface*) IIcon); IIcon = 0;
	if (IconBase) CloseLibrary(IconBase); IconBase = 0;

	if (IWorkbench) DropInterface((struct Interface*) IWorkbench); IWorkbench = 0;
	if (WorkbenchBase) CloseLibrary(WorkbenchBase); WorkbenchBase = 0;

	if (IAsl) DropInterface((struct Interface*) IAsl); IAsl = 0;
	if (AslBase) CloseLibrary(AslBase); AslBase = 0;

	if (ILocale) DropInterface((struct Interface*) ILocale); ILocale = 0;
	if (LocaleBase) CloseLibrary(LocaleBase); LocaleBase = 0;

	if (IKeymap) DropInterface((struct Interface*) IKeymap); IKeymap = 0;
	if (KeymapBase) CloseLibrary(KeymapBase); KeymapBase = 0;

	if (DiskfontBase) CloseLibrary(DiskfontBase); DiskfontBase = 0;
	if (IDiskfont) DropInterface((struct Interface*) IDiskfont); IDiskfont = 0;

	if (IntuitionBase) CloseLibrary(IntuitionBase); IntuitionBase = 0;
	if (IIntuition) DropInterface((struct Interface*) IIntuition); IIntuition = 0;

	if (LayersBase) CloseLibrary(LayersBase); LayersBase = 0;
	if (ILayers) DropInterface((struct Interface*) ILayers); ILayers = 0;

	if (GraphicsBase) CloseLibrary(GraphicsBase); GraphicsBase = 0;
	if (IGraphics) DropInterface((struct Interface*) IGraphics); IGraphics = 0;
}

bool OpenMacEMU()
{
	if (init() == false ) 
	{
		cleanup();
		return false;
	}

	m(windows) = _vector_array_new();
	if (m(windows) == NULL)
	{
		CloseMacEMU();
		return false;
	}

	m(fd) = _vector_array_new();
	if (m(fd) == NULL)
	{
		CloseMacEMU();
		return false;
	}

	return true;
}

void CloseMacEMU()
{
	// erase items inside array..

	cleanup_fd();
	cleanup_windows();

	if (m(windows))	// remove the array
	{
		_vector_array_delete(m(windows));
		m(windows) = NULL;
	}

	if (m(fd))	// remove the array
	{
		_vector_array_delete(m(fd));
		m(fd) = NULL;
	}

	cleanup();
}

void AdjustMenus(){}
void BeginUpdate(){}
void DragWindow(){}
void EndUpdate(){}
void EraseRect( Rect *r ){}

struct Window *amigaWindow = NULL;

int FindWindow(Point where, void *ptr)
{
}

void FlushEvents( uint32_t mask, uint32_t xxxx);
void *FrontWindow(){}

void HandleMenu( void *ptr){}
void HideWindow(){}
void HiliteMenu(){}
void InitCursor(){}
void InitDialogs(){}
void InitFonts(){}
void InitGraf(){}
void InitMenus(){}
void InitWindows(){}

void InsetRect( Rect *r, int w,int h )
{
	r->left+=w;
	r->right-=w;
	r->top+=h;
	r->bottom-=h;
}

void InvalRect(){}
void MaxApplZone(){}
void *MenuKey(char key) 
{
	return NULL;
}

void MenuSelect(Point where)
{
}

#define IDCMP_COMMON IDCMP_MOUSEBUTTONS | IDCMP_INACTIVEWINDOW | IDCMP_ACTIVEWINDOW  | \
	IDCMP_CHANGEWINDOW | IDCMP_MOUSEMOVE | IDCMP_REFRESHWINDOW | IDCMP_RAWKEY | \
	IDCMP_EXTENDEDMOUSE | IDCMP_CLOSEWINDOW | IDCMP_NEWSIZE | IDCMP_INTUITICKS | IDCMP_MENUPICK | IDCMP_GADGETUP

WindowPtr NewWindow( int value1, Rect *bounds,const char *title, bool opt1, uint32_t opt2, WindowPtr cloneFrom, bool opt3, int value2)
{
	int window_width, window_height;
	WindowPtr macWindow;

	macWindow = (WindowPtr) malloc(sizeof(struct __mac_window__));

	if (macWindow)
	{
		window_width = bounds->right - bounds->left;
		window_height = bounds->bottom - bounds->top;

		macWindow -> AmigaWindow  = OpenWindowTags( NULL,
//				WA_PubScreen,       (ULONG) fullscreen_screen,
				WA_Left,			bounds->left,
				WA_Top,			bounds->top,
				WA_InnerWidth,		window_width,
				WA_InnerHeight,	window_height,

				WA_MinWidth, 	30, 
				WA_MinHeight,  30,
				WA_MaxWidth,      ~0,
				WA_MaxHeight,       ~0,  

				WA_SimpleRefresh,	TRUE,
				WA_CloseGadget,	FALSE,
				WA_DepthGadget,	FALSE,
				WA_DragBar,		FALSE ,
				WA_Borderless,	TRUE ,
				WA_SizeGadget,	FALSE ,
				WA_SizeBBottom,	FALSE ,
				WA_NewLookMenus,	TRUE,
				WA_Title,			NULL,
				WA_Activate,		TRUE,
				WA_Flags,			WFLG_RMBTRAP| WFLG_REPORTMOUSE,
				WA_IDCMP,		IDCMP_COMMON,
			TAG_DONE);
		
		if (macWindow -> AmigaWindow == NULL)
		{
			free(macWindow);
			macWindow = NULL;
		}
	}

	if (_vector_array_push_back( m(windows), macWindow ) == false)
	{
		macWindow_destructor(macWindow);
		macWindow = NULL;
	}

	return macWindow;
}

void SelectWindow(){}

void empty_que(struct MsgPort *win_port)
{
	struct IntuiMessage *msg;

	while (msg = (struct IntuiMessage *) GetMsg(win_port))
	{
		ReplyMsg((struct Message *) msg);
	}
}

void SetPort( WindowPtr ptr)
{
	amigaWindow = ptr -> AmigaWindow;
}

bool GetNextEvent( int opt, EventRecord *er)
{
	struct IntuiMessage *msg;
	if ((amigaWindow == NULL)||(er == NULL)) return false;

	msg = (struct IntuiMessage *) GetMsg( amigaWindow -> UserPort );

	if (msg)
	{
		ULONG cl = msg->Class;
		bool up = msg -> Code & IECODE_UP_PREFIX;

		switch (cl) 
		{
			case IDCMP_ACTIVEWINDOW:
				er -> what = activateEvt;
				break;
			case IDCMP_MOUSEMOVE:
				er -> what = updateEvt;
				break;
			case IDCMP_MOUSEBUTTONS:
				er -> what = up ? mouseUp : mouseDown;
				break;
			case IDCMP_RAWKEY:
				er -> what = up ? keyUp : keyDown;
				break;
			case IDCMP_EXTENDEDMOUSE:
				break;

		}

		ReplyMsg((struct Message *) msg);
		return true;
	}

	return false;
}


void SetUpMenus()
{
}

void SystemClick()
{
}

void SystemTask()
{
}

void TEInit()
{
}

bool TrackGoAway( void *win ,Point where )
{
}

short _mac_FSOpen(const char *name, int refNum, short *fd)
{
	BPTR _fd;
	void **i;

	_fd = FOpen( name, MODE_READWRITE, 0);

	if (_fd)
	{
		i =  _vector_array_push_back(m(fd), (void *)  _fd );
		if (i)
		{
			*fd = i - m(fd) -> array +1;	// fd can't be 0.
		}
	}

	return 0;	// failed.
}


short _mac_FSRead( short fd, long int *size, void *ptr)
{
	if (m(fd) -> array[fd])
	{
		return Read( (BPTR) m(fd)->array[fd-1], ptr, *size );
	}

	return 0;
}

void _mac_FSClose(short fd)
{
	if (fd)
	{
		_vector_array_erase(m(fd),  m(fd) -> array + fd -1, mac_fd_destructor );
	}
}

void SFGetFile( Point pos, const char *name, int a, int b, int c, int d, SFReply *out )
{
	// This is like macOS ASL requester,

	out -> fName = strdup("ram:test.txt");
	out -> good = true;
}

void HLock(Handle ptr)
{
	// do nothing, this has to do with virtual memory in macos
}

void HUnlock(Handle ptr)
{
	// do nothing, this has to do with virtual memory in macos
}

void FillOval( Rect *r, uint32_t color)
{
	int cx,cy,hr,vr;
	
	hr = (r->bottom - r->top) / 2;
	vr = (r->right - r->left) / 2;

	cx = r->left + hr;
	cy = r->top + vr;

//	SetRastColor( amigaWindow -> RPort, color );

	SetRPAttrs( amigaWindow -> RPort,
		RPTAG_APenColor, color, 
		TAG_END	);

	DrawEllipse( amigaWindow -> RPort, cx,cy,hr,vr);
	Flood(amigaWindow -> RPort, 1, cx, cy);
}

void FrameOval(Rect *r)
{
	int cx,cy,hr,vr;
	
	hr = (r -> bottom - r ->top) / 2;
	vr = (r -> right - r -> left) / 2;

	cx = r -> left + hr;
	cy = r -> top + vr;

	DrawEllipse( amigaWindow -> RPort, cx,cy,hr,vr);
}

void FrameRect(Rect*r)
{
       RectFill(amigaWindow -> RPort, r->left, r->top,
                     r->right, r->bottom);
}

