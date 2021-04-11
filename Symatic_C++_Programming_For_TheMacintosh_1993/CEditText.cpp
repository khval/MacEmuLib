

#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include "missing.h"

#include "CDocument.h"
#include "CEditText.h"

void CEditText::IEditText(CScrollPane*&, CDocument*, int, int, int, int, int, int, short const&)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CEditText::ChangeSize(Rect*, bool)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void SetTextHandle( Handle handle )
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CEditText::SetTextHandle(char**)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}