object Form4: TForm4
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
  object Button1: TButton
    Left = 8
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Losuj...'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 56
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 2
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 104
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 3
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 152
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 4
    Text = 'Edit4'
  end
  object Edit5: TEdit
    Left = 200
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 5
    Text = 'Edit5'
  end
  object Edit6: TEdit
    Left = 248
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 6
    Text = 'Edit6'
  end
  object BitBtn1: TBitBtn
    Left = 96
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Czasowe...'
    TabOrder = 7
    OnClick = BitBtn1Click
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer1Timer
    Left = 200
    Top = 64
  end
end
