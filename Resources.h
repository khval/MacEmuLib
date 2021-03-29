

#ifndef __RESOURCES__
#define __RESOURCES__

enum {

    resSysHeap = 64,    /*System or application heap?*/
    resPurgeable = 32,  /*Purgeable resource?*/
    resLocked = 16,     /*Load it in locked?*/
    resProtected = 8,   /*Protected?*/
    resPreload = 4,     /*Load in on OpenResFile?*/
    resChanged = 2,     /*Resource changed?*/
    mapReadOnly = 128,  /*Resource file read-only*/
    mapCompact = 64,    /*Compact resource file*/
    mapChanged = 32,    /*Write map out at updat*/

/* Values for setting RomMapInsert and TmpResLoad */
    mapTrue = 0xFFFF,   /*insert ROM map w/ TmpResLoad = TRUE.*/
    mapFalse = 0xFF00   /*insert ROM map w/ TmpResLoad = FALSE.*/
};

#ifdef __cplusplus
extern "C" {
#endif

extern short InitResources(void);
extern void RsrcZoneInit(void);
extern void CloseResFile(short refNum);
extern short ResError(void);
extern short CurResFile(void);
extern short HomeResFile(Handle theResource);
extern void CreateResFile(ConstStr255Param fileName);
extern short OpenResFile(ConstStr255Param fileName);
extern void UseResFile(short refNum);
extern short CountTypes(void);
extern short Count1Types(void);
extern void GetIndType(ResType *theType,short index);
extern void Get1IndType(ResType *theType,short index);
extern void SetResLoad(Boolean load);
extern short CountResources(ResType theType);
extern short Count1Resources(ResType theType);
extern Handle GetIndResource(ResType theType,short index);
extern Handle Get1IndResource(ResType theType,short index);
extern Handle GetResource(ResType theType,short theID);
extern Handle Get1Resource(ResType theType,short theID);
extern Handle GetNamedResource(ResType theType,ConstStr255Param name);
extern Handle Get1NamedResource(ResType theType,ConstStr255Param name);
extern void LoadResource(Handle theResource);
extern void ReleaseResource(Handle theResource);
extern void DetachResource(Handle theResource);
extern short UniqueID(ResType theType);
extern short Unique1ID(ResType theType);
extern short GetResAttrs(Handle theResource);
extern void GetResInfo(Handle theResource,short *theID,ResType *theType, Str255 name);
extern void SetResInfo(Handle theResource,short theID,ConstStr255Param name);
extern void AddResource(Handle theResource,ResType theType,short theID, ConstStr255Param name);
extern long SizeResource(Handle theResource);
extern long MaxSizeRsrc(Handle theResource);
extern long RsrcMapEntry(Handle theResource);
extern void SetResAttrs(Handle theResource,short attrs);
extern void ChangedResource(Handle theResource);
extern void RmveResource(Handle theResource);
extern void UpdateResFile(short refNum);
extern Handle getnamedresource(ResType theType,char *name); 
extern void WriteResource(Handle theResource);
extern void SetResPurge(Boolean install);
extern Handle get1namedresource(ResType theType,char *name); 
extern short GetResFileAttrs(short refNum);
extern void SetResFileAttrs(short refNum,short attrs);
extern short OpenRFPerm(ConstStr255Param fileName,short vRefNum,char permission);
extern Handle RGetResource(ResType theType,short theID);
extern short HOpenResFile(short vRefNum,long dirID,ConstStr255Param fileName,    char permission); 
extern void HCreateResFile(short vRefNum,long dirID,ConstStr255Param fileName); 
extern short FSpOpenResFile(const FSSpec *spec,SignedByte permission);
extern void FSpCreateResFile(const FSSpec *spec,OSType creator,OSType fileType,  ScriptCode scriptTag);
extern void ReadPartialResource(Handle theResource,long offset,void *buffer,  long count);
extern void WritePartialResource(Handle theResource,long offset,const void *buffer, long count);
extern void SetResourceSize(Handle theResource,long newSize);
extern short openrfperm(char *fileName,short vRefNum,char permission); 
extern short openresfile(char *fileName); 
extern void createresfile(char *fileName); 
extern void getresinfo(Handle theResource,short *theID,ResType *theType,char *name); 
extern void setresinfo(Handle theResource,short theID,char *name); 
extern void addresource(Handle theResource,ResType theType,short theID,char *name); 

#ifdef __cplusplus
}
#endif

#endif
