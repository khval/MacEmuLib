
#warning this file is all wrong, its here to add the missing stuff.


typedef int SizingOption;

class CPane		// used by CRandomRectanglePane
{
	public:
		virtual int FitToEnclosure(int,int);
		virtual void Dawdle( int *maxSleep);
};

class CBureaucrat;

class CView
{
	public:
		WindowPtr window;
		CBureaucrat *cbureaucrat;
		void GetTitle(Str255 &ptr);
		void SetTitle(Str255 &ptr);
		void SetTitle(Str63 &ptr);
		void Select();
};

class CDecorator;
class CApplication;

class CCollaborator
{
	public:
};

class CBureaucrat : CCollaborator
{
	public:
		CBureaucrat();
		CApplication *app;
		CView *itsWindow;		// the window to draw on.
		CPane *itsGopher;		// the gadgets going to be drawen
};

class CDirectorOwner : public CBureaucrat
{

};

class CApplication : public CDirectorOwner
{
	public:

		CApplication();

		short sfNumType;
		short sfFileTypes[20];
		short gSignature;

		CBureaucrat *cbureaucrat;
		CDecorator *gDecorator;

		void SetUpFileParameters();

		virtual void Exit();
		virtual void Run();
};


class CDecorator
{
	public:
		int GetWCount();
		void PlaceNewWindow(CView *win);
};


//  CDirector -> CBureaucrat -> CCollaborator

class CDirector : public CBureaucrat
{
	public:
		void IDirector(CApplication *capp);
};


class CWindow : public CView
{
	public:
		void IWindow(
			const short kind,
			Boolean hasFloats,
			int desktop,
			CBureaucrat *cbureaucrat
		);
};


#define IApplication(a,b,c,d)

#define gDesktop 1
#define sizELASTIC 1

