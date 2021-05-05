object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 312
  ClientWidth = 563
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StringGrid1: TStringGrid
    Left = 0
    Top = 0
    Width = 131
    Height = 185
    ColCount = 2
    FixedCols = 0
    RowCount = 7
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    ScrollBars = ssNone
    TabOrder = 0
  end
  object TreeView1: TTreeView
    Left = 320
    Top = 0
    Width = 241
    Height = 304
    Indent = 19
    TabOrder = 1
  end
  object Button1: TButton
    Left = 0
    Top = 191
    Width = 75
    Height = 25
    Caption = 'performTree'
    TabOrder = 2
    OnClick = Button1Click
  end
  object StaticText1: TStaticText
    Left = 137
    Top = 8
    Width = 30
    Height = 17
    Caption = 'Text:'
    TabOrder = 3
  end
  object StaticText2: TStaticText
    Left = 137
    Top = 31
    Width = 26
    Height = 17
    Caption = 'Key:'
    TabOrder = 4
  end
  object Edit1: TEdit
    Left = 173
    Top = 8
    Width = 36
    Height = 21
    TabOrder = 5
  end
  object Edit2: TEdit
    Left = 173
    Top = 31
    Width = 36
    Height = 21
    NumbersOnly = True
    TabOrder = 6
  end
  object Button2: TButton
    Left = 137
    Top = 54
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 239
    Top = 279
    Width = 75
    Height = 25
    Caption = 'expandTree'
    TabOrder = 8
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 239
    Top = 248
    Width = 75
    Height = 25
    Caption = 'preOrder'
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 239
    Top = 217
    Width = 75
    Height = 25
    Caption = 'inOrder'
    TabOrder = 10
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 239
    Top = 186
    Width = 75
    Height = 25
    Caption = 'postOrder'
    TabOrder = 11
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 137
    Top = 85
    Width = 75
    Height = 25
    Caption = 'searchByKey'
    TabOrder = 12
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 137
    Top = 116
    Width = 75
    Height = 25
    Caption = 'deleteByKey'
    TabOrder = 13
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 0
    Top = 279
    Width = 75
    Height = 25
    Caption = 'performTask'
    TabOrder = 14
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 81
    Top = 279
    Width = 75
    Height = 25
    Caption = 'balanceTree'
    TabOrder = 15
    OnClick = Button10Click
  end
end
