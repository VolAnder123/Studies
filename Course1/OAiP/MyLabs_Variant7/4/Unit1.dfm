object Form1: TForm1
  Left = 205
  Top = 132
  Width = 882
  Height = 253
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 24
    Width = 14
    Height = 13
    Caption = 'N='
  end
  object Label2: TLabel
    Left = 16
    Top = 64
    Width = 15
    Height = 13
    Caption = 'M='
  end
  object Edit1: TEdit
    Left = 40
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 40
    Top = 64
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit2'
  end
  object StringGrid1: TStringGrid
    Left = 176
    Top = 24
    Width = 320
    Height = 120
    ColCount = 4
    RowCount = 4
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 2
  end
  object Button1: TButton
    Left = 40
    Top = 104
    Width = 105
    Height = 25
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1088#1072#1079#1084#1077#1088
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 224
    Top = 160
    Width = 75
    Height = 25
    Caption = #1047#1072#1087#1086#1083#1085#1080#1090#1100
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 344
    Top = 160
    Width = 75
    Height = 25
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 5
    OnClick = Button3Click
  end
  object StringGrid2: TStringGrid
    Left = 520
    Top = 24
    Width = 320
    Height = 120
    ColCount = 4
    RowCount = 4
    TabOrder = 6
  end
end