
#ifndef CView_h
#define CView_h

#include "CBureaucrat.h"

class CView
{
	public:
		WindowPtr window;
		CBureaucrat *cbureaucrat;
		void GetTitle(Str255 &ptr);
		void SetTitle(Str255 &ptr);
		void SetTitle(Str63 &ptr);
		void Select();
};

#endif

