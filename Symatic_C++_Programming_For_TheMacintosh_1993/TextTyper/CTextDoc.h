
// CTextDoc -> CDocument -> CApplication

#ifndef CTextDoc_h
#define CTextDoc_h

#include "CDocument.h"
#include "CEditText.h"

class CTextDoc : public CDocument
{
	public:
		void ITextDoc( CApplication *app );

		void NewFile();
		void OpenFile( SFReply *macReply );
		virtual Boolean DoSave();
		virtual Boolean DoSaveAs( SFReply *macSFReply );

	protected:
		virtual void BuildWindow();

	private:
		CEditText	*fEditText;
};

#endif

