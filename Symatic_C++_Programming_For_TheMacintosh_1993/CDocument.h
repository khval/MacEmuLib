
#ifndef CDocument_h
#define CDocument_h

#include "CDataFile.h"

class CDocument : public CApplication
{
	Boolean kPrintable;

	public:
		Boolean dirty ;
		CDataFile *itsFile;

		CDocument()
		{
			printf("%s:%s:%d - this: %08x\n",__FILE__,__FUNCTION__,__LINE__, this);
		}

		void IDocument( CApplication *&_supervisor, Boolean _kPrintable);
		Boolean DoSaveFileAs();
};

#endif

