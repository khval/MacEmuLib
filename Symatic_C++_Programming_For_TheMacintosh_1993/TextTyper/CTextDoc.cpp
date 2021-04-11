
#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
#endif

#include "CTextDoc.h"
#include "CScrollPane.h"
#include "CEditText.h"
#include "CDataFile.h"

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
	LibMacEmu::ConcatPStrings(wTitle," - ");
	LibMacEmu::ConcatPStrings(wTitle, wNumber);
	itsWindow -> SetTitle(wTitle);
	itsWindow -> Select();
}

void CTextDoc::OpenFile(SFReply *macReply)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);

	CDataFile *theDataFile;
	Handle	theData;
	Str63	theName;
	OSErr	theError;
	const long	kMaxFileSize = 32000;

	theDataFile = new CDataFile;

	itsFile = theDataFile;

	theDataFile -> IDataFile();
	theDataFile -> SFSpecify(macReply);
	theDataFile -> Open( fsRdPerm );

	TRY {
		if (theDataFile->GetLength() > kMaxFileSize )
			Failure(mFulErr, excExeedTELimit);
		theData = theDataFile -> ReadAll();
	} CATCH {
		theDataFile-> Close();
	}
	ENDTRY;

	TRY {
		theDataFile->Close();
		BuildWindow();
		fEditText -> SetTextHandle(theData);
	} CATCH {
		DisposeHandle(theData);
	}
	ENDTRY;

	DisposeHandle(theData);

	itsFile -> GetName( theName );
	itsWindow -> SetTitle( theName );
	itsWindow -> Select();
}

Boolean CTextDoc::DoSave()
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);

	Handle theData;

	if (itsFile == NULL)
		return (DoSaveFileAs());
	else {
		CDataFile *theDataFile = (CDataFile *) itsFile;

		theData = fEditText->GetTextHandle();
		theDataFile -> Open( fsWrPerm );
		TRY {
			theDataFile -> WriteAll(theData);
		} CATCH {
			theDataFile -> Close();
		}
		theDataFile -> Close();
		dirty = FALSE;
		return(TRUE);
	}
}

Boolean CTextDoc::DoSaveAs( SFReply *macSFReply )
{
}

void CTextDoc::BuildWindow()
{
	const short	kWINDResourceID = 500;
	const Boolean	kWindowFloats = TRUE;
	const Boolean	kFitHorizontal = TRUE;
	const Boolean	kFitVertical = TRUE;
	const Boolean	kHasHorizontalScrollbar = TRUE;
	const Boolean	kHasVerticalScrollbar = TRUE;
	const Boolean	kHasGrowBox = TRUE;
	const short	kEditTextWidth = 72 * 6;
	const Boolean	kRedraw = TRUE;

	CWindow *aWindow = new CWindow;
	aWindow -> IWindow(kWINDResourceID, !kWindowFloats, gDesktop, this);
	itsWindow = aWindow;
	CScrollPane *theScrollPane = new CScrollPane;
	theScrollPane -> IScrollPane(aWindow, this, 10, 10, 0, 0, sizELASTIC, sizELASTIC, kEditTextWidth );
	theScrollPane -> FitToEnclFrame( kFitHorizontal, kFitVertical );

	CEditText *thePane = new CEditText;
	thePane -> IEditText(theScrollPane, this , 1,  1, 0, 0, sizELASTIC, sizELASTIC, kEditTextWidth );

	Rect margin;
	::SetRect( &margin, 2,2,-2,-2);
	thePane -> ChangeSize( &margin, !kRedraw );

	gDecorator -> PlaceNewWindow( itsWindow );
}

