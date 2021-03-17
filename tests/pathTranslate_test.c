
#ifdef __amigaos4__
#include <proto/exec.h>
#include <proto/asl.h>
#include <proto/exec.h>
#include <proto/dos.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "pathTranslate.h"
#include "MacEmuLib.h"

int main()
{
	char *mpath = NULL;
	char *apath = NULL;

	if ( OpenMacEMU() == false )
	{
		CloseMacEMU();
		return 0;
	}

	char *str = asl( NULL );

	if (str)
	{
		mpath = _amiga_to_mac_path( str);

		if (mpath)
		{
			apath = _mac_to_amiga_path( mpath);
		}

		printf("mac path: %s\n",mpath ? mpath : "NULL");
		printf("amiga path: %s\n",apath ? apath : "NULL");

		if (apath)	free(apath);
		if (mpath)	free(mpath);
		mpath = NULL;
		apath = NULL;

		 free(str);
	}
	str = NULL;

	CloseMacEMU();
	return 0;
}

