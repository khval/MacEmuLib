
#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include "missing.h"
#include "CDocument.h"

void CDocument::IDocument( CApplication *&_supervisor, Boolean _kPrintable)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	_supervisor -> nextApp = this;
}

Boolean CDocument::DoSaveFileAs()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("*** Should open AS\n");
	printf("*** Should call DoSaveAS(...)\n");
}

