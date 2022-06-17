//---------------------------------------------------------------------------


#pragma hdrstop

#include "fileSearch.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

const AnsiString TFileSearch::FFolderDelim = "\\" ;

/* ******
  Purpose:
  Accepts: 
  Returns:
*/
__fastcall TFileSearch::TFileSearch(AnsiString RootFolder , AnsiString FolderPattern , AnsiString FilePattern ):
FRootFolder ( RootFolder ) , FFolderPattern ( FolderPattern ) , FFilePattern ( FilePattern )
{
        //DONE: Count all files that match the Root+FilePattern
        TSearchRec srFolders , srFiles ;

        // folder wraps files
        if ( FindFirst ( FRootFolder + "\\*.*" , faDirectory , srFolders) == 0)
        {

                do
                {
                        if ( srFolders.Name == "." || srFolders.Name == ".." )
                                continue;
                                
                        if ( FindFirst ( FRootFolder + FFolderDelim + srFolders.Name + FFolderDelim + FFilePattern , faAnyFile , srFiles) == 0)
                        {
                                do
                                {
                                        FFileCount ++ ;
                                } while (FindNext(srFiles) == 0) ;

                        }   
                        FindClose(srFiles);
                        
                } while  (FindNext(srFolders) == 0) ;
        }
        FindClose ( srFolders ) ;
}

void __fastcall TFileSearch::renameFiles()
{
        //TODO: Add your source code here
                TSearchRec srFolders , srFiles ;

        // folder wraps files
        if ( FindFirst ( FRootFolder + FFolderDelim + "*.*" , faDirectory , srFolders) == 0)
        {

                do
                {
                        if ( srFolders.Name == "." || srFolders.Name == ".." )
                                continue;

                        if ( FindFirst ( FRootFolder + FFolderDelim + srFolders.Name + FFolderDelim + FFilePattern , faAnyFile , srFiles) == 0)
                        {
                                do
                                {
                                        // rename drive:\\path\\
                                        AnsiString oldName = FRootFolder + FFolderDelim + srFolders.Name + FFolderDelim + srFiles.FindData.cFileName ;
                                        AnsiString tempPath = ExtractPathTail ( ExtractFilePath (oldName) );
                                        AnsiString tempName = ExtractSqBrackets ( tempPath ) ;
                                        AnsiString newName =   FRootFolder + FFolderDelim + tempName +  srFiles.FindData.cFileName ;
                                        RenameFile ( oldName , newName ) ;
                                        //MainFopbFileRename->

                                } while (FindNext(srFiles) == 0) ;

                        }
                        FindClose(srFiles);

                } while  (FindNext(srFolders) == 0) ;
        }
        FindClose ( srFolders ) ;
}

AnsiString __fastcall TFileSearch::ExtractPathTail ( AnsiString Path )
{
        //TODO: Add your source code here return the remaining part of the path
        // C:\data\file return files
        AnsiString temp = ExtractFilePath (Path) ;

        if ( Path.AnsiPos ( FFolderDelim ) != 0 )
        {
                do
                {
                        temp = temp.SubString( temp.AnsiPos ( FFolderDelim ) + 1 , temp.Length() - temp.AnsiPos ( FFolderDelim ) )  ;
                } while  ( temp.AnsiPos ( FFolderDelim ) != temp.Length()  ) ;

                return temp.SubString(1 , temp.Length() -1 ) ;
        }

        return "" ;
}

AnsiString __fastcall TFileSearch::ExtractSqBrackets ( AnsiString subPath )
{
        //TODO: Add your source code here  FFolderPattern
        
        if ( subPath.AnsiPos("Roll") != 0 || subPath.AnsiPos("roll") != 0)
        {
                AnsiString tempPattern = FFolderPattern.SubString( 1 , FFolderPattern.AnsiPos ( "[" ) -1 ) ;
                AnsiString tailPattern = FFolderPattern.SubString ( FFolderPattern.AnsiPos ( "[" ) , FFolderPattern.Length() ) ;

                AnsiString temp = subPath.SubString( tempPattern.AnsiPos("[") + tempPattern.Length () + 1  , 2 ) ;

                return temp ;
        }

}
