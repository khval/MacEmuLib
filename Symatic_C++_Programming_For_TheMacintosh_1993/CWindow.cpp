
#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include "CWindow.h"

CWindow::CWindow()
{
	printf("%s:%s:%d -- this: %08x\n",__FILE__,__FUNCTION__,__LINE__,this);
}

void CWindow::IWindow(short kind, Boolean kWindowFloats, int gDesktop, CBureaucrat *app)
{
	Rect bounds;
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("KindID: %d, kWindowFloats: %s, gDesktop: %d, bureaucrat: %0x\n",
			kind, kWindowFloats ? "True" : "False", gDesktop, app );

	SetRect(&bounds,50,50,200,100);
	window = NewWindow( NULL, &bounds, "Window",  TRUE,  0,  NULL,  TRUE,  0);
}



