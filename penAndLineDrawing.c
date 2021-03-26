
#include "libMacEmu.h"
#include "vector_array.h"
#include "proto/gadtools.h"	// used by AmigaOS menu system.

extern WindowPtr m(used_window);

typedef struct
{
	int __nothing__;
} PenState;

void HidePen()
{
}

void ShowPen()
{
}

void GetPen(Point *pt)
{
}

void GetPenSate(PenState *pnSate)
{
}

void SetPenState(PenState **pnState)
{
}

void PenSize(int width, int height)
{
}

void PenMode(int mode)
{
}

void MoveTo( int x, int y )
{
	struct RastPort *rp = m(used_window) -> AmigaWindowContext.win -> RPort;
	Move( rp, x,y );
}

void Move(int h,int v)
{
}

void LineTo(int h,int v)
{
}

void Line(int h,int v)
{
}

