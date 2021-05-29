object Form1: TForm1
  Left = 1260
  Top = 203
  BorderStyle = bsDialog
  Caption = 'Next1'
  ClientHeight = 130
  ClientWidth = 177
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefaultPosOnly
  PixelsPerInch = 96
  TextHeight = 13
  object SpeedButton1: TSpeedButton
    Left = 128
    Top = 8
    Width = 41
    Height = 35
    Caption = '&Calc'
    Flat = True
    OnClick = SpeedButton1Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 24
    Width = 33
    Height = 21
    BevelInner = bvLowered
    BevelKind = bkSoft
    BevelOuter = bvRaised
    BorderStyle = bsNone
    ImeName = 'Microsoft IME 2003'
    TabOrder = 3
    OnChange = SpeedButton1Click
    OnKeyPress = EditIntKeyPress
  end
  object Edit2: TEdit
    Left = 49
    Top = 24
    Width = 33
    Height = 21
    BevelInner = bvLowered
    BevelKind = bkSoft
    BevelOuter = bvRaised
    BorderStyle = bsNone
    ImeName = 'Microsoft IME 2003'
    TabOrder = 4
    OnChange = SpeedButton1Click
    OnKeyPress = EditIntKeyPress
  end
  object Edit3: TEdit
    Left = 89
    Top = 24
    Width = 33
    Height = 21
    BevelInner = bvLowered
    BevelKind = bkSoft
    BevelOuter = bvRaised
    BorderStyle = bsNone
    ImeName = 'Microsoft IME 2003'
    TabOrder = 5
    OnChange = SpeedButton1Click
    OnKeyPress = EditIntKeyPress
  end
  object Panel3: TPanel
    Left = 89
    Top = 8
    Width = 33
    Height = 17
    Caption = 'n'
    TabOrder = 2
  end
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 33
    Height = 17
    Caption = 'p'
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 49
    Top = 8
    Width = 33
    Height = 17
    Caption = 'q'
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 8
    Top = 48
    Width = 161
    Height = 73
    TabStop = False
    BevelInner = bvLowered
    BevelKind = bkSoft
    BevelOuter = bvRaised
    BorderStyle = bsNone
    Color = clMoneyGreen
    ImeName = 'Microsoft IME 2003'
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 6
  end
end
