
#undef EraseRect
#undef HideWindow

#define EraseRect __mac__EraseRect
#define GetNextEvent __mac__GetNextEvent

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
void HLock();
void HUnlock();
void FrameRect(Rect *r);
void FrameOval(Rect *r);

