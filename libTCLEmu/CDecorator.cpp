

#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include <CDecorator.h>

int CDecorator::GetWCount()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

void CDecorator::PlaceNewWindow(CView*)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

