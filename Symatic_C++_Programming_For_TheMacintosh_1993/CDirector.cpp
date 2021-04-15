
#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
#endif

#include "CDirector.h"

void CDirector::IDirector(CApplication *Capp)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	// not sure if this correct, but need, app to know about Bureaucrat
	Capp -> nextApp = (CApplication *) this;
}

