

class CDocument : public CApplication
{
	Boolean kPrintable;

	public:
		CView *itsWindow;

		void IDocument( class CBureaucrat *_supervisor, Boolean _kPrintable);
};

