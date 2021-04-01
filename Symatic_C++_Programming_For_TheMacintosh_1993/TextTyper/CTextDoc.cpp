

#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
#endif

#include "CDocument.h"
#include "CEditText.h"
#include "CTextDoc.h"


void CTextDoc::ITextDoc( CApplication *supervisor )
{
	const Boolean kPrintable = true;

	IDocument( supervisor, kPrintable);
}


void CTextDoc::NewFile()
{
	BuildWindow();

	Str255 wTitle;
	short wCount;
	Str255 wNumber;

	itsWindow->GetTitle(wTitle);
	wCount = gDecorator->GetWCount();
	::NumToString(wCount,wNumber);
	::ConcatPStrings(2Title,"-");
	itsWindow -> SetTitle(wTitle);
	itsWindow -> Select();
}

