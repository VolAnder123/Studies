object Form1: TForm1
  Left = 150
  Top = 168
  Width = 547
  Height = 318
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 184
    Top = 72
    Width = 56
    Height = 13
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090':'
  end
  object StringGrid1: TStringGrid
    Left = 16
    Top = 8
    Width = 145
    Height = 265
    ColCount = 2
    FixedCols = 0
    RowCount = 9
    TabOrder = 0
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24
      24)
  end
  object Edit1: TEdit
    Left = 176
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 176
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 248
    Top = 72
    Width = 49
    Height = 21
    TabOrder = 3
    Text = 'Edit3'
  end
  object BitButton1: TBitBtn
    Left = 312
    Top = 8
    Width = 201
    Height = 25
    Caption = '&'#1055#1077#1088#1077#1074#1077#1089#1090#1080' '#1074' '#1087#1086#1089#1090#1092#1080#1082#1089#1085#1091#1102' '#1092#1086#1088#1084#1091
    TabOrder = 4
    OnClick = BitButton1Click
    Kind = bkYes
  end
  object BitButton2: TBitBtn
    Left = 312
    Top = 40
    Width = 105
    Height = 25
    Caption = '&'#1056#1072#1089#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 5
    OnClick = BitButton2Click
    Kind = bkYes
  end
  object BitButton3: TBitBtn
    Left = 208
    Top = 128
    Width = 75
    Height = 25
    Caption = '&'#1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 6
    OnClick = BitButton3Click
    Kind = bkAbort
  end
  object BitButton4: TBitBtn
    Left = 440
    Top = 128
    Width = 75
    Height = 25
    TabOrder = 7
    Kind = bkClose
  end
end
