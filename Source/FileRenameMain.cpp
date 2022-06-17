//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FileRenameMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmRename *FrmRename;
//---------------------------------------------------------------------------
__fastcall TFrmRename::TFrmRename(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmRename::BitBtn1Click(TObject *Sender)
{
        filesearch  = new TFileSearch ( TBRootFolder->Text , TBFolder_Pattern->Text , TB_FilePattern->Text ) ;

        StatusBar1->SimpleText = String ( filesearch->FileCount  ) ;
        filesearch->renameFiles() ;
        delete filesearch ;   
}
//---------------------------------------------------------------------------

