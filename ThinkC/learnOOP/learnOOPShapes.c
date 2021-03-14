/***** * LearnOOPShapes.c * Copyright © 1991 Symantec Corporation. All rights reserved. 
*
*		These are the methods that operate on the shapes in the 
*		LearnOOP tutorial. 
* 
*****/


#ifdef __amigaos4__
#include "amigaos4.h"
#include "missing.h"
#endif

/*#include <oops.h>*/

#include "LearnOOPShapes.h"
extern	WindowPtr	DrawingWindow;

	// The drawing window is									

// defined in windowUtils.c

/**** 
*	SetBounds * 
*	Set the bounding rectangle of the shape. 
* 
***/

short CShape::SetBounds (short aTop, short aLeft, short aBottom, short aRight)
{
	itsRectangle.top = aTop;
	itsRectangle.left = aLeft;
	itsRectangle.bottom = aBottom;
	itsRectangle.right = aRight;
}

/****
*	Draw 
* 
*	The default Draw() method for all shapes 
*	simply sets the port to the drawing window 
*	to make sure that the shape is being drawn in it. 
*	All subclasses that override the Draw() method 
*	should call inherited::Draw() 
* 
****/

short CShape::std_draw (void)
{
	printf("%s:%d\n",__FUNCTION__,__LINE__);
	SetPort(DrawingWindow);
}

short CShape::Draw (void)
{
	std_draw();
}

/****
*	CRectangle::Draw 
*
*	The Draw() method for rectangles simply uses 
*	the Macintosh Toolbox routine FrameRect() 
*	to do the work-- after calling its ancestor's Draw() 
*	method to set the port correctly. 
*
****/

short CRectangle::Draw (void)
{
	printf("%s:%d\n",__FUNCTION__,__LINE__);
	std_draw();
	FrameRect(&itsRectangle);
}

/****
*	COval::Draw 
*	 
*	The Draw() method for ovals simply uses 
*	the Macintosh Toolbox routine FrameOval() 
*	to do the work-- after calling its ancestor's Draw() 
*	method to set the port correctly. 
*
****/ 

short COval::Draw (void)
{
	printf("%s:%d\n",__FUNCTION__,__LINE__);

	std_draw();
	FrameOval(&itsRectangle);
}

