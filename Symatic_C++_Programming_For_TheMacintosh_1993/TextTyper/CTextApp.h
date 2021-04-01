
class CTextApp: public CApplication
{
	public:

		void 		ITextApp();

		virtual void	CreateDocument();
		virtual void	OpenDocument(SFReply *macReply);
		virtual void	SetUpFileParameters();
};

