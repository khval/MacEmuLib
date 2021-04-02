
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
};

class m(itsWindow)	// name is not know at this time...
{
	public:
		void GetTitle(Str255 &ptr);
		void SetTitle(Str255 &ptr);
		void Select();
};

class CDecorator;
class CApplication;

class CBureaucrat
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

		short sfNumType;
		short sfFileTypes[20];
		short gSignature;

		CApplication();

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
};


class CDirector : public CBureaucrat
{
	public:
		void IDirector(CApplication *capp);
};


class CWindow : public CView
{
	public:
		void IWindow(
			short kind,
			Boolean hasFloats,
			int desktop,
			CDirector *aDirector
		);
};

#define IApplication(a,b,c,d)

#define gDesktop 1
#define sizeELASTIC 1

