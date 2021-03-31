
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


class CAapplication
{
	public:
		CBureaucrat *cbureaucrat;

		CAapplication();

		virtual void Exit();
		virtual void Run();
};


class CBureaucrat
{
	public:
		CBureaucrat();
		CAapplication *app;
		CView *itsWindow;		// the window to draw on.
		CPane *itsGopher;		// the gadgets going to be drawen
};

class CDirector : public CBureaucrat
{
	public:
		void IDirector(CAapplication *capp);
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

