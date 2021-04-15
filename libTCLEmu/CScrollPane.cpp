
#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
#endif


#include "CDocument.h"
#include "CView.h"


void CScrollPane::IScrollPane(CView *object, CDocument *doc , int, int, int, int, int, int, const short int&)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	object -> gGopher = this;
}

void CScrollPane::FitToEnclFrame(bool, bool)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

