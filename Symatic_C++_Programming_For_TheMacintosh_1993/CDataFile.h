
#ifndef CDataFile_h
#define CDataFile_h

class CDataFile
{
	public:
		void IDataFile();
		void SFSpecify(SFReply*&);
		void Open( int );
		void Close();
		int GetLength();
		void GetName(Str63 name);
		Handle ReadAll();
};

#endif

