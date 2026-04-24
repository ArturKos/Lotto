object OknoGlowne: TOknoGlowne
  Left = 125
  Top = 172
  Width = 792
  Height = 480
  Caption = 'Lotto'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCanResize = FormCanResize
  OnCreate = FormCreate
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object WykresLosowan: TPaintBox
    Left = 0
    Top = 29
    Width = 784
    Height = 339
    Align = alClient
    OnMouseMove = WykresLosowanMouseMove
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 415
    Width = 784
    Height = 19
    Panels = <
      item
        Text = 'asas'
        Width = 200
      end>
    SimplePanel = False
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 784
    Height = 29
    Caption = 'ToolBar1'
    TabOrder = 1
  end
  object PanelNajczestszych: TPanel
    Left = 0
    Top = 368
    Width = 784
    Height = 47
    Align = alBottom
    Color = clInfoBk
    TabOrder = 2
    OnClick = PanelNajczestszychClick
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 161
      Height = 13
      Caption = 'Najcz'#281#347'ciej pojawiaj'#261'ce si'#281' liczby:'
    end
    object EtykietaRanking: TLabel
      Left = 8
      Top = 24
      Width = 32
      Height = 13
      Caption = 'Label2'
    end
  end
  object MainMenu1: TMainMenu
    Left = 232
    Top = 40
    object MenuStatystyka: TMenuItem
      Caption = 'Statystyka'
      object MenuDodajWynik: TMenuItem
        Caption = 'Dodaj ...'
        OnClick = MenuDodajWynikClick
      end
    end
    object MenuLosowanie: TMenuItem
      Caption = 'Losowanie'
      OnClick = MenuLosowanieClick
    end
  end
end
