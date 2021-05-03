object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 169
  ClientWidth = 435
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
    Left = 117
    Top = 35
    Width = 3
    Height = 13
    Color = clHotLight
    ParentColor = False
  end
  object Label2: TLabel
    Left = 117
    Top = 58
    Width = 3
    Height = 13
  end
  object calcRPN: TLabel
    Left = 153
    Top = 81
    Width = 3
    Height = 13
  end
  object calcORIGINAL: TLabel
    Left = 169
    Top = 104
    Width = 3
    Height = 13
  end
  object Edit1: TEdit
    Left = 8
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
    TextHint = 'Enter Equation'
    OnChange = Edit1Change
  end
  object Button1: TButton
    Left = 135
    Top = 8
    Width = 75
    Height = 21
    Caption = '1.Parse'
    TabOrder = 1
    OnClick = Button1Click
  end
  object StaticText1: TStaticText
    Left = 8
    Top = 35
    Width = 75
    Height = 17
    Caption = 'Your Equation:'
    TabOrder = 2
  end
  object StaticText2: TStaticText
    Left = 8
    Top = 58
    Width = 103
    Height = 17
    Caption = 'Your Equation(RPN):'
    TabOrder = 3
  end
  object Button2: TButton
    Left = 358
    Top = 143
    Width = 75
    Height = 25
    Caption = '2.Calculate'
    TabOrder = 4
    OnClick = Button2Click
  end
  object aValue: TEdit
    Left = 358
    Top = 8
    Width = 75
    Height = 21
    TabOrder = 5
    TextHint = 'Enter a Value'
  end
  object bValue: TEdit
    Left = 358
    Top = 35
    Width = 75
    Height = 21
    TabOrder = 6
    TextHint = 'Enter b Value'
  end
  object cValue: TEdit
    Left = 358
    Top = 62
    Width = 75
    Height = 21
    TabOrder = 7
    TextHint = 'Enter c Value'
  end
  object dValue: TEdit
    Left = 358
    Top = 89
    Width = 75
    Height = 21
    TabOrder = 8
    TextHint = 'Enter d Value'
  end
  object eValue: TEdit
    Left = 358
    Top = 116
    Width = 75
    Height = 21
    TabOrder = 9
    TextHint = 'Enter e Value'
  end
  object StaticText3: TStaticText
    Left = 8
    Top = 81
    Width = 139
    Height = 17
    Caption = 'Result When Calcalute RPN:'
    TabOrder = 10
  end
  object StaticText4: TStaticText
    Left = 8
    Top = 104
    Width = 155
    Height = 17
    Caption = 'Result When Calculate Original:'
    TabOrder = 11
  end
end
