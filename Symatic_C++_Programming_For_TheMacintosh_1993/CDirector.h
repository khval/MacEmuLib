
#ifndef CDirector_h
#define CDirector_h

#include "CBureaucrat.h"
#include "CApplication.h"

//  CDirector -> CBureaucrat -> CCollaborator

class CDirector : public CBureaucrat
{
	public:
		void IDirector(CApplication *capp);
};

#endif

