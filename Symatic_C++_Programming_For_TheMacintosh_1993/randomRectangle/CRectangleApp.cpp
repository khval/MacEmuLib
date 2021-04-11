

#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
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
	aDirector -> IDirector(this);

	CWindow *aWindow = new CWindow;

	aWindow -> IWindow(kWINDResourceID, !kWindowFloats, gDesktop, aDirector);
	aDirector -> itsWindow = aWindow;

	printf("aDirector -> itsWindow = %08x\n", aDirector -> itsWindow);

	CRandomRectanglePane *thePane = new CRandomRectanglePane;
	thePane -> IRandomRectanglePane(aWindow,  aDirector,  0, 0, 0, 0,
		(SizingOption) sizELASTIC, (SizingOption) sizELASTIC);

	thePane -> FitToEnclosure(TRUE, TRUE);
	aDirector -> itsGopher = thePane;

	printf("aDirector -> itsGopher = %08x\n", aDirector -> itsGopher);

}

