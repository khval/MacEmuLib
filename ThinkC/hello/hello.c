#ifdef __amigaos4__
// Not real mac, we need some defines.
#include "MacEmuLib.h"
struct { int dummy; } thePort;
#endif


/***************************************************************************************/
/*							Programme de Hello en Think C			        */
/***************************************************************************************/
/***************************************************************************************/
#include <stdio.h>
#include <math.h>
#include <Files.h>
#include <StandardFile.h>

#define  REC 24
int main()
{
	int		i=25;
	int		x=400;
	double	y,sqrt();
	char		s[20],c;
	short	rc,fRef,errCode;
	SFReply	tr;
	Point		where;
	Handle	Buf;
	char		*Ptr;
	long		count;

#ifdef __amigaos4__
	if (OpenMacEMU() == false)
	{
		CloseMacEMU();
		return 0;
	}
#endif

	typedef struct
	 {
		int	jour;
		int	mois;
		int annee;
	} date ;

	date	anniv = {2, 7, 1951};


	where.h=100;
	where.v=50;

	printf ("nom ? ");
	scanf ("%s",s);
	printf ("%s \n",s);
	printf("hello world  ! No %d %o %x \n \007",i,i,i);	y=sqrt((double) x);

	y=pow(y,2.);

	printf("x= %d y= %.0f ¶x= %.8f \n",x,y,x-y);
	printf(" sizeof(date) = %d\n", (short) sizeof(date));

	SFGetFile(	where,"Quoi ?",	0,-1,	0,0,	&tr);

	if(tr.good)
	{
		rc=FSOpen(tr.fName,tr.vRefNum,&fRef);
		Buf=NewHandle(REC);
		Ptr=*Buf;
		count=REC;
		HLock(Buf);
		rc=FSRead(fRef,&count,*Buf);
		HUnlock(Buf);
		FSClose(fRef);

		// missing...

		free(Buf);

	}

#ifdef __amigaos4__
	CloseMacEMU();
	return 0;
#endif

}
