

#include "CDirectorOwner.h"

#ifndef CApplication_h
#define CApplication_h

class CBureaucrat;
class CDecorator;

class CApplication : public CDirectorOwner
{
	public:

		CApplication();

		short sfNumType;
		short sfFileTypes[20];
		short gSignature;

		CBureaucrat *cbureaucrat;
		CDecorator *gDecorator;

		virtual void SetUpFileParameters();
		virtual void CreateDocument();

		virtual void Exit();
		virtual void Run();
};

#endif

