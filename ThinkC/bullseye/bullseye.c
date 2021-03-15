

#ifdef __amigaos4__
// Not real mac, we need some defines.
#include "MacEmuLib.h"
struct { int dummy; } thePort;
#endif

#include "bullMenus.h"
#include "bullWindow.h"

extern	WindowPtr	bullseyeWindow;
extern	Rect		dragRect;

void InitMacintosh(void);
void HandleMouseDown (EventRecord	*theEvent);

#ifdef __amigaos4__
bool HandleEvent(void);
#else
void HandleEvent(void);
#endif

void InitMacintosh(void)
{
	MaxApplZone();
	InitGraf(&thePort);
	InitFonts();
//	FlushEvents(everyEvent, 0);
	InitWindows();
	InitMenus();
	TEInit();
	InitDialogs(0L);
	InitCursor();
}

void HandleMouseDown (EventRecord	*theEvent)
{
	void	*theWindow;
	int			windowCode = FindWindow (theEvent->where, (void *) &theWindow);

	switch (windowCode)
	{
		case inSysWindow:
				SystemClick (theEvent, theWindow);
				break;

	    	  case inMenuBar:
				AdjustMenus();
//				HandleMenu(MenuSelect(theEvent->where));
				break;

	    	  case inDrag:
//				if (theWindow == bullseyeWindow)  DragWindow(bullseyeWindow, theEvent->where, &dragRect);
				break;

	  	  case inContent:
			  	if (theWindow == bullseyeWindow)
				{
					if (theWindow != FrontWindow())
						SelectWindow(bullseyeWindow);
					else
						InvalRect(&bullseyeWindow->portRect);
	  	  		}
				break;

		case inGoAway:
				if (theWindow == bullseyeWindow && TrackGoAway(bullseyeWindow, theEvent->where))
				HideWindow(bullseyeWindow);
				break;
      	}
}

#ifdef __amigaos4__
bool  HandleEvent(void)
#else
void  HandleEvent(void)
#endif
{
	int			ok;
	EventRecord	theEvent;
	HiliteMenu(0);
	SystemTask ();
	/* Handle desk accessories */

	ok = GetNextEvent (everyEvent, &theEvent);
	if (ok)
		switch (theEvent.what)
		{
			case mouseDown:
					HandleMouseDown(&theEvent);
					break;
	
			case keyDown:
			case autoKey:
					if ((theEvent.modifiers & cmdKey) != 0)
					{
						AdjustMenus();
						HandleMenu(MenuKey((char) (theEvent.message & charCodeMask)));
					}
					break;

			case updateEvt:
					BeginUpdate(bullseyeWindow);
					DrawBullseye(((WindowPeek) bullseyeWindow)->hilited);
					EndUpdate(bullseyeWindow);
					break;

	    		case activateEvt:
					InvalRect(&bullseyeWindow->portRect);
					break;
		}

#ifdef __amigaos4__
	return true;
#endif
}

int main()
{
	if (OpenMacEMU() == false) return -30;

	InitMacintosh();
	SetUpMenus();
	SetUpWindow();

#ifdef __amigaos4__
	while (HandleEvent()) { Delay(1); }
#else
	for (;;) HandleEvent();
#endif

	CloseMacEMU();
	return 0;
}


/* end main */

