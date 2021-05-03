object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
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
  object intForQueue: TEdit
    Left = 0
    Top = 28
    Width = 57
    Height = 21
    NumbersOnly = True
    TabOrder = 0
    TextHint = 'insert int'
  end
  object push: TButton
    Left = 0
    Top = 59
    Width = 57
    Height = 25
    Caption = 'PUSH'
    TabOrder = 1
    OnClick = pushClick
  end
  object pop: TButton
    Left = 63
    Top = 59
    Width = 57
    Height = 25
    Caption = 'POP'
    TabOrder = 2
    OnClick = popClick
  end
  object size: TButton
    Left = 0
    Top = 90
    Width = 57
    Height = 25
    Caption = 'SIZE'
    TabOrder = 3
    OnClick = sizeClick
  end
  object isEmpty: TButton
    Left = 33
    Top = 121
    Width = 57
    Height = 25
    Caption = 'IS EMPTY'
    TabOrder = 4
    OnClick = isEmptyClick
  end
  object StaticText1: TStaticText
    Left = 40
    Top = 5
    Width = 42
    Height = 17
    Caption = 'QUEUE:'
    TabOrder = 5
  end
  object ListBox1: TListBox
    Left = 63
    Top = 28
    Width = 57
    Height = 25
    ItemHeight = 13
    TabOrder = 6
  end
  object peek: TButton
    Left = 63
    Top = 90
    Width = 57
    Height = 25
    Caption = 'PEEK'
    TabOrder = 7
    OnClick = peekClick
  end
  object test: TEdit
    Left = 399
    Top = 28
    Width = 75
    Height = 21
    TabOrder = 8
    TextHint = 'insert int'
  end
  object Button1: TButton
    Left = 399
    Top = 59
    Width = 75
    Height = 25
    Caption = 'push_left'
    TabOrder = 9
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 480
    Top = 59
    Width = 75
    Height = 25
    Caption = 'push_right'
    TabOrder = 10
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 399
    Top = 90
    Width = 75
    Height = 25
    Caption = 'pop_left'
    TabOrder = 11
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 480
    Top = 90
    Width = 75
    Height = 25
    Caption = 'pop_right'
    TabOrder = 12
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 399
    Top = 152
    Width = 75
    Height = 25
    Caption = 'isEmpty'
    TabOrder = 13
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 480
    Top = 152
    Width = 75
    Height = 25
    Caption = 'size'
    TabOrder = 14
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 399
    Top = 121
    Width = 75
    Height = 25
    Caption = 'peek_left'
    TabOrder = 15
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 480
    Top = 121
    Width = 75
    Height = 25
    Caption = 'peek_right'
    TabOrder = 16
    OnClick = Button8Click
  end
  object ListBox2: TListBox
    Left = 480
    Top = 28
    Width = 75
    Height = 25
    ItemHeight = 13
    TabOrder = 17
  end
  object StaticText2: TStaticText
    Left = 455
    Top = 5
    Width = 42
    Height = 17
    Caption = 'DEQUE:'
    TabOrder = 18
  end
  object Button9: TButton
    Left = 440
    Top = 183
    Width = 75
    Height = 25
    Caption = 'performTask'
    TabOrder = 19
    OnClick = Button9Click
  end
end
