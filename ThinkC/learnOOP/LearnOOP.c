/*****
* LearnOOP.c 
* Copyright © 1991 Symantec Corporation. All rights reserved. 
*
*		The main file of the LearnOOP tutorial. 
*
*****/ 

#ifdef __amigaos4__
// Not real mac, we need some defines.
#include "libMacEmu.h"
#endif

#include <stdio.h>

/*#include <oops.h>*/

#include "windowUtils.h"

#include "LearnOOPShapes.h"

/**** * ChooseShape 
*
*	This function prompts you for a a kind of shape, 
*	creates an instance of it, and returns it. 
*
****/

static CShape *ChooseShape (void)
{
	char	c;
	while (1)
	{
		c = GetCh("Create [O]val or [R]ectangle");

		switch (c) {
			case 'Q':
			case 'q':
				return NULL;
				case 'R':
			case 'r':
				return new CRectangle;

			case 'O':
			case 'o':
				return new COval;
			default:

	/* stay in the loop */	
			break;
		}
	}
}

/****
* main
*
*	Prompt for a shape and its location. Then 
*	draw it in the drawing window. 
*
****/

int main()
{
	CShape	*aShape;
	short	top, left, bottom, right;

#ifdef __amigaos4__
	if (OpenMacEMU() == false) return -30;
#endif

	SetUpWindows();

	while (aShape = ChooseShape())
	 {
		top = GetNum("top");
		left = GetNum("left");
		bottom = GetNum("bottom");
		right = GetNum("right");

		printf("%d,%d,%d,%d\n",left,top,right,bottom);

		aShape->SetBounds(top, left, bottom, right);
		aShape->Draw();	
	}

#ifdef __amigaos4__
	CloseMacEMU();
#endif

	return 0;
}

