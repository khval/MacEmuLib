
#ifndef CPane_h
#define CPane_h

#include "CView.h"

class CPane : public CView		// used by CRandomRectanglePane
{
	public:
		virtual int FitToEnclosure(int,int);
		virtual void Dawdle( int *maxSleep);
};


#endif
