object Form3: TForm3
  Left = 144
  Top = 156
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'Dane statystyki'
  ClientHeight = 401
  ClientWidth = 718
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
  object SpeedButton1: TSpeedButton
    Left = 336
    Top = 360
    Width = 73
    Height = 22
    Caption = 'OK'
    OnClick = SpeedButton1Click
  end
  object Label1: TLabel
    Left = 16
    Top = 24
    Width = 122
    Height = 13
    Caption = 'Liczby wed'#322'ug kolejno'#347'ci:'
  end
  object Label2: TLabel
    Left = 200
    Top = 24
    Width = 119
    Height = 13
    Caption = 'Liczby wed'#322'ug cz'#281'sto'#347'ci:'
  end
  object Label3: TLabel
    Left = 584
    Top = 24
    Width = 78
    Height = 13
    Caption = 'Wykaz losowa'#324':'
  end
  object Label4: TLabel
    Left = 392
    Top = 24
    Width = 111
    Height = 13
    Caption = 'Liczba powtarza si'#281' co:'
  end
  object v1: TValueListEditor
    Left = 16
    Top = 40
    Width = 177
    Height = 300
    Strings.Strings = (
      '=')
    TabOrder = 0
    TitleCaptions.Strings = (
      'Liczba'
      'Powt'#243'rzy'#322'a si'#281' razy')
    ColWidths = (
      51
      120)
  end
  object v2: TValueListEditor
    Left = 200
    Top = 40
    Width = 177
    Height = 300
    Strings.Strings = (
      '=')
    TabOrder = 1
    TitleCaptions.Strings = (
      'Liczba'
      'Powt'#243'rzy'#322'a si'#281' razy')
    ColWidths = (
      51
      120)
  end
  object ListBox1: TListBox
    Left = 584
    Top = 40
    Width = 113
    Height = 297
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clTeal
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    TabOrder = 2
  end
  object v3: TValueListEditor
    Left = 392
    Top = 40
    Width = 177
    Height = 300
    Strings.Strings = (
      '=')
    TabOrder = 3
    TitleCaptions.Strings = (
      'Liczba'
      'losowania')
    ColWidths = (
      51
      120)
  end
end
