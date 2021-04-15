
#ifndef CScrollPane_h
#define CScrollPane_h

#include "CView.h"
#include "CDocument.h"

class CScrollPane : public CView
{
	public:
		void IScrollPane(CView *object, CDocument* const, int, int, int, int, int, int, const short int&);
		void FitToEnclFrame( Boolean kFitHorizontal, Boolean kFitVertical );
};

#endif

