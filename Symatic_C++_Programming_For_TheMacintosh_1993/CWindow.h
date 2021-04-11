
#include "CView.h"

#ifndef CWindow_h
#define CWindow_h

class CBureaucrat;

class CWindow : public CView
{
	public:
		void IWindow(
			const short kind,
			Boolean hasFloats,
			int desktop,
			CBureaucrat *cbureaucrat
		);
};

#endif

