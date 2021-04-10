
#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"
#endif

#include "CDocument.h"
#include "CEditText.h"
#include "CTextDoc.h"
#include "CTextAPP.h"
#include "CScrollPane.h"

void CTextApp::ITextApp()
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

void CTextApp::CreateDocument()
{

	CTextDoc *theDocument = new CTextDoc();
/*
	try
	{
		theDocument -> ITextDoc(this);
		theDocument -> NewFile();
	}
	catch (int error)
	{
		ForgetObject( theDocument );
	}*/
}

void CTextApp::OpenDocument(SFReply *macReply)
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

void CTextApp::SetUpFileParameters()
{
	CApplication::SetUpFileParameters();
	sfNumType = 1;
	sfFileTypes[0]= 'TEXT';
	gSignature = 'C++2';
}

