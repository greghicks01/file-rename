//---------------------------------------------------------------------------

#ifndef fileSearchH
#define fileSearchH

#include <vcl.h>

class TFileSearch : public TObject
{

public:
        __fastcall TFileSearch ( AnsiString RootFolder , AnsiString FolderPattern , AnsiString FilePattern );
        void __fastcall renameFiles ( ) ;
        __property int FileCount  = { read=FFileCount };
private:
        AnsiString FRootFolder ;
        AnsiString FFolderPattern ;
        AnsiString FFilePattern ;
        int FFileCount ;
        static const AnsiString FFolderDelim ;
        AnsiString __fastcall  ExtractPathTail ( AnsiString Path ) ;
        AnsiString __fastcall ExtractSqBrackets ( AnsiString Path ) ;

}  ;

//---------------------------------------------------------------------------
#endif
