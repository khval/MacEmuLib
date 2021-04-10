
#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
#endif

#include "CDocument.h"
#include "CScrollPane.h"


void CScrollPane::IScrollPane(CWindow*&, CDocument* const, int, int, int, int, int, int, const short int&)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CScrollPane::FitToEnclFrame(bool, bool)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

