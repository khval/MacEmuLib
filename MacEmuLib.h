
#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>

#undef EraseRect
#undef HideWindow
#undef EraseRect
#undef GetNextEvent
#undef Draw

#define Point _mac_Point_
#define FSOpen _mac_FSOpen
#define FSRead _mac_FSRead
#define FSClose _mac_FSClose
#define ColorSpec _mac_ColorSpec
#define BitMap _mac_BitMap

#ifdef AddResource
// found in "proto/exec.h", but is not the same in macos.
#undef AddResource
#endif

#undef InitWindows

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

typedef char *GrafPtr;

typedef struct
{
	unsigned short red;
	unsigned short green;
	unsigned short blue;
} RGBColor;

typedef struct
{
	int value;
	RGBColor rgb;
} ColorSpec;

typedef struct {
	int x;
	int y;
	int h;
	int v;
} Point;

typedef struct 
{
	int what;
	Point where;
	int when;
	int message;
	int modifiers;
} EventRecord;

typedef char ** Handle;			//  its possible this used as mutex lock.

#define NewHandle(extraSize) (malloc( sizeof(Handle) + extraSize ))

typedef const char ConstStr255Param[256];
typedef char Str255[256];
typedef char Str31[31];

typedef uint32_t OSErr;
typedef bool Boolean;


typedef struct {
	int left;
	int top;
	int right;
	int bottom;
} Rect;

typedef struct {

	char *baseAddr;
	uint32_t pixelSize;
	uint32_t rowBytes;

	struct {
		int *ctTable;
	} **pmTable;

	Rect bounds;

} PixMap;

extern PixMap screenBits;

typedef PixMap *PixMapPtr;
typedef PixMapPtr *PixMapHandle;

typedef struct {
	int *ctTable;
} ** CTabHandle;

typedef struct __mac_window__{
	void *portRect;
	bool hilited;

	struct Window *AmigaWindow;
} *WindowPtr;

#define WindowPeek WindowPtr
// hilited

typedef struct _HParamBlockRec1_ {
	struct _HParamBlockRec2_ {
		uint32_t ioCompletion;
	} ioParam; 
	struct _HParamBlockRec3_ {
		uint32_t ioFDirIndex;
		uint32_t ioVRefNum;
		uint32_t ioDirID;
		const char *ioNamePtr;
	} fileParam; 
} HParamBlockRec;

typedef void * CInfoPBPtr;

typedef int BitMap;
typedef int CGrafPtr;
typedef int GrafPort;
typedef struct
{
	int portPixMap;
} CGrafPort;

typedef struct
{
	char *name;
	int vRefNum;
	int parID;
} FSSpec;

typedef void * MenuHandle;
typedef void * RgnHandle;
typedef void * CursHandle;

typedef struct {
	PixMapHandle gdPMap;
} GD;

typedef GD *GDPtr;
typedef GDPtr *GDHandle;

extern WindowPtr GetNewCWindow( int a, long, WindowPtr );
extern GDHandle GetMainDevice();

typedef struct Process * TMTask;		// guess, we need a Amiga process here.

#define noErr 0

#define nil 0

enum
{
	fsRdWrPerm = 1
};

enum	// Gestalt
{
	gestaltQuickdrawFeatures = 1,
	gestaltHasColor,
	gestaltQuickTime,
	gestaltSoundAttr,
	gestaltMultiChannels,
	gestaltSysArchitecture,
	gestaltPowerPC
};

typedef struct {
void *thePort;
} qd;


#define GetCursor(watchCursor) 0;

enum
{
	keyDownMask = 1,
	autoKeyMask = 2,
	mDownMask = 4,
	mUpMask = 8,
	charCodeMask = 32
};

enum	// event what
{
	mouseUp = 1,
	mouseDown,
	keyUp,
	keyDown,
	autoKey,
	updateEvt,
	activateEvt
};

enum	// event where in window.
{
	inSysWindow = 1,
	inMenuBar,
	inDrag,
	inContent,
	inGoAway
};

enum	// event modifiers
{
	optionKey =1,
	cmdKey = 2,
};

enum	// colors
{
	black = 0x000000,
	gray =0xFFAAAAAA,
	white = 0xFFFFFFFF
};

#define everyEvent (~0)

typedef int ResType;
typedef void *Ptr;
typedef int wide;

typedef void *Movie;

typedef struct
{
	int sfGood;
	int sfReplacing;
	FSSpec sfFile;
} StandardFileReply;

typedef struct 
{
	Rect picFrame;
} Pic;

typedef Pic *PicPtr;
typedef PicPtr *PicHandle;

typedef struct 
{
	int ioWDVRefNum;
	int ioWDDirID;
} WDPBRec;

extern void DebugStr(const char *txt);
extern uint32_t MemError();

#define BlockMove(src,dest,size) memcpy(dest,src,size)
#define BlockMoveData(src,dest,size) memcpy(dest,src,size)

//	"void far *" to "void *"
#define far

typedef signed char SignedByte;
typedef uint32_t UInt32;

// typedef ulong Ref; // found in /Libraries/RES/Source/res.h

typedef int ComponentInstance;

typedef struct 
{
	int quackQuackQuack;
} ImageDescription;

typedef struct 
{
	int quackQuackQuack;
} ImageSequence;

typedef struct 
{
	int good;
	int vRefNum;
	char *vName;
	char *fName;
} SFReply;

typedef struct
{
	int top ;
	int left ;
	const char *title ;
	int nrows ;
	int ncols ;
	int pause_atexit ;
} console_options_type;

extern console_options_type console_options;

enum
{
	scUserCancelled = 1
};

#define noGrowDocProc 0

#ifdef __cplusplus
extern "C" {
#endif

extern void Draw4x4( unsigned char *, int , int );
extern void Draw4x4Reset( unsigned char *pColorSet, unsigned char *pHuffTab );
extern void HuffExpandFlashTables( unsigned char *, int , unsigned long *, int  );

extern void HLock( Handle h );
extern void HUnlock( Handle h );
extern long KeyTranslate(void *ptr, int ,  UInt32 *);
extern Handle GetIndResource(uint16_t catgory, int count );
extern void GetKeys( UInt32 *array );

extern bool OSEventAvail( uint32_t mask, EventRecord *event );		// like GetMsg() for AmigaOS.
extern bool GetOSEvent( uint32_t mask, EventRecord *event );		// like GetMsg() for AmigaOS.
extern bool Button();	// See if the mouse button is down
extern void GetMouse( Point *point );
extern void LocalToGlobal( Point *point );
extern uint32_t TickCount();
extern void FlushEvents( uint32_t mask, uint32_t xxxx);

#define GlobalToLocal(x)		// not something AmigaOS has, changes owner of data.

typedef int TimerUPP;
// typedef int errtype;  	// found in Libraries/H/error.h

#define SetPtrSize(adr,size) _SetPtrSize( &(adr),size )
// (Ptr)_tt->lines[line_num],new_targ);

extern void mput( char a, int, int );
extern int mono_setxy(int xpos,int ypos);
extern void mprint( const char *str );

extern bool OpenMacEMU();
extern void CloseMacEMU();

void AdjustMenus();
void BeginUpdate();
void DragWindow();
void EndUpdate();
void EraseRect(Rect *r);
void FillOval( Rect *bounds, uint32_t color );
int FindWindow(Point where, void *ptr);
void FlushEvents( uint32_t mask, uint32_t xxxx);
void *FrontWindow();
bool GetNextEvent( int opt, EventRecord *er);
void HandleMenu( void *);
void HideWindow();
void HiliteMenu();
void InitCursor();
void InitDialogs();
void InitFonts();
void InitGraf();
void InitMenus();
void InitWindows();
void InsetRect( Rect *r, int w,int h );
void InvalRect();
void MaxApplZone();
void *MenuKey(char key);
void MenuSelect(Point where);
WindowPtr NewWindow( int, Rect *bounds,const char *title, bool , uint32_t opt1, WindowPtr cloneFrom, bool opt2, int value);
void SelectWindow();
void SetPort( WindowPtr ptr);
void SetUpMenus();
void SystemClick();
void SystemTask();
void TEInit();
bool TrackGoAway( void *win ,Point where);
short _mac_FSOpen( const char *name, int refNum, short *fRef );
short _mac_FSRead( short fd, long *size, void *ptr);
void _mac_FSClose( short fd );
void SFGetFile( Point p,const char *,int,int,int,int, SFReply *tr);
void FrameRect(Rect *r);
void FrameOval(Rect *r);

#ifdef __cplusplus
}
#endif
