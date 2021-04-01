
#include "libMacEmu.h"
#include "vector_array.h"
#include "pathTranslate.h"
#include <proto/gadtools.h>

#undef HideWindow
#undef ShowWindow
#undef SetPort

PixMap screenBits;

GrafPort this_GrafPort;	// this maybe wrong... but it will be changed, its place holder.

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
struct GadToolsIFace	*IGadTools = NULL;

struct KeymapIFace		*IKeymap = NULL;
struct Library			*KeymapBase = NULL;

struct Locale			*_locale = NULL;
ULONG				*codeset_page = NULL;

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

// I expected to run into name conflict, macros is like namespace.

#define n(name) __native__ ## name
#define l(name) __libMacEmu__ ## name
#define m(name) __mac__ ## name

// we work with arrays, just makes it easy to cleanup, (looks like MacOS program suck, at this.)

struct _vector_array * m(fd) = NULL;
struct _vector_array * m(windows) = NULL;
struct _vector_array * m(mac_event_queue) = NULL;

extern struct NewMenu *n(menu) ;
extern int m(menus_items_count) ;

void mac_fd_destructor (void *item)
{
	FClose( (BPTR) item );
}

void cleanup_fd()
{
	if (IDOS)
	{
		_vector_array_clear( m(fd) );
	}
}

void macWindow_destructor(void *item)
{
	WindowPtr macWindow = (WindowPtr) item;
	GrafPort *port = (GrafPort *) item;

	n(detach_menu_from_window)((void *) macWindow );

	if (port->AmigaWindowContext.win)
	{
		CloseWindow(port->AmigaWindowContext.win);
	}

	free(macWindow);
}

void cleanup_windows()
{
	if (IIntuition == NULL)  return;

	_vector_array_clear(m(windows));
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

	if (GadToolsBase) CloseLibrary(GadToolsBase); GadToolsBase = 0;
	if (IGadTools) DropInterface((struct Interface*) IGadTools); IGadTools = 0;

	if (IntuitionBase) CloseLibrary(IntuitionBase); IntuitionBase = 0;
	if (IIntuition) DropInterface((struct Interface*) IIntuition); IIntuition = 0;

	if (LayersBase) CloseLibrary(LayersBase); LayersBase = 0;
	if (ILayers) DropInterface((struct Interface*) ILayers); ILayers = 0;

	if (GraphicsBase) CloseLibrary(GraphicsBase); GraphicsBase = 0;
	if (IGraphics) DropInterface((struct Interface*) IGraphics); IGraphics = 0;
}

void mac_event_queue_destructor( void *item )
{
	item = NULL;	// we use circle buffer... mem allocations too slow...
}

bool OpenMacEMU()
{
	if (init() == false ) 
	{
		cleanup();
		return false;
	}

	m(windows) = _vector_array_new( macWindow_destructor );
	if (m(windows) == NULL)
	{
		CloseMacEMU();
		return false;
	}

	m(fd) = _vector_array_new( mac_fd_destructor );
	if (m(fd) == NULL)
	{
		CloseMacEMU();
		return false;
	}

	m(mac_event_queue) = _vector_array_new( mac_event_queue_destructor );
	if (m(mac_event_queue) == NULL)
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


	if (m(mac_event_queue))	// remove the array
	{
		_vector_array_delete(m(mac_event_queue));
		m(mac_event_queue) = NULL;
	}

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

void BeginUpdate(){}

void DragWindow(void *a,void *b,void *c)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void EndUpdate(){}
void EraseRect( Rect *r ){}

GrafPort *m(GrafPort) = NULL;

uint16_t FindWindow(m(where) where, WindowPtr *win)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	*win = where.window;

	return where.windowCode;
}

void FlushEvents( uint32_t mask, uint32_t xxxx);

WindowPeek FrontWindow()
{
	return (WindowPeek) m(GrafPort);
}

void HideWindow( WindowPtr win ){}
void ShowWindow( WindowPtr win ) {}

void InitCursor()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void InitDialogs()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void InitFonts()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void InitGraf()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void InitWindows()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void InsetRect( Rect *r, short w,short h )
{
	r->left+=w;
	r->right-=w;
	r->top+=h;
	r->bottom-=h;
}

void SetRect(Rect *r,short x0,short y0,short x1,short y1)
{
	r->left=x0;
	r->right=x1;
	r->top=y0;
	r->bottom=y1;
}

void InvalRect(){}
void MaxApplZone(){}

#define IDCMP_COMMON IDCMP_MOUSEBUTTONS | IDCMP_INACTIVEWINDOW | IDCMP_ACTIVEWINDOW  | \
	IDCMP_CHANGEWINDOW | IDCMP_MOUSEMOVE | IDCMP_REFRESHWINDOW | IDCMP_RAWKEY | \
	IDCMP_EXTENDEDMOUSE | IDCMP_CLOSEWINDOW | IDCMP_NEWSIZE | IDCMP_INTUITICKS | IDCMP_MENUPICK | IDCMP_GADGETUP


WindowPtr NewWindow( WindowPeek wStorage, Rect *bounds,const char *title, bool visible, uint32_t procID, WindowPtr behind, bool goAwayFlag, 	long refCon)
{
	int window_width, window_height;
	WindowPtr macWindow;

	macWindow = (WindowPtr) malloc(sizeof(struct WindowRecord));

	if (macWindow)
	{
		GrafPort *port = (GrafPort *)  macWindow;
		window_width = bounds->right - bounds->left;
		window_height = bounds->bottom - bounds->top;
	
		port -> AmigaWindowContext.vi = 0;
		port -> AmigaWindowContext.menu = NULL;
		port -> AmigaWindowContext.win  = OpenWindowTags( NULL,
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
				WA_CloseGadget,	goAwayFlag ? TRUE : FALSE,
				WA_DepthGadget,	FALSE,
				WA_DragBar,		FALSE ,
				WA_Borderless,	TRUE ,
				WA_SizeGadget,	FALSE ,
				WA_SizeBBottom,	FALSE ,
				WA_NewLookMenus,	TRUE,
				WA_Title,			title,
				WA_Activate,		TRUE,
				WA_Flags,			WFLG_REPORTMOUSE,
				WA_IDCMP,		IDCMP_COMMON,
			TAG_DONE);
		
		if (port -> AmigaWindowContext.win == NULL)
		{
			free(macWindow);
			macWindow = NULL;
		}
	}

	if (_vector_array_push_back( m(windows), macWindow ))
	{
		if (n(menu))
		{
//			dump_amiga_menu( n(menu) );
			n(attach_menu_to_window)( (void *) macWindow);
		}
	}
	else
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


void 	GetPort( GrafPort **port )
{
	*port = m(GrafPort);
}

void SetPort( GrafPort *ptr)
{
	m(GrafPort) = ptr ;
}

EventRecord n(io)[1000];
int n(io_pos) = 0;

void n(_get_events_and_convert)(n(AWC) *awc)
{
	struct IntuiMessage *msg;
	struct MenuItem *menuitem;
	EventRecord *er;

	while (msg = (struct IntuiMessage *) GetMsg( awc -> win -> UserPort ))
	{
		ULONG cl = msg->Class;
		bool up = msg -> Code & IECODE_UP_PREFIX;

		er = &n(io)[n(io_pos) % 1000];


		if (er)
		{
			er -> what = none_event;
			er -> where.window = (WindowPtr) m(GrafPort);

			switch (cl) 
			{
				case IDCMP_CLOSEWINDOW:

					er -> what = mouseDown;
					er -> where.windowCode = inGoAway;
					break;

				case IDCMP_ACTIVEWINDOW:
					er -> what = activateEvt;
					break;


				case IDCMP_MOUSEMOVE:
//					er -> what = updateEvt;
					break;

				case IDCMP_MOUSEBUTTONS:

					er -> what = up ? mouseUp : mouseDown;
					er -> where.windowCode = inContent;
					er -> where.point.x = msg -> MouseX;
					er -> where.point.y = msg -> MouseY;
					break;

				case IDCMP_RAWKEY:

					er -> what = up ? keyUp : keyDown;
					break;

				case IDCMP_EXTENDEDMOUSE:
					break;

				case IDCMP_INTUITICKS:
					er-> what = updateEvt;
					break;

				case IDCMP_MENUPICK:

					{
						int menuNumber = msg -> Code;
						int menuNum,itemNum;

						if (awc -> menu)
						{
							while (menuNumber != MENUNULL)
							{
								menuNum = MENUNUM(menuNumber);
								itemNum = ITEMNUM(menuNumber);

								menuitem = ItemAddress( awc -> menu , msg -> Code);

								printf("menu item: %08x --- %d ,%d \n",menuitem,menuNum,itemNum);

								er -> what = mouseDown;
								er -> where.windowCode = inMenuBar;
								er -> where.code = (uint32_t) GTMENUITEM_USERDATA(menuitem);

								_vector_array_push_back( m(mac_event_queue), (void  *) er) ;
								n(io_pos) ++;

								menuNumber = menuitem -> NextSelect;
							}

							er -> what != none_event	;		// no more menu events.
						}
					}
					break;
			}

			if (er -> what != none_event)	// not a valid event..
			{
				_vector_array_push_back( m(mac_event_queue), (void  *) er) ;
				n(io_pos) ++;
			}
		}

		ReplyMsg((struct Message *) msg);
	}
}

bool n(refresh_menu) = false;
extern void n(create_menu)();

bool GetNextEvent( int opt, EventRecord *er)
{
	struct Window *win;
	if ((m(GrafPort) == NULL)||(er == NULL)) return false;
		
	n(_get_events_and_convert)( &m(GrafPort) -> AmigaWindowContext );

	if (m(mac_event_queue) -> used)
	{
		*er = *((EventRecord *) m(mac_event_queue) -> array[0]);	// make copy of first,
		_vector_array_erase(m(mac_event_queue), m(mac_event_queue) -> array );	// erase the first.
		return true;
	}
	else 
	{
		if (n(refresh_menu))
		{
			n(create_menu)();
			n(refresh_menu) = false;
		}

		Delay(1);
	}

	return false;
}


void SystemClick( void *x )
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void SystemTask()
{
}

void TEInit()
{
}

bool TrackGoAway( WindowPtr win ,m(where) where )
{
	return (win == where.window);
}

short _mac_FSOpen(const char *mname, int refNum, short *fd)
{
	BPTR _fd;
	void **i;
	char *aname = _mac_to_amiga_path( mname );

	*fd = 0;

	if (aname == NULL) 	return 0;	// failed.

	_fd = FOpen( aname, MODE_READWRITE, 0);

	if (_fd)
	{
		i =  _vector_array_push_back(m(fd), (void *)  _fd );
		if (i)
		{
			*fd = i - m(fd) -> array +1;	// fd can't be 0.

			printf("*fd %d\n",*fd);
		}
	}

	free(aname);

	return *fd ? true : false;
}


short _mac_FSRead( short fd, long int *size, void *ptr)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	if (fd < 1) return  0;

	fd--;

	if (m(fd) -> array[fd])
		return IDOS -> Read( (BPTR) m(fd)->array[fd], ptr, *size );


	return 0;
}

void _mac_FSClose(short fd)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	if (fd < 1) return;
	
	fd--;
	_vector_array_erase(m(fd),  m(fd) -> array + fd  );
}

extern char *asl( const char *pattern );

void SFGetFile( Point pos, const char *name, int a, int b, int c, int d, SFReply *out )
{
	char *aname;
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	// This is like macOS ASL requester,

	aname = asl( "" );

	if (aname == NULL) 
	{
		out -> fName = NULL;
		out -> good = false;
		return;
	}

	out -> fName = _amiga_to_mac_path( aname );
	out -> good = out -> fName ? true : false;

	if (aname) free(aname);
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
	int ar,br,mr;
	struct RastPort *rp;
	struct Window *win;
	if (m(GrafPort) == NULL) return ;
	
	hr = (r->bottom - r->top) / 2;
	vr = (r->right - r->left) / 2;

	win  = m(GrafPort) -> AmigaWindowContext.win;
	rp =  win -> RPort;

	cx = r->left + hr + win -> BorderLeft;
	cy = r->top + vr + win -> BorderTop;



	SetRPAttrs( rp,
		RPTAG_APenColor, color, 
		TAG_END	);

	mr = hr > vr ? hr : vr;
	for (ar=0;ar<=mr;ar++)
	{
		br = sqrt( mr*mr - ar*ar);

		IGraphics -> Move( rp, cx+ ar,cy - br );
		IGraphics -> Draw( rp, cx +ar,cy + br );

		IGraphics -> Move( rp, cx- ar,cy - br );
		IGraphics -> Draw( rp, cx -ar,cy + br );

	}
}

void FrameOval(Rect *r)
{
	int cx,cy,hr,vr;
	struct RastPort *rp;
	struct Window *win;
	
	hr = (r -> bottom - r ->top) / 2;
	vr = (r -> right - r -> left) / 2;

	cx = r -> left + hr;
	cy = r -> top + vr;

	win  = m(GrafPort) -> AmigaWindowContext.win;
	rp =  win -> RPort;

	DrawEllipse( rp, cx + win -> BorderLeft,cy + win -> BorderTop,hr,vr);
}

void FrameRect(Rect*r)
{
	struct RastPort *rp = m(GrafPort) -> AmigaWindowContext.win -> RPort;
	RectFill( rp, r->left, r->top, r->right, r->bottom);
}

void GetFrame( LongRect *r )		// not sure if this correct, some examples suggest its window draw aria.
{
	struct Window *win = m(GrafPort) -> AmigaWindowContext.win;

	r -> left = win -> BorderLeft;
	r -> top = win -> BorderTop;
	r -> right = win -> Width - r -> left - win -> BorderRight;
	r -> bottom = win -> Height - r -> top - win -> BorderBottom;

}

void DrawString(const char *text)
{
	struct RastPort *rp = m(GrafPort) -> AmigaWindowContext.win -> RPort;
	Text( rp, text, strlen(text) );
}

void OpenDeskAcc(GrafPtr port)
{

}

void CloseDeskAcc( short windowKind )
{
}

void ExitToShell()
{
	CloseMacEMU();
	exit(0);
}

bool SystemEdit( int item )
{
}

void SysBeep(int nr)
{
}

void 	Pt2Rect(Point p1,Point p2,Rect *r)
{
	r -> left = p1.h < p2.h ? p1.h : p2.h;
	r -> top = p1.v < p2.v ? p1.v : p2.v;
	r -> right = p1.h > p2.h ? p1.h : p2.h;
	r -> bottom = p1.v > p2.v ? p1.v : p2.v;
}

void 	Prepare()
{
	// should do nothing on Amiga, this has to do with cooperative multitasking.
}

