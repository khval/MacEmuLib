
#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
#endif

#include "TRandom.h"
#include "CRandomRectanglePane.h"


#ifdef __amigaos4__

void 	IPane(
		CView *anEnclosure,
		CBureaucrat *aSupervisor,
		short aWidth,
		short aHeight,
		SizingOption aHSizing,
		SizingOption aVSizing )
{
	printf("IPane: %d,%d,%d,%d\n",aWidth,aHeight,aHSizing,aVSizing);
}

struct {
	bool hasColorQD;
} gSystem = {true};


#endif 

void CRandomRectanglePane::IRandomRectanglePane(CView *anEnclosure, CBureaucrat *aSupervisor, 
				short aWidth,short aHeight, short aHEncl, short aVEncl,
				SizingOption aHSizing, SizingOption aVSizing)
{
	IPane( anEnclosure , aSupervisor, aWidth,  aHeight, aHSizing, aVSizing );
}

void CRandomRectanglePane::Dawdle( int *maxSleep)
{
	Rect r;
	Point p1;
	Point p2;
	LongRect frameSize;

	GetFrame( &frameSize );

	p1.h = fRandom.valueInRange( frameSize.left, frameSize.right );
	fRandom.advance();

	p1.v = fRandom.valueInRange( frameSize.top, frameSize.bottom );
	fRandom.advance();

	p2.h = fRandom.valueInRange( frameSize.left, frameSize.right );
	fRandom.advance();

	p2.v = fRandom.valueInRange( frameSize.top, frameSize.bottom );
	fRandom.advance();

	::Pt2Rect(p1,p2,&r);

	Prepare();

	if (gSystem.hasColorQD)
		DrawRectangleInRandomColor(&r);
	else
		DrawRectangleInRandomPattern(&r);

	*maxSleep = 20;
}


#ifdef __amigaos4__

#warning some stuff we dont have, trying to workaround it.

typedef RGBColor pixPat;
typedef pixPat *pixPatHandle;
#define NewPixPat new pixPat
#define MakeRGBPat(p,color) *p = *(color)
#define DisposePixPat(a) delete a

extern GrafPort *m(GrafPort);

void FillCRect(const Rect *r,  pixPatHandle pixPat)
{
	uint32_t color;
	struct RastPort *rp = m(GrafPort) -> AmigaWindowContext.win -> RPort;

	color = (( pixPat->red & 0xFF)  << 16) | ( (pixPat->green & 0xFF) << 8) | (pixPat->blue & 0xFF);

	SetRPAttrs( rp,
		RPTAG_APenColor, color, 
		TAG_END	);

	RectFill( rp, r->left, r->top, r->right, r->bottom);
}

#endif

void CRandomRectanglePane::DrawRectangleInRandomColor( const Rect *r )
{
	RGBColor	aColor;
	pixPatHandle myPixPat;

	aColor.red = fRandom.value();
	fRandom.advance();

	aColor.green = fRandom.value();
	fRandom.advance();

	aColor.blue = fRandom.value();
	fRandom.advance();

	myPixPat = NewPixPat();
	MakeRGBPat(myPixPat,&aColor);
	FillCRect(r,myPixPat);
	DisposePixPat(myPixPat);
}


void CRandomRectanglePane::DrawRectangleInRandomPattern( const Rect *r )
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}


