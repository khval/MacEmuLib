
#ifndef CEditText_h
#define CEditText_h

#include "CScrollPane.h"

class CEditText
{
	public:
		void IEditText(CScrollPane*&, CDocument* const, int, int, int, int, int, int, const short int&);
		void ChangeSize(Rect*, bool);
};

#endif

