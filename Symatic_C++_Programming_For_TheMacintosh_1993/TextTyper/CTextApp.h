
#ifndef CTextApp_h
#define CTextApp_h

class CTextApp: public CApplication
{
	public:

		void 		ITextApp();

		virtual void	CreateDocument();
		virtual void	OpenDocument(SFReply *macReply);
		virtual void	SetUpFileParameters();
};

#endif

