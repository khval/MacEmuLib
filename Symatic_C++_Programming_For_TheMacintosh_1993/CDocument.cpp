
#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include "missing.h"
#include "CDocument.h"


void CDocument::IDocument( class CBureaucrat *_supervisor, Boolean _kPrintable)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

