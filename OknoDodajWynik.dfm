object OknoDodajWynik: TOknoDodajWynik
  Left = 442
  Top = 151
  Width = 420
  Height = 181
  ActiveControl = PoleLiczby1
  BorderIcons = []
  Caption = 'Dodaj losowanie'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnCanResize = FormCanResize
  PixelsPerInch = 96
  TextHeight = 13
  object PrzyciskOk: TSpeedButton
    Left = 112
    Top = 112
    Width = 65
    Height = 22
    Caption = 'Ok'
    OnClick = PrzyciskOkClick
  end
  object PrzyciskAnuluj: TSpeedButton
    Left = 248
    Top = 112
    Width = 57
    Height = 22
    Caption = 'Anuluj'
    OnClick = PrzyciskAnulujClick
  end
  object PoleLiczby1: TCSpinEdit
    Left = 24
    Top = 40
    Width = 49
    Height = 22
    MaxValue = 49
    MinValue = 1
    TabOrder = 0
  end
  object PoleLiczby2: TCSpinEdit
    Left = 80
    Top = 40
    Width = 49
    Height = 22
    MaxValue = 49
    MinValue = 1
    TabOrder = 1
  end
  object PoleLiczby3: TCSpinEdit
    Left = 144
    Top = 40
    Width = 49
    Height = 22
    MaxValue = 49
    MinValue = 1
    TabOrder = 2
  end
  object PoleLiczby4: TCSpinEdit
    Left = 208
    Top = 40
    Width = 49
    Height = 22
    MaxValue = 49
    MinValue = 1
    TabOrder = 3
  end
  object PoleLiczby5: TCSpinEdit
    Left = 264
    Top = 40
    Width = 49
    Height = 22
    MaxValue = 49
    MinValue = 1
    TabOrder = 4
  end
  object PoleLiczby6: TCSpinEdit
    Left = 328
    Top = 40
    Width = 49
    Height = 22
    MaxValue = 49
    MinValue = 1
    TabOrder = 5
  end
end
