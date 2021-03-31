
#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
#endif

#include "TRandom.h"
#include "CRandomRectanglePane.h"
#include "CRectangleAPP.h"

int main()
{
#ifdef __amigaos4__
	if (OpenMacEMU() == false) return -30;
#endif

	CRectangleApp	*rectangleApp;

	rectangleApp = new CRectangleApp;
	rectangleApp -> IRectangleApp();
	rectangleApp -> Run();
	rectangleApp -> Exit();

#ifdef __amigaos4__
	CloseMacEMU();
#endif

	return 0;
}

