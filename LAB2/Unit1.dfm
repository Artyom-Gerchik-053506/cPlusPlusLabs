object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Main Form'
  ClientHeight = 473
  ClientWidth = 908
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 90
    Top = 299
    Width = 3
    Height = 13
  end
  object Button1: TButton
    Left = 89
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Save'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 1
    Top = 93
    Width = 400
    Height = 200
    ReadOnly = True
    TabOrder = 1
  end
  object Button2: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Open'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 140
    Top = 313
    Width = 71
    Height = 21
    Caption = 'Edit'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 109
    Top = 313
    Width = 25
    Height = 21
    NumbersOnly = True
    TabOrder = 4
  end
  object StaticText1: TStaticText
    Left = 8
    Top = 317
    Width = 95
    Height = 17
    Caption = 'Disk to edit/delete:'
    TabOrder = 5
  end
  object StaticText2: TStaticText
    Left = 8
    Top = 299
    Width = 76
    Height = 17
    Caption = 'Count of disks:'
    TabOrder = 6
  end
  object Button4: TButton
    Left = 8
    Top = 340
    Width = 283
    Height = 21
    Caption = 'AddDisk'
    TabOrder = 7
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 217
    Top = 313
    Width = 75
    Height = 21
    Caption = 'DeleteDisk'
    TabOrder = 8
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 145
    Top = 62
    Width = 131
    Height = 25
    Caption = 'Sort By Type And Author'
    TabOrder = 9
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 8
    Top = 62
    Width = 131
    Height = 25
    Caption = 'Sort By Type And Name'
    TabOrder = 10
    OnClick = Button7Click
  end
  object SearchField: TEdit
    Left = 566
    Top = 8
    Width = 206
    Height = 21
    TabOrder = 11
    TextHint = 'Enter Here:'
  end
  object Memo2: TMemo
    Left = 566
    Top = 89
    Width = 305
    Height = 200
    TabOrder = 12
  end
  object Button8: TButton
    Left = 778
    Top = 8
    Width = 93
    Height = 25
    Caption = 'Search By Author'
    TabOrder = 13
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 778
    Top = 33
    Width = 93
    Height = 25
    Caption = 'Search By Name'
    TabOrder = 14
    OnClick = Button9Click
  end
  object ComboBox1: TComboBox
    Left = 566
    Top = 35
    Width = 145
    Height = 21
    TabOrder = 15
    TextHint = 'Author'
    OnSelect = onSelect
  end
  object ComboBox2: TComboBox
    Left = 566
    Top = 62
    Width = 145
    Height = 21
    Hint = 'Type Of Disk'
    TabOrder = 16
    TextHint = 'Type Of Disk'
    OnSelect = onSelectSecond
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Top = 440
  end
  object FileSaveDialog1: TFileSaveDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 32
    Top = 440
  end
end
