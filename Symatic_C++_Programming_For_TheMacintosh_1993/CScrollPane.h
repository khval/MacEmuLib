
#ifndef CScrollPane_h
#define CScrollPane_h

class CScrollPane
{
	public:
		void IScrollPane(CWindow*&, CDocument* const, int, int, int, int, int, int, const short int&);
		void FitToEnclFrame( Boolean kFitHorizontal, Boolean kFitVertical );
};

#endif

