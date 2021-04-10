
#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include "missing.h"

bool  n(handelEvensts)( WindowRecord *window )
{
	bool isQuit = false;
	struct IntuiMessage *msg;
	struct Window *win = ((GrafPort *) window) -> AmigaWindowContext.win;

	while (msg = (struct IntuiMessage *) GetMsg(win -> UserPort))
	{
		switch (msg -> Class)
		{
				case IDCMP_CLOSEWINDOW:
					isQuit = true;
					break;
		}

		ReplyMsg((struct Message *) msg);
	}
	return isQuit;
}


void CDirector::IDirector(CApplication*Capp)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	// not sure if this correct, but need, app to know about Bureaucrat
	Capp -> cbureaucrat = this;
}

void CWindow::IWindow(short, bool, int, CBureaucrat *bureaucrat)
{
	Rect bounds;
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	cbureaucrat = bureaucrat;

	SetRect(&bounds,50,50,200,100);
	window = NewWindow( NULL, &bounds, "Window",  TRUE,  0,  NULL,  TRUE,  0);
}

int CPane::FitToEnclosure(int, int)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CPane::Dawdle( int *maxSleep)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

CBureaucrat::CBureaucrat()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	app = NULL;
	itsWindow = NULL;
	itsGopher = NULL;
}

void CView::GetTitle(Str255 &wTitle)
{

}

void CView::SetTitle(Str255 &ptr)
{

}

void CView::Select()
{

}
