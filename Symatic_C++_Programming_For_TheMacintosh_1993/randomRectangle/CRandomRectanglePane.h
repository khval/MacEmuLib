

class CRandomRectanglePane : public CPane
{
	public:

		void IRandomRectanglePane(CView *anEnclosure, CBureaucrat *aSupervisor, 
				short aWidth, short aHeight, short aHEncl, short aVEncl,
				SizingOption aHSizing, SizingOption aVSizing);

	virtual void Dawdle( int *maxSleep);

	protected:
		virtual void DrawRectangleInRandomColor( const Rect *r );
		virtual void DrawRectangleInRandomPattern( const Rect *r );

	private:
		TRandom	fRandom;

};
