

#ifndef CCollaborator_h
#define CCollaborator_h

class CView;

class CCollaborator
{
	protected:	// this are not used in this class, but vtable must be the same.

		virtual void SetUpFileParameters();
		virtual void CreateDocument();
		virtual void Exit();
		virtual void Run();

	public:		// will be used.
		CView *itsWindow;		// the window to draw on.
		CView *itsGopher;		// the gadgets going to be drawen

		CCollaborator()
		{
			printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
		}
};

#endif

