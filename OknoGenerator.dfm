object OknoGenerator: TOknoGenerator
  Left = 313
  Top = 305
  BorderStyle = bsToolWindow
  Caption = 'Losowanie...'
  ClientHeight = 103
  ClientWidth = 290
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PrzyciskLosuj: TButton
    Left = 8
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Losuj...'
    TabOrder = 0
    OnClick = PrzyciskLosujClick
  end
  object PoleLiczby1: TEdit
    Left = 8
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 1
    Text = 'PoleLiczby1'
  end
  object PoleLiczby2: TEdit
    Left = 56
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 2
    Text = 'PoleLiczby2'
  end
  object PoleLiczby3: TEdit
    Left = 104
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 3
    Text = 'PoleLiczby3'
  end
  object PoleLiczby4: TEdit
    Left = 152
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 4
    Text = 'PoleLiczby4'
  end
  object PoleLiczby5: TEdit
    Left = 200
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 5
    Text = 'PoleLiczby5'
  end
  object PoleLiczby6: TEdit
    Left = 248
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 6
    Text = 'PoleLiczby6'
  end
  object PrzyciskCzasowe: TBitBtn
    Left = 96
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Czasowe...'
    TabOrder = 7
    OnClick = PrzyciskCzasoweClick
  end
  object TimerLosowania: TTimer
    Enabled = False
    Interval = 1
    OnTimer = TimerLosowaniaTimer
    Left = 200
    Top = 64
  end
end
