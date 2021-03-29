
#include "libMacEmu.h"
#include "Resources.h"

short InitResources(void)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void RsrcZoneInit(void)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CloseResFile(short refNum)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short ResError(void)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short CurResFile(void)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short HomeResFile(Handle theResource)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void CreateResFile(ConstStr255Param fileName)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short OpenResFile(ConstStr255Param fileName)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void UseResFile(short refNum)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short CountTypes(void)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short Count1Types(void)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void GetIndType(ResType *theType,short index)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void Get1IndType(ResType *theType,short index)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void SetResLoad(Boolean load)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short CountResources(ResType theType)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short Count1Resources(ResType theType)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

Handle GetIndResource(ResType theType,short index)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

Handle Get1IndResource(ResType theType,short index)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

Handle GetResource(ResType theType,short theID)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

Handle Get1Resource(ResType theType,short theID)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

Handle GetNamedResource(ResType theType,ConstStr255Param name)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

Handle Get1NamedResource(ResType theType,ConstStr255Param name)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void LoadResource(Handle theResource)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void ReleaseResource(Handle theResource)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void DetachResource(Handle theResource)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short UniqueID(ResType theType)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short Unique1ID(ResType theType)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short GetResAttrs(Handle theResource)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void GetResInfo(Handle theResource,short *theID,ResType *theType, Str255 name)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void SetResInfo(Handle theResource,short theID,ConstStr255Param name)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void AddResource(Handle theResource,ResType theType,short theID, ConstStr255Param name)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

long SizeResource(Handle theResource)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

long MaxSizeRsrc(Handle theResource)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

long RsrcMapEntry(Handle theResource)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void SetResAttrs(Handle theResource,short attrs)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void ChangedResource(Handle theResource)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void RmveResource(Handle theResource)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void UpdateResFile(short refNum)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

Handle getnamedresource(ResType theType,char *name)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}
 
void WriteResource(Handle theResource)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void SetResPurge(Boolean install)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

Handle get1namedresource(ResType theType,char *name)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}
 
short GetResFileAttrs(short refNum)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void SetResFileAttrs(short refNum,short attrs)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short OpenRFPerm(ConstStr255Param fileName,short vRefNum,char permission)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

Handle RGetResource(ResType theType,short theID)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short HOpenResFile(short vRefNum,long dirID,ConstStr255Param fileName,    char permission)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}
 
void HCreateResFile(short vRefNum,long dirID,ConstStr255Param fileName)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}
 
short FSpOpenResFile(const FSSpec *spec,SignedByte permission)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void FSpCreateResFile(const FSSpec *spec,OSType creator,OSType fileType,  ScriptCode scriptTag)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void ReadPartialResource(Handle theResource,long offset,void *buffer,  long count)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void WritePartialResource(Handle theResource,long offset,const void *buffer, long count)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void SetResourceSize(Handle theResource,long newSize)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

short openrfperm(char *fileName,short vRefNum,char permission)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}
 
short openresfile(char *fileName)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}
 
void createresfile(char *fileName)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}
 
void getresinfo(Handle theResource,short *theID,ResType *theType,char *name)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}
 
void setresinfo(Handle theResource,short theID,char *name)
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}
 
void addresource(Handle theResource,ResType theType,short theID,char *name) 
{
	printf("%s:%d:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

