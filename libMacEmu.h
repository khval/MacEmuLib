
#ifndef libMacEmu_h
#define libMacEmu_h

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>

#undef EraseRect
#undef HideWindow
#undef ShowWindow
#undef EraseRect
#undef GetNextEvent
#undef Draw
#undef Move
#undef GetCurrentDir
#undef Write
#undef Read
#undef Open
#undef Close

#define Point _mac_Point_
#define FSOpen _mac_FSOpen
#define FSRead _mac_FSRead
#define FSClose _mac_FSClose
#define ColorSpec _mac_ColorSpec
#define BitMap _mac_BitMap
#define RgnHandle _mac_RgnHandle
#define Style _mac_Style

#define TRY try
#define CATCH catch( int )

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

#define n(name) __native__ ## name
#define l(name) __libMacEmu__ ## name
#define m(name) __mac__ ## name

extern bool n(refresh_menu) ;

typedef int OSType;
typedef int ScriptCode;

enum
{
	srcCopy,
	srcOr,
	srcXor,
	srcBic,
	notSrcCopy,
	notSrcOr,
	notSrcXor,
	notSrcBic,
	patCopy,
	parOr,
	patXOr,
	patBic,
	notPatCopy,
	notPatOr,
	notPatXor,
	notPatBic
};

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
	APTR		vi;
	struct Window 	*win;
	struct Menu	*menu;
} n(AWC);

typedef int SysEnvRec;

typedef char ** Handle;			//  its possible this used as mutex lock.

#define NewHandle(extraSize) (malloc( sizeof(Handle) + extraSize ))

typedef const char *ConstStr255Param;
typedef char Str255[256];
typedef char Str31[32];
typedef char Str63[64];

typedef uint32_t OSErr;
typedef bool Boolean;

typedef struct {
	short left;
	short top;
	short right;
	short bottom;
} Rect;

typedef struct {
	int left;
	int top;
	int right;
	int bottom;
} LongRect;

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

typedef int32_t Pattern;
typedef int64_t LongInt;




typedef int *CGrafPtr;
typedef int *QDHandle;
typedef int *QDProcsPtr;

typedef void * RgnHandle;

typedef struct // used for fonts.
{
	int _dummy_;
} Style;

typedef double Fixed;

struct GrafPort
{
	short device;
	BitMap portBits;
	Rect portRect;
	RgnHandle visRgn;
	RgnHandle clipRgn;
	Pattern bkPat;
	Pattern fillPat;
	Point pnLoc;
	Point pnSize;
	short pnMode;
	Pattern pnPat;
	short pnVis;
	short txFont;
	Style txFace;
	char filler;
	short txMode;
	short txSize;
	Fixed spExtra;
	long fgColor;
	long bkColor;
	short colrBit;
	short patStretch;
	Handle picSave;
	Handle rgnSave;
	Handle polySave;
	QDProcsPtr grafProcs;

// we add Amiga stuff to the end.

	n(AWC) AmigaWindowContext;
};

typedef struct GrafPort GrafPort;
typedef GrafPort *GrafPtr;

typedef char *StringHandle;

typedef void *ControlHandle;

typedef struct 
{
	Rect picFrame;
} Pic;

typedef Pic *PicPtr;
typedef PicPtr *PicHandle;

struct WindowRecord
{
    GrafPort port;
    short windowKind;
    Boolean visible;
    Boolean hilited;
    Boolean goAwayFlag;
    Boolean spareFlag;
    RgnHandle strucRgn;
    RgnHandle contRgn;
    RgnHandle updateRgn;
    Handle windowDefProc;
    Handle dataHandle;
    StringHandle titleHandle;
    short titleWidth;
    ControlHandle controlList;
    struct WindowRecord *nextWindow;
    PicHandle windowPic;
    long refCon;
};

typedef struct WindowRecord WindowRecord;
typedef WindowRecord *WindowPeek;


typedef GrafPtr WindowPtr;

typedef struct 
{
	Point point;
	WindowPtr window;
	uint16_t windowCode;
	uint32_t code;
} m(where);

typedef struct 
{
	int what;
	m(where) where;
	int when;
	int message;
	int modifiers;
} EventRecord;

extern GrafPort this_GrafPort ;	// this maybe wrong... but it will be changed, its place holder.

typedef struct 
{
	int ascent;
	int descent;
	int widMax;
	int leading;
} FontInfo;

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

typedef FSSpec * FSSpecPtr;

typedef struct
{
	char *name;
	char *key;
	int flags;
}_tmp_mac_menu_item_;

typedef struct 		// only a placeholder.
{
	uint16_t id;
	char *description;
	_tmp_mac_menu_item_ *items;
	int items_count ;
	int items_allocated;
}__tmp_mac_menu__;


typedef __tmp_mac_menu__ *MenuHandle;


#define PtoCstr(a) a
#define CtoPstr(a) a


typedef void * CursPtr;
typedef CursPtr * CursHandle;

typedef struct {
	PixMapHandle gdPMap;
	Rect  gdRect;
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
	none_event,
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
	black = 0xFF000000,
	gray =  0xFFAAAAAA,
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
	int __dummy;
} PixPatHandle;

typedef struct
{
	int __dummy;
} PatHandle;

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

typedef struct 
{
	void *__dummy;
} ModalFilterUPP;

extern console_options_type console_options;

enum
{
	scUserCancelled = 1
};

typedef struct 
{
	void *__dummy;
} DialogPtr ;

typedef struct 
{
	void *__dummy;
} SndChannel ;

typedef SndChannel  SndChannelPtr ;

typedef struct 
{
	void *cmd;
	void *param1;
	void *param2;
} SndCommand ;


extern int errcode;


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
extern void GetKeys( UInt32 *array );

extern bool OSEventAvail( uint32_t mask, EventRecord *event );		// like GetMsg() for AmigaOS.
extern bool GetOSEvent( uint32_t mask, EventRecord *event );		// like GetMsg() for AmigaOS.
extern bool Button();	// See if the mouse button is down
extern void GetMouse( Point *point );
extern void LocalToGlobal( Point *point );
extern uint32_t TickCount();
extern void FlushEvents( uint32_t mask, uint32_t xxxx);

extern void LockPixels(char);
extern void UnlockPixels(char);
extern Pic **GetPicture(int);

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

void BeginUpdate();
void DragWindow(void *,void *,void *);
void EndUpdate();
void EraseRect(Rect *r);
void FillOval( Rect *bounds, uint32_t color );
uint16_t FindWindow( m(where) where, WindowPtr *win);

void FlushEvents( uint32_t mask, uint32_t xxxx);
WindowPeek FrontWindow();
bool GetNextEvent( int opt, EventRecord *er);

void ShowWindow( WindowPtr ptr );		// takes DialogPtr or WindowPtr as input
void HideWindow( WindowPtr ptr );		// takes DialogPtr or WindowPtr as input

#define ShowWindow(ptr) ShowWindow( (WindowPtr) ptr )
#define HideWindow(ptr) HideWindow( (WindowPtr) ptr )

void 	Pt2Rect(Point p1,Point p2,Rect *r);
void 	Prepare();

void HiliteMenu();
void InitCursor();
void InitDialogs();
void InitFonts();
void InitGraf();
void InitMenus();
void InitWindows();
void InsetRect( Rect *r, short w,short h );
void InvalRect();
void MaxApplZone();
WindowPtr NewWindow( WindowPeek wStorage, Rect *bounds,const char *title, bool visible, uint32_t procID, WindowPtr behind, bool goAwayFlag, 	long refCon);
void SelectWindow();
void GetPort( GrafPort **ptr );
void SetPort( GrafPort *ptr );
void SystemClick( void *x, void *y );
void SystemTask();
void TEInit();
bool TrackGoAway( WindowPtr win ,m(where) where);
short _mac_FSOpen( const char *name, int refNum, short *fRef );
short _mac_FSRead( short fd, long int *size, void *ptr);
void _mac_FSClose( short fd );
void SFGetFile( Point p,const char *,int,int,int,int, SFReply *tr);
void FrameRect(Rect *r);
void FrameOval(Rect *r);
void CloseDeskAcc( short windowKind );

short MenuKey(char key);
uint32_t MenuSelect(m(where) where);
MenuHandle NewMenu(short id, const char *description);
void AppendMenu(MenuHandle menu, const char *description);
void InsertMenu( MenuHandle menu, short num );
void DrawMenuBar();
void AddResMenu( MenuHandle menu, uint16_t ref);
void CheckItem(MenuHandle menu, int width, bool enabled);
void EnableItem(MenuHandle menu, short item);
void DisableItem(MenuHandle menu, short item);

void GetItem( MenuHandle menu, int Item, char *name);
void OpenDeskAcc(GrafPtr port);
void ExitToShell();
bool SystemEdit( int item );
void SysBeep(int nr);

void SetRect(Rect *r,short x0,short y0,short x1,short y1);
void RGBForeColor(RGBColor*rgb);
void ForeColor(int c);
void PaintRect(Rect *r);
void FillCRgn(void *gBackgroundRgn,PixPatHandle gMyPat);

void SetDialogItemText(void *, const char *txt);
void DisposeDialog();

void GetFrame( LongRect *r );		// get size of window?

void ConcatPStrings(Str255 str, char *cut);
void NumToString(int wCount,char *out);

typedef uint32_t Size;

#define blackColor 0
#define whiteColor  1

#define HiWord(x) ( (x) >> 16);
#define LoWord(x) ( (x) & 0xFFFF)

#ifdef __cplusplus

class LibMacEmu		// for overloaded function, ThinkC, PowerC most be doing some magic to have have classes whitout names.
{
	public:
 		static void ConcatPStrings(Str255 str, const char *merge);
	 	static void ConcatPStrings(Str255 str, int num);
};

#endif

#ifdef __cplusplus
}
#endif

#include "Resources.h"

#define SetPort(x) SetPort( (GrafPort*) x);

#define excExeedTELimit 1
#define fsRdPerm 1
#define fsWrPerm 2

#define DisposeHandle(x) delete x
#define Failure(a,b) throw(b)

#endif


