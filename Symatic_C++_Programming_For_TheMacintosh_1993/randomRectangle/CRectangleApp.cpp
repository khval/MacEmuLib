

#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
#include "CPane.h"
#endif

#include "CRectangleApp.h"
#include "TRandom.h"
#include "CRandomRectanglePane.h"

void CRectangleApp::IRectangleApp()
{
	const short	kExtraMasters = 1;
	const Size	kRainyDayFund = 45000;
	const Size	kCriticalBalance = 40000;
	const Size 	kToolboxBalance = 20000;
	const short	kWINDResourceID = 500;
	const Boolean	kWindowFloats = TRUE;

	IApplication( kExtraMasters, kRainyDayFund, kCriticalBalance, kToolboxBalance);

	CDirector *aDirector = new CDirector;
	aDirector -> IDirector(this);											// aDirector & CRectangleApp

	CWindow *aWindow = new CWindow;

	aWindow -> IWindow(kWINDResourceID, !kWindowFloats, gDesktop, aDirector);	// Assign CDirector to CWindow.
	aDirector -> itsWindow = aWindow;										// Assign CWindow to CDirector

	printf("aDirector -> itsWindow = %08x\n", aDirector -> itsWindow);

	CRandomRectanglePane *thePane = new CRandomRectanglePane;

	printf("aDirector -> itsWindow = %08x\n", aDirector -> itsWindow);

	thePane -> IRandomRectanglePane(aWindow,  aDirector,  0, 0, 0, 0,				// thePane & aDirector ( that knows itsWindow )
		(SizingOption) sizELASTIC, (SizingOption) sizELASTIC);

	printf("aDirector -> itsWindow = %08x, offsetof %d \n", aDirector -> itsWindow, offsetof(CDirector,itsWindow) );

	thePane -> FitToEnclosure(TRUE, TRUE);									// Don't do anything.. as it is now...
	aDirector -> itsGopher = thePane;										// Assign thePane to CDirector

	printf("aDirector -> itsGopher = %08x, offsetof %d\n", aDirector -> itsGopher, offsetof(CDirector,itsGopher) );
	printf("aDirector -> itsWindow = %08x, offsetof %d\n", aDirector -> itsWindow, offsetof(CDirector,itsWindow) );

}

