
#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
#endif

#include "CTextApp.h"

int main()
{
#ifdef __amigaos4__
	if (OpenMacEMU() == false) return -30;
#endif

	CTextApp	*app;

	app = new CTextApp;
	app->ITextApp();
	app->Run();
	app->Exit();

#ifdef __amigaos4__
	CloseMacEMU();
#endif

}


