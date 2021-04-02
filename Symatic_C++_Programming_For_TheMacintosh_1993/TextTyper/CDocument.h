

class CDocument : public CApplication
{
	Boolean kPrintable;

	public:
		m(itsWindow) *itsWindow;

		void IDocument( class CBureaucrat *_supervisor, Boolean _kPrintable);
};

