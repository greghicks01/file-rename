//---------------------------------------------------------------------------

#ifndef FileRenameMainH
#define FileRenameMainH
//---------------------------------------------------------------------------

#include "FileSearch.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFrmRename : public TForm
{
__published:	// IDE-managed Components
        TLabel *Folder;
        TLabel *File_Pattern;
        TLabel *Root_Folder;
        TEdit *TBFolder_Pattern;
        TEdit *TB_FilePattern;
        TEdit *TBRootFolder;
        TProgressBar *pbFileRename;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TStatusBar *StatusBar1;
        TOpenDialog *FolderSelect;
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrmRename(TComponent* Owner);
        TFileSearch * filesearch ;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmRename *FrmRename;
//---------------------------------------------------------------------------
#endif
