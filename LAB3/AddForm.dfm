object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'AddForm'
  ClientHeight = 294
  ClientWidth = 563
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 56
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 0
    TextHint = 'Name'
  end
  object Edit2: TEdit
    Left = 56
    Top = 59
    Width = 121
    Height = 21
    Hint = 'City'
    TabOrder = 1
    TextHint = 'City'
  end
  object Edit3: TEdit
    Left = 56
    Top = 86
    Width = 121
    Height = 21
    Hint = 'Mark1'
    NumbersOnly = True
    TabOrder = 2
    TextHint = 'Mark1'
  end
  object Edit4: TEdit
    Left = 56
    Top = 113
    Width = 121
    Height = 21
    Hint = 'Mark2'
    NumbersOnly = True
    TabOrder = 3
    TextHint = 'Mark2'
  end
  object Edit5: TEdit
    Left = 56
    Top = 140
    Width = 121
    Height = 21
    Hint = 'Mark3'
    NumbersOnly = True
    TabOrder = 4
    TextHint = 'Mark3'
  end
  object Button1: TButton
    Left = 480
    Top = 230
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 480
    Top = 261
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 6
    OnClick = Button2Click
  end
end
