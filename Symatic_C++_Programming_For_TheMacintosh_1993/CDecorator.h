
#ifndef CDecorator_h
#define CDecorator_h

class CView;

class CDecorator
{
	public:
		int GetWCount();
		void PlaceNewWindow(CView *win);
};

#endif

