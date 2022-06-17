//---------------------------------------------------------------------------


#pragma hdrstop

#include "PathExtract.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


__fastcall TPathExtract::TPathExtract(AnsiString fullPath)
{
        //TODO: extract the path into the individual parts
        TFullPath = ExtractFilePath ( fullPath ) ;
        TFileName = ExtractFileName ( fullPath ) ;
}