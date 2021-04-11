

#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include "missing.h"

extern bool  n(handelEvensts)( GrafPort *window );

void CApplication::CreateDocument()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

CApplication::CApplication()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	cbureaucrat = NULL;
}

void CApplication::Exit()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CApplication::Run()
{
	bool quit = false;

	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	this->CreateDocument();

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
					quit = n(handelEvensts)( cbureaucrat -> itsWindow -> window);

					cbureaucrat -> itsGopher -> Dawdle(&maxSleep);
					Delay(maxSleep);
				}
			}
		}
	}
}

void CApplication::SetUpFileParameters()
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

