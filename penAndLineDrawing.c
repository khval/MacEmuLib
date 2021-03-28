
#include "libMacEmu.h"
#include "vector_array.h"
#include "proto/gadtools.h"	// used by AmigaOS menu system.

extern GrafPort *m(GrafPort);

typedef struct
{
	int __nothing__;
} PenState;

void HidePen()
{
	m(GrafPort)->pnVis --;
}

void ShowPen()
{
	m(GrafPort)->pnVis ++;
}

void PenNormal()
{
	m(GrafPort)->pnSize.x = 0;
	m(GrafPort)->pnSize.y = 0;
	m(GrafPort)->pnMode = patCopy;
	m(GrafPort)->pnPat = black;
}

void GetPen(Point *pt)
{
}

void GetPenSate(PenState *pnSate)
{
}

void SetPenState(PenState pnState)
{
}

void PenSize(int width, int height)
{
	m(GrafPort)->pnSize.x = width;
	m(GrafPort)->pnSize.y = height;
}

void PenPat(Pattern *pat)
{
	m(GrafPort)->pnPat = *pat;
}

void PenMode(int mode)
{
	m(GrafPort)->pnMode = mode;
}

void MoveTo( int h, int v )	// absolute
{
	struct RastPort *rp = m(GrafPort) -> AmigaWindowContext.win -> RPort;

	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	IGraphics -> Move( rp, h,v );
	m(GrafPort)->pnLoc.x=h;
	m(GrafPort)->pnLoc.y=v;
}

void Move(int h,int v)		// relative
{
	struct RastPort *rp = m(GrafPort) -> AmigaWindowContext.win -> RPort;

	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	m(GrafPort)->pnLoc.x+=h;
	m(GrafPort)->pnLoc.y+=v;
	IGraphics -> Move( rp, m(GrafPort)->pnLoc.x,m(GrafPort)->pnLoc.y );
}

void LineTo(int h,int v)	// absolute
{
	struct RastPort *rp = m(GrafPort) -> AmigaWindowContext.win -> RPort;

	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	IGraphics -> Draw( rp, h,v );
	m(GrafPort)->pnLoc.x=h;
	m(GrafPort)->pnLoc.y=v;
}

void Line(int h,int v)	// relative
{
	struct RastPort *rp = m(GrafPort) -> AmigaWindowContext.win -> RPort;

	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	m(GrafPort)->pnLoc.x+=h;
	m(GrafPort)->pnLoc.y+=v;
	IGraphics -> Draw( rp, m(GrafPort)->pnLoc.x,m(GrafPort)->pnLoc.y );
}

