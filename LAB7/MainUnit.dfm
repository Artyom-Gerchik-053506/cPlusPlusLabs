object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 647
  ClientWidth = 1222
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 101
    Top = 62
    Width = 3
    Height = 13
  end
  object Label2: TLabel
    Left = 88
    Top = 85
    Width = 22
    Height = 13
  end
  object Label3: TLabel
    Left = 60
    Top = 108
    Width = 75
    Height = 11
  end
  object Label4: TLabel
    Left = 96
    Top = 131
    Width = 68
    Height = 13
  end
  object Button1: TButton
    Left = 135
    Top = 8
    Width = 75
    Height = 25
    Caption = 'AddElement'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 216
    Top = 8
    Width = 998
    Height = 631
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object Edit2: TEdit
    Left = 8
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 2
    TextHint = 'PASSWORD'
  end
  object Edit3: TEdit
    Left = 8
    Top = 35
    Width = 121
    Height = 21
    TabOrder = 3
    TextHint = 'DESCRIPTION'
  end
  object StaticText1: TStaticText
    Left = 8
    Top = 62
    Width = 87
    Height = 17
    Caption = 'ElementsInTable:'
    TabOrder = 4
  end
  object StaticText2: TStaticText
    Left = 8
    Top = 85
    Width = 74
    Height = 17
    Caption = 'SumOfAllKeys:'
    TabOrder = 5
  end
  object StaticText3: TStaticText
    Left = 8
    Top = 108
    Width = 46
    Height = 17
    Caption = 'AVGKey:'
    TabOrder = 6
  end
  object StaticText4: TStaticText
    Left = 8
    Top = 131
    Width = 82
    Height = 17
    Caption = 'BiggerThanAVG:'
    TabOrder = 7
  end
  object Button2: TButton
    Left = 135
    Top = 39
    Width = 75
    Height = 25
    Caption = 'DeleteElement'
    TabOrder = 8
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 135
    Top = 70
    Width = 75
    Height = 25
    Caption = 'SearchElement'
    TabOrder = 9
    OnClick = Button3Click
  end
end
