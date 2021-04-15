
#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include "CBureaucrat.h"

#ifndef CView_h
#define CView_h


class CView
{
	public:
		CView *gGopher;
		WindowPtr window;
		CBureaucrat *cbureaucrat;
		void GetTitle(Str255 &ptr);
		void SetTitle(Str255 &ptr);
		void SetTitle(Str63 &ptr);
		void Select();
		virtual void Dawdle( int *maxSleep);
};

#endif

