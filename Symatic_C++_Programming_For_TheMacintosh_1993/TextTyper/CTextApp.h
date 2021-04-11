
#ifndef CTextApp_h
#define CTextApp_h

class CTextApp: public CApplication
{
	public:
		void 		ITextApp();

		void	CreateDocument();
		void	OpenDocument(SFReply *macReply);
		void	SetUpFileParameters() ; 
};

#endif

