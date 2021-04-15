


#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include "CView.h"

void CView::GetTitle(Str255 &wTitle)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CView::SetTitle(Str255 &ptr)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CView::SetTitle(Str63 &ptr)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CView::Select()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CView::Dawdle(int*)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

