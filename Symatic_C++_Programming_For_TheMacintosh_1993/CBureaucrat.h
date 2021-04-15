

#include "CCollaborator.h"

#ifndef CBureaucrat_h
#define CBureaucrat_h

class CApplication;
class CView;
class CPane;

class CBureaucrat : public CCollaborator
{
	public:
		CBureaucrat();
		CApplication *app;
};

#endif
