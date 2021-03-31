
#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include "missing.h"

CAapplication::CAapplication()
{
	cbureaucrat = NULL;
}

void CAapplication::Exit()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CAapplication::Run()
{
	bool quit = false;

	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (cbureaucrat)
	{
		printf("found a bureaucrat...\n");

		if (cbureaucrat -> itsWindow)	// class
		{
			printf("he has a window\n");

			SetPort( cbureaucrat -> itsWindow -> window );

			if (cbureaucrat -> itsGopher)
			{
				int maxSleep;

				printf("he has work to do\n");

				while( ! quit )
				{
					cbureaucrat -> itsGopher -> Dawdle(&maxSleep);
					Delay(maxSleep);
				}
			}
		}
	}
}

void CDirector::IDirector(CAapplication*Capp)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	// not sure if this is correct, but need, app to know about Bureaucrat
	Capp -> cbureaucrat = this;
}

void CWindow::IWindow(short, bool, int, CDirector*cd)
{
	Rect bounds;
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	cbureaucrat = cd;

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

