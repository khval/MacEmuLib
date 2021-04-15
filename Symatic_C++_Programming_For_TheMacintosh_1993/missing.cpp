
#ifdef __amigaos4__
#include "libMacEmu.h"
#endif

#include "missing.h"

bool  n(handelEvensts)( GrafPort *window )
{
	bool isQuit = false;
	struct IntuiMessage *msg;
	struct Window *win = ((GrafPort *) window) -> AmigaWindowContext.win;

	if (win)
	{
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
	}
	return isQuit;
}

