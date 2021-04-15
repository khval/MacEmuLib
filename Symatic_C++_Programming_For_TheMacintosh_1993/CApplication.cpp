

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
	printf("%s:%s:%d - this: %08x\n",__FILE__,__FUNCTION__,__LINE__, this);
	nextApp = NULL;
}

void CApplication::Exit()
{
	printf("%s:%s:%d - this: %08x\n",__FILE__,__FUNCTION__,__LINE__, this);
}

void CApplication::Run()
{
	CApplication *currentApp;
	bool quit = false;

	printf("%s:%s:%d - this: %08x\n",__FILE__,__FUNCTION__,__LINE__, this);

	this->SetUpFileParameters();
	this->CreateDocument();

	printf("found a bureaucrat...\n");

	int maxSleep;
	bool hasWindow;

	while( ! quit )
	{
		hasWindow = false;

		for (currentApp = this ; currentApp; currentApp = currentApp -> nextApp)
		{
			printf("Running App: %08x\n",currentApp);
			printf("currentApp -> itsWindow: %08x - offsetof %d\n",currentApp -> itsWindow,offsetof(CApplication,itsWindow) );
			printf("currentApp -> itsGopher: %08x - offsetof %d\n",currentApp -> itsGopher,offsetof(CApplication,itsGopher));

			if (currentApp -> itsWindow)	// class
			{
				hasWindow = true;
				SetPort( currentApp -> itsWindow -> window );

				quit = n(handelEvensts)( currentApp -> itsWindow -> window);

				if (currentApp -> itsGopher)
				{
					currentApp -> itsGopher -> Dawdle(&maxSleep);
				}
				else quit = true;

				printf("Delay: %d\n",maxSleep);
				Delay(maxSleep);

				if (quit) break;
			}
		}

		if (hasWindow == false)
		{
			printf("no window, has to quit\n");
			quit = true;
		}
	}
}

void CApplication::SetUpFileParameters()
{
	printf("%s:%s:%d - this: %08x\n",__FILE__,__FUNCTION__,__LINE__, this);
}

