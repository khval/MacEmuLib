
#ifndef CPane_h
#define CPane_h

class CPane		// used by CRandomRectanglePane
{
	public:
		virtual int FitToEnclosure(int,int);
		virtual void Dawdle( int *maxSleep);
};


#endif
