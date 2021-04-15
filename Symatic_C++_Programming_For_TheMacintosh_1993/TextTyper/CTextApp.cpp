
#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
#endif

#include "CDocument.h"
#include "CEditText.h"
#include "CTextDoc.h"
#include "CTextAPP.h"
#include "CScrollPane.h"


CTextApp::CTextApp()				// is run manually.
{
	printf("%s:%s:%d - this: %08x\n",__FILE__,__FUNCTION__,__LINE__,this);
}

void CTextApp::ITextApp()				// is run manually.
{
	const short	kExtraMaster = 1;
	const Size	kRainyDayFund = 45000;
	const Size	kCriticalBalance = 40000;
	const Size	kToolboxBalance = 20000;

	IApplication ( kExtraMasters, kRainyDayFund, kCriticalBalance, kToolboxBalance );
}

#ifdef __amigaos4__
#define ForgetObject(x) delete x
#endif

void CTextApp::CreateDocument()		// 2en thing, we call when we run it.
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	// CTextDoc -> CDocument -> CApplication

	CTextDoc *theDocument = new CTextDoc();

	try
	{
		theDocument -> ITextDoc(this);
		theDocument -> NewFile();
	}
	catch (int error)
	{
		ForgetObject( theDocument );
	}
}

void CTextApp::OpenDocument(SFReply *macReply)		// open new file??
{
	CTextDoc *theDocument = new CTextDoc;

	try
	{
		theDocument -> ITextDoc(this);
		theDocument -> OpenFile(macReply);
	}
	catch (int error)
	{
		ForgetObject( theDocument );
	}
}

void CTextApp::SetUpFileParameters()		// 1en thing, we call when we run it.
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	CApplication::SetUpFileParameters();
	sfNumType = 1;
	sfFileTypes[0]= 'TEXT';
	gSignature = 'C++2';
}

