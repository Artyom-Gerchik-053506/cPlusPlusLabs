object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Editing Form'
  ClientHeight = 294
  ClientWidth = 563
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
    Left = 8
    Top = 11
    Width = 65
    Height = 13
    Caption = 'Type Of Disk:'
  end
  object Label2: TLabel
    Left = 8
    Top = 39
    Width = 102
    Height = 13
    Caption = 'Type Of Information:'
  end
  object Label3: TLabel
    Left = 8
    Top = 65
    Width = 27
    Height = 13
    Caption = 'Price:'
  end
  object Label4: TLabel
    Left = 8
    Top = 89
    Width = 31
    Height = 13
    Caption = 'Name:'
  end
  object Label5: TLabel
    Left = 8
    Top = 116
    Width = 37
    Height = 13
    Caption = 'Author:'
  end
  object Label6: TLabel
    Left = 8
    Top = 143
    Width = 27
    Height = 13
    Caption = 'Note:'
  end
  object Edit1: TEdit
    Left = 116
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
    TextHint = 'Enter Type'
  end
  object Button1: TButton
    Left = 480
    Top = 261
    Width = 75
    Height = 25
    Caption = 'Apply'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 116
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 2
    TextHint = 'Enter Type Of Info'
  end
  object Edit3: TEdit
    Left = 116
    Top = 59
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 3
    TextHint = 'Enter Price'
  end
  object Edit4: TEdit
    Left = 116
    Top = 86
    Width = 121
    Height = 21
    TabOrder = 4
    TextHint = 'Enter Name'
  end
  object Edit5: TEdit
    Left = 116
    Top = 113
    Width = 121
    Height = 21
    TabOrder = 5
    TextHint = 'Enter Author'
  end
  object Edit6: TEdit
    Left = 116
    Top = 140
    Width = 121
    Height = 21
    TabOrder = 6
    TextHint = 'Enter Note'
  end
end
