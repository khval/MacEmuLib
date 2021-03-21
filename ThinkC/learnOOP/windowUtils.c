/*****
*	windowUtils.c 
*	Copyright © 1991 Symantec Corporation. All rights reserved. 
*
*		Utility functions for the LearnOOP tutorial. These routines 
*		set up the console and drawing windows and provide a 
*		clean way to get input. 
*
*		You do not need to understand these functions to do the
*		LearnOOP tutorial, though you may find them interesting. 
*
*****/

#ifdef __amigaos4__
// Not real mac, we need some defines.
#include "libMacEmu.h"
#endif

#include <stdio.h>
#include <console.h>
#include "windowUtils.h"


 WindowPtr	DrawingWindow;

/****
*	SetUpWindows 
*
*	Set up the windows so the console window 
*	is just big enough to handle a line of input. 
*	Then make a Macintosh window that we can use 
*	to draw some shapes in. 
* 
****/

void SetUpWindows (void)
{
	Rect	drawingWindowPosition = {95, 10, 300, 348};

	//	Change some aspects of the default	
	//	console window: its size and its title.	
	//
	//	Also, let the console package know that
	//	we want to program to exit when we're
	//	finished.

	console_options.top = 40;
	console_options.left = 10;
	console_options.title = "LearnOOP";
	console_options.nrows = 2;
	console_options.ncols = 55;
	console_options.pause_atexit = 0;

	//	cshow() initializes the console
	//	package and displays the console window.

//	cshow(stdout);

	//	Now create a Macintosh window. Note that
	//	its position is fixed and that it cannot	
	//	be moved.

	DrawingWindow = NewWindow(NULL, &drawingWindowPosition,"Drawing", TRUE, noGrowDocProc,(struct __mac_window__ *)-1L, FALSE, 0L);
}


/* end SetUpWindows */

/****
*	Prompt 
*
*	Put a prompt string on the first line of the console window. 
*
****/

void Prompt (char *string)
{
//	cgotoxy(1,1,stdout);

	printf("%s: ", string);

//	ccleol(stdout);
}

/* end Prompt 
*/

/****
*	GetCh 
*
*	Get a character from the console window. 
*
****/

char GetCh (char *string)
{
	short	theChar;

	if (string)		Prompt(string);

	theChar = getchar();	fflush(stdin);

	/* ignore any additional characters in input buffer */

	return theChar;
}

/* end GetCh */

/**** 
*	GetNum 
* 
*	Get an integer from the console window. 
*
****/

#if defined(__amigaos4__)

short	GetNum (char *string)
{
	char line[100];
	int	theInt;

	while (1) 
	{
		if (string)
			Prompt(string);	

		if (fgets(line,100,stdin))
		{
			if (sscanf(line,"%d", &theInt) == 1)
				return theInt;
		}

		fflush(stdin);

		/* get rid of any additional characters in input buffer */
	}

}/* end GetNum */

#else

short	GetNum (char *string)
{
	short	theInt;

	while (1) 
	{
		if (string)
			Prompt(string);	

		if (scanf("%d", &theInt) == 1)
			return theInt;

		fflush(stdin);

		/* get rid of any additional characters in input buffer */
	}

}/* end GetNum */

#endif
