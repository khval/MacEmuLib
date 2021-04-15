



#ifndef CApplication_h
#define CApplication_h

#include "CCollaborator.h"
#include "CBureaucrat.h"
#include "CDirectorOwner.h"
#include "CDecorator.h"

// CApplication -> CDirectorOwner -> CBureaucrat -> CCollaborator

class CApplication : public CDirectorOwner
{
	public:

		CApplication();

		short sfNumType;
		short sfFileTypes[20];
		short gSignature;

		CApplication *nextApp;
		CDecorator *gDecorator;

		virtual void SetUpFileParameters();
		virtual void CreateDocument();

		virtual void Exit();
		virtual void Run();

};

#endif

