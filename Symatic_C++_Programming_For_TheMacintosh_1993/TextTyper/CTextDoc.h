

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

