object Form1: TForm1
  Left = 408
  Top = 252
  Width = 508
  Height = 273
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
    Left = 32
    Top = 40
    Width = 13
    Height = 13
    Caption = 'X0'
  end
  object Label2: TLabel
    Left = 32
    Top = 72
    Width = 13
    Height = 13
    Caption = 'X1'
  end
  object Label3: TLabel
    Left = 256
    Top = 40
    Width = 7
    Height = 13
    Caption = 'A'
  end
  object Label4: TLabel
    Left = 216
    Top = 72
    Width = 47
    Height = 13
    Caption = #1058#1086#1095#1085#1086#1089#1090#1100
  end
  object Memo1: TMemo
    Left = 16
    Top = 120
    Width = 465
    Height = 65
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 56
    Top = 40
    Width = 105
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 56
    Top = 72
    Width = 105
    Height = 21
    TabOrder = 2
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 288
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 288
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 4
    Text = 'Edit4'
  end
  object Button1: TButton
    Left = 192
    Top = 200
    Width = 105
    Height = 25
    Caption = #1042#1099#1095#1080#1089#1083#1080#1090#1100
    TabOrder = 5
    OnClick = Button1Click
  end
end
