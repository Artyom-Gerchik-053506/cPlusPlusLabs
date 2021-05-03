object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'shipGame'
  ClientHeight = 250
  ClientWidth = 500
  Color = clGradientInactiveCaption
  CustomTitleBar.CaptionAlignment = taCenter
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 421
    Top = 0
    Width = 75
    Height = 25
    Caption = 'spawnShip'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 471
    Top = 222
    Width = 25
    Height = 25
    Caption = #8594
    TabOrder = 1
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 409
    Top = 222
    Width = 25
    Height = 25
    Caption = #8592
    TabOrder = 2
    OnClick = Button4Click
  end
  object Button2: TButton
    Left = 440
    Top = 222
    Width = 25
    Height = 25
    Caption = #8595
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button5: TButton
    Left = 440
    Top = 191
    Width = 25
    Height = 25
    Caption = #8593
    TabOrder = 4
    OnClick = Button5Click
  end
end
