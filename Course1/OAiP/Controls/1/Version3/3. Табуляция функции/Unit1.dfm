object Form1: TForm1
  Left = 263
  Top = 204
  Width = 439
  Height = 187
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
    Top = 32
    Width = 7
    Height = 13
    Caption = 'A'
  end
  object Label2: TLabel
    Left = 16
    Top = 64
    Width = 7
    Height = 13
    Caption = 'B'
  end
  object Label3: TLabel
    Left = 224
    Top = 32
    Width = 8
    Height = 13
    Caption = 'N'
  end
  object Label4: TLabel
    Left = 224
    Top = 64
    Width = 9
    Height = 13
    Caption = 'M'
  end
  object Button1: TButton
    Left = 160
    Top = 96
    Width = 97
    Height = 25
    Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 56
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 56
    Top = 64
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 256
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 256
    Top = 64
    Width = 121
    Height = 21
    TabOrder = 4
    Text = 'Edit4'
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.Txt'
    Filter = #1058#1077#1082#1089#1090#1086#1074#1099#1081' '#1092#1072#1081#1083'|*.txt|'#1042#1089#1077' '#1092#1072#1081#1083#1099'|*.*'
    Left = 384
    Top = 32
  end
end
