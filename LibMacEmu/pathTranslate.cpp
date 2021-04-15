
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


char *asl( const char *pattern )
{
	struct FileRequester	 *filereq;
	char *ret = NULL;
	char c;
	int l;

	if (filereq = (struct FileRequester	 *) AllocAslRequest( ASL_FileRequest, TAG_DONE ))
	{
		if (AslRequestTags( (void *) filereq, 
				ASLFR_DrawersOnly, FALSE,
				ASLFR_InitialPattern, pattern ? pattern : "",
				ASLFR_DoPatterns, TRUE,
				TAG_DONE ))
		{
			if ((filereq -> fr_File)&&(filereq -> fr_Drawer))
			{
				if (l = strlen(filereq -> fr_Drawer))
				{
					c = filereq -> fr_Drawer[l-1];
					if (ret = (char *) malloc( strlen(filereq -> fr_Drawer) + strlen(filereq -> fr_File) +2 ))
					{
						sprintf( ret, ((c == '/') || (c==':')) ? "%s%s" : "%s/%s",  filereq -> fr_Drawer, filereq -> fr_File ) ;
					}
				}
				else ret = strdup(filereq -> fr_File);
			}
		}
		 FreeAslRequest( filereq );
	}

	return ret;
}

#define bstr_to_ptr( ptr ) ((char *) (dl -> dol_Name << 2) + 1)

bool _amiga_has_volume(const char *name)
{
	char buffer[1000];
	struct DosList *dl;
	ULONG flags;

	flags = LDF_DEVICES|LDF_VOLUMES|LDF_ASSIGNS|LDF_READ;
	dl = LockDosList(flags);

	while(( dl = NextDosEntry(dl,flags) ))
	{
		switch (dl -> dol_Type)
		{
			case DLT_DEVICE:

				if (dl -> dol_Port)
				{
					if (DevNameFromPort(dl -> dol_Port,  buffer, sizeof(buffer), TRUE))
					{
						if (strcasecmp(name,buffer) == 0)
						{
							while(( dl = NextDosEntry(dl,flags) ));	// must read it to the end.. :-(
							UnLockDosList(flags);
							return true;
						}
					}
				}
				break;


			case DLT_LOCK:      /* normal assign */
			case DLT_VOLUME:
				
				if (strcasecmp(name,bstr_to_ptr(dl -> dol_Name) ) == 0)
				{
					while(( dl = NextDosEntry(dl,flags) ));	// must read it to the end.. :-(
					UnLockDosList(flags);
					return true;
				}
				break;
		}
	}

	UnLockDosList(flags);
	return false;
}

char *_mac_to_amiga_path(const  char *path )
{
	int l = strlen(path);
	char *newstr ;
	char *d_ptr;
	const char *s_end = path + l;
	const char *s_ptr;

	newstr = (char *) malloc( l + 1);
	bool first_divider = true;

	if (newstr)
	{
		d_ptr = newstr;	
		for (s_ptr =path ; s_ptr < s_end ; s_ptr++,d_ptr++)
		{
			switch (*s_ptr)
			{
				case ':':
						if (first_divider)
						{
							*d_ptr = 0;	// terminate string..
							*d_ptr = (_amiga_has_volume(newstr)) ? ':' : '/';
						}
						else *d_ptr = '/';		
 
						first_divider = false;
						break;
				
				default: *d_ptr = *s_ptr;
						break;
			}
		}
		*d_ptr = 0;

		return newstr;
	}

	return NULL;
}


char *_amiga_to_mac_path( const char *path )
{
	int l = strlen(path);
	const char *s_end = path + l;
	const char *s_ptr;
	char *newstr ;
	char *d_ptr;
	newstr = (char *) malloc( l + 1);
	bool first_divider = true;

	if (newstr)
	{
		d_ptr = newstr;	
		for (s_ptr =path ; s_ptr < s_end ; s_ptr++,d_ptr++)
		{
			switch (*s_ptr)
			{
				case '/': *d_ptr = ':'; 	break;
				default: *d_ptr = *s_ptr; break;
			}
		}
		*d_ptr = 0;

		return newstr;
	}

	return NULL;
}
