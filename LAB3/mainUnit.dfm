object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 510
  ClientWidth = 840
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
    Left = 8
    Top = 8
    Width = 450
    Height = 257
    ColCount = 10
    RowCount = 10
    TabOrder = 0
  end
  object Button2: TButton
    Left = 8
    Top = 280
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button1: TButton
    Left = 757
    Top = 8
    Width = 75
    Height = 25
    Caption = 'UpdateUI'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 464
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 3
    TextHint = 'Enter Name Here'
    OnChange = Edit1Change
  end
  object Button3: TButton
    Left = 591
    Top = 8
    Width = 106
    Height = 21
    Caption = 'Search By Name'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Edit2: TEdit
    Left = 464
    Top = 35
    Width = 121
    Height = 21
    TabOrder = 5
    TextHint = 'Enter City Here'
    OnChange = Edit2Change
  end
  object Button4: TButton
    Left = 591
    Top = 35
    Width = 106
    Height = 21
    Caption = 'Search By City'
    TabOrder = 6
    OnClick = Button4Click
  end
  object Edit3: TEdit
    Left = 464
    Top = 62
    Width = 121
    Height = 21
    TabOrder = 7
    TextHint = 'Enter AvgMark Here'
    OnChange = Edit3Change
  end
  object Button5: TButton
    Left = 591
    Top = 62
    Width = 106
    Height = 21
    Caption = 'Search By AvgMark'
    TabOrder = 8
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 703
    Top = 62
    Width = 106
    Height = 21
    Caption = 'Set Minimal AvgMark'
    TabOrder = 9
    OnClick = Button6Click
  end
end
