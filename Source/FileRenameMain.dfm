object FrmRename: TFrmRename
  Left = 1739
  Top = 58
  Width = 368
  Height = 226
  Caption = 'Rename Files'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Folder: TLabel
    Left = 16
    Top = 8
    Width = 29
    Height = 13
    Caption = 'Folder'
  end
  object File_Pattern: TLabel
    Left = 16
    Top = 40
    Width = 53
    Height = 13
    Caption = 'File Pattern'
  end
  object Root_Folder: TLabel
    Left = 16
    Top = 72
    Width = 55
    Height = 13
    Caption = 'Root Folder'
  end
  object TBFolder_Pattern: TEdit
    Left = 96
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Roll [nn]'
  end
  object TB_FilePattern: TEdit
    Left = 96
    Top = 36
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '*.bmp'
  end
  object TBRootFolder: TEdit
    Left = 96
    Top = 68
    Width = 233
    Height = 21
    TabOrder = 2
    Text = 'D:\Documents\Photos\Canada\Films'
  end
  object pbFileRename: TProgressBar
    Left = 16
    Top = 104
    Width = 313
    Height = 17
    Min = 0
    Max = 100
    TabOrder = 3
  end
  object BitBtn1: TBitBtn
    Left = 16
    Top = 136
    Width = 75
    Height = 25
    TabOrder = 4
    OnClick = BitBtn1Click
    Kind = bkOK
  end
  object BitBtn2: TBitBtn
    Left = 256
    Top = 136
    Width = 75
    Height = 25
    TabOrder = 5
    Kind = bkClose
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 173
    Width = 360
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object FolderSelect: TOpenDialog
    Options = [ofHideReadOnly, ofEnableSizing, ofDontAddToRecent]
    Left = 256
    Top = 8
  end
end
