object Form1: TForm1
  Left = 128
  Top = 153
  Width = 995
  Height = 552
  Caption = 'Form1'
  Color = clWindow
  Ctl3D = False
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
    Top = 16
    Width = 92
    Height = 13
    Caption = #1050#1086#1083'-'#1074#1086' '#1101#1083#1077#1084#1077#1085#1090#1086#1074
  end
  object Label2: TLabel
    Left = 16
    Top = 312
    Width = 27
    Height = 13
    Caption = #1060#1048#1054
  end
  object Label3: TLabel
    Left = 16
    Top = 352
    Width = 26
    Height = 13
    Caption = #1050#1083#1102#1095
  end
  object Label4: TLabel
    Left = 400
    Top = 64
    Width = 83
    Height = 13
    Caption = #1055#1086#1083#1086#1078#1080#1090#1077#1083#1100#1085#1099#1077
  end
  object Label5: TLabel
    Left = 592
    Top = 64
    Width = 80
    Height = 13
    Caption = #1054#1090#1088#1080#1094#1072#1090#1077#1083#1100#1085#1099#1077
  end
  object StringGrid1: TStringGrid
    Left = 16
    Top = 64
    Width = 169
    Height = 209
    ColCount = 2
    FixedCols = 0
    RowCount = 8
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
  end
  object Button1: TButton
    Left = 16
    Top = 280
    Width = 169
    Height = 25
    Caption = #1047#1072#1085#1077#1089#1090#1080' '#1076#1072#1085#1085#1099#1077' '#1074' '#1093#1077#1096'-'#1090#1072#1073#1083#1080#1094#1091
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 16
    Top = 32
    Width = 89
    Height = 19
    TabOrder = 2
    Text = 'Edit1'
  end
  object Button2: TButton
    Left = 112
    Top = 32
    Width = 75
    Height = 25
    Caption = #1047#1072#1076#1072#1090#1100
    TabOrder = 3
    OnClick = Button2Click
  end
  object Edit2: TEdit
    Left = 16
    Top = 328
    Width = 129
    Height = 19
    TabOrder = 4
    Text = 'Edit2'
  end
  object Button3: TButton
    Left = 16
    Top = 392
    Width = 129
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1085#1086#1074#1091#1102' '#1079#1072#1087#1080#1089#1100
    TabOrder = 5
    OnClick = Button3Click
  end
  object Edit3: TEdit
    Left = 16
    Top = 368
    Width = 129
    Height = 19
    TabOrder = 6
    Text = 'Edit3'
  end
  object Memo1: TMemo
    Left = 200
    Top = 64
    Width = 185
    Height = 209
    Lines.Strings = (
      'Memo1')
    TabOrder = 7
  end
  object Button4: TButton
    Left = 16
    Top = 488
    Width = 129
    Height = 25
    Caption = #1056#1072#1089#1087#1077#1095#1072#1090#1072#1090#1100
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 16
    Top = 424
    Width = 129
    Height = 25
    Caption = #1063#1090#1077#1085#1080#1077' '#1089' '#1091#1076#1072#1083#1077#1085#1080#1077#1084
    TabOrder = 9
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 16
    Top = 456
    Width = 129
    Height = 25
    Caption = #1063#1090#1077#1085#1080#1077' '#1073#1077#1079' '#1091#1076#1072#1083#1077#1085#1080#1103
    TabOrder = 10
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 200
    Top = 32
    Width = 177
    Height = 25
    Caption = #1056#1072#1089#1087#1077#1095#1072#1090#1072#1090#1100' '#1080' '#1086#1095#1080#1089#1090#1080#1090#1100' '#1090#1072#1073#1083#1080#1094#1091
    TabOrder = 11
    OnClick = Button7Click
  end
  object Memo2: TMemo
    Left = 400
    Top = 88
    Width = 185
    Height = 209
    Lines.Strings = (
      'Memo2')
    TabOrder = 12
  end
  object Memo3: TMemo
    Left = 592
    Top = 88
    Width = 185
    Height = 209
    Lines.Strings = (
      'Memo3')
    TabOrder = 13
  end
  object Button8: TButton
    Left = 456
    Top = 32
    Width = 209
    Height = 25
    Caption = #1055#1086#1083#1086#1078#1080#1090#1077#1083#1100#1085#1099#1077'/'#1086#1090#1088#1080#1094#1072#1090#1077#1083#1100#1085#1099#1077
    TabOrder = 14
    OnClick = Button8Click
  end
end
