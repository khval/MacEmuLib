/*****
*	LearnOOPShapes.h
*	Copyright © 1991 Symantec Corporation. All rights reserved.
*
*****/

#pragma once
#pragma options(virtual)

// ensure that all methods
// are virtual, regardless
// of project settings

	//	NOTE:
	//	This example uses "struct" declarations
	//	for classes to make sure that all the
	//	members are public
	//	CShape is the abstract class that
	//	describes all shapes. All shape
	//	classes are subclasses of this class.

struct CShape 
{
	Rect	itsRectangle;

	// The rectangle that	
	// encloses the shape.

	//	The SetBounds method sets values
	//	for itsRectangle. Most subclasses
	//	won't need to override it.	

	short SetBounds (short aTop, short aLeft, short aBottom, short aRight);

	//	The Draw method draws the shape. All
	//	subclasses should override it.

	short std_draw(void);

	virtual short Draw(void);
};

struct	CRectangle : CShape 
{
	virtual short Draw(void);
};

struct COval : CShape
{
	virtual short Draw(void);
};

