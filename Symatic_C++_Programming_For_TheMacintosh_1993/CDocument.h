
#ifndef CDocument_h
#define CDocument_h

#include "CDataFile.h"

class CDocument : public CApplication
{
	Boolean kPrintable;

	public:
		CView *itsWindow;
		CDataFile *itsFile;

		void IDocument( class CBureaucrat *_supervisor, Boolean _kPrintable);
};

#endif

