
#ifndef CTextApp_h
#define CTextApp_h

class CTextApp: public CApplication
{
	public:
		CTextApp();
		void 	ITextApp();
		void	CreateDocument();
		void	OpenDocument(SFReply *macReply);
		void	SetUpFileParameters() ; 
};

#endif

