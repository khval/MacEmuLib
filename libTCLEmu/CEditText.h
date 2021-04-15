
#ifndef CEditText_h
#define CEditText_h

#include "CView.h"
#include "CScrollPane.h"

class CEditText : public CView
{
	public:
		void IEditText(CView *object, CDocument* const, int, int, int, int, int, int, const short int&);
		void ChangeSize(Rect*, bool);
		void SetTextHandle( Handle handle );
		Handle GetTextHandle( );
};

#endif

