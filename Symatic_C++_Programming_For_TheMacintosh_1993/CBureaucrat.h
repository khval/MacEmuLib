

#include "CCollaborator.h"

#ifndef CBureaucrat_h
#define CBureaucrat_h

class CApplication;
class CView;
class CPane;

class CBureaucrat : CCollaborator
{
	public:
		CBureaucrat();
		CApplication *app;
		CView *itsWindow;		// the window to draw on.
		CPane *itsGopher;		// the gadgets going to be drawen
};

#endif
