
#include "CView.h"

#ifndef CWindow_h
#define CWindow_h

class CWindow : public CView
{
	public:
		CWindow();
		
		void IWindow(
			const short kind,
			Boolean hasFloats,
			int,
			CBureaucrat *worker
		);
};

#endif

