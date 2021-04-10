
#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include "CDataFile.h"

void CDataFile::IDataFile()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CDataFile::SFSpecify(SFReply*&)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CDataFile::Open(int)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}


