//---------------------------------------------------------------------------

#ifndef PathExtractH
#define PathExtractH

class TPathExtract : public TObject
{

public:
        __fastcall TPathExtract(AnsiString fullPath);
private:
        int TPathCount;
        AnsiString * PathParts
        AnsiString TFullPath;
        AnsiString TFileName;
};
//---------------------------------------------------------------------------
#endif
 