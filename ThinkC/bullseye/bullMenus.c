
#ifdef __amigaos4__
// Not real mac, we need some defines.
#include "libMacEmu.h"
struct { int dummy; } thePort;
#endif

#include "bullMenus.h"

extern	WindowPtr bullseyeWindow;
extern	int	width;


MenuHandle	appleMenu, fichierMenu, editionMenu, widthMenu;

enum	{
	appleID = 1,
	fichierID,
	editionID,
	widthID
	};

enum	{
	openItem = 1,
	closeItem,
	quitItem = 4
	};

void SetUpMenus(void)

{
	InsertMenu(appleMenu = NewMenu(appleID, "\024"), 0);
	InsertMenu(fichierMenu = NewMenu(fichierID, "Fichier"), 0);
	InsertMenu(editionMenu = NewMenu(editionID, "Edition"), 0);
	InsertMenu(widthMenu = NewMenu(widthID, "Epaisseur"), 0);
	DrawMenuBar();	
	AppendMenu(appleMenu, "A propos de bullseye�;(-");
	AddResMenu(appleMenu, 'DRVR');
	AppendMenu(fichierMenu, "Ouvrir/O;Fermer/W;(-;Quitter/Q");
	AppendMenu(editionMenu, "Annuler/Z;(-;Couper/X;Copier/C;Coller/V;Effacer");
	AppendMenu(widthMenu, "1/1;2/2;3/3;4/4;5/5;6/6;7/7;8/8;9/9;10/0;11;12");
}

static void enable (MenuHandle menu, short item, short ok);

void AdjustMenus(void)
{
	register WindowPeek wp = (WindowPeek) FrontWindow();
	short kind = wp ? wp->windowKind : 0;
	Boolean DA = kind < 0;
	
	enable(editionMenu, 1, DA);
	enable(editionMenu, 3, DA);
	enable(editionMenu, 4, DA);
	enable(editionMenu, 5, DA);
	enable(editionMenu, 6, DA);
	
	enable(fichierMenu, openItem, !((WindowPeek) bullseyeWindow)->visible);
	enable(fichierMenu, closeItem, DA || ((WindowPeek) bullseyeWindow)->visible);

	CheckItem(widthMenu, width, true);
}


static void enable(MenuHandle menu, short item, short ok)
{
	if (ok)
		EnableItem(menu, item);
	else
		DisableItem(menu, item);
}


void HandleMenu (long mSelect)

{
	int			menuID = HiWord(mSelect);
	int			menuItem = LoWord(mSelect);
	Str255		name;
	GrafPtr		savePort;
	WindowPeek	frontWindow;
	
	switch (menuID)
	  {
	  case	appleID:
		GetPort(&savePort);
		GetItem(appleMenu, menuItem, name);
		OpenDeskAcc(name);
		SetPort(savePort);
		break;
			
	  case	fichierID:
		switch (menuItem)
		  {
		  case	openItem:
			ShowWindow(bullseyeWindow);
			SelectWindow(bullseyeWindow);
			break;
  				  			
		  case	closeItem:
			if ((frontWindow = (WindowPeek) FrontWindow()) == 0L)
			  break;
			  
			if (frontWindow->windowKind < 0)
			  CloseDeskAcc(frontWindow->windowKind);
			else if (frontWindow = (WindowPeek) bullseyeWindow)
			  HideWindow(bullseyeWindow);
  				  	break;
  				  	
		  case	quitItem:
			ExitToShell();
			break;
		  }
		break;
  				
	  case	editionID:
		if (!SystemEdit(menuItem-1))
		  SysBeep(5);
		break;
		
	  case	widthID:
		CheckItem(widthMenu, width, false);
		width = menuItem;
		InvalRect(&bullseyeWindow->portRect);
		break;
	  }
}


