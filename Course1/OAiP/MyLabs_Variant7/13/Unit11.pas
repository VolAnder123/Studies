unit Unit11;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, Unit22, Menus;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    Label1: TLabel;
    Edit2: TEdit;
    Label2: TLabel;
    Edit3: TEdit;
    Label3: TLabel;
    Edit4: TEdit;
    Label4: TLabel;
    BitBtn1: TBitBtn;
    Memo1: TMemo;
    SaveDialog1: TSaveDialog;
    SaveDialog2: TSaveDialog;
    OpenDialog1: TOpenDialog;
    BitBtn3: TBitBtn;
    BitBtn2: TBitBtn;
    BitBtn5: TBitBtn;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Edit5: TEdit;
    Edit6: TEdit;
    Edit7: TEdit;
    MainMenu1: TMainMenu;
    N1: TMenuItem;
    N2: TMenuItem;
    N3: TMenuItem;
    N4: TMenuItem;
    N5: TMenuItem;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    procedure FormCreate(Sender: TObject);
    procedure BitBtn1Click(Sender: TObject);
    procedure BitBtn3Click(Sender: TObject);
    procedure BitBtn2Click(Sender: TObject);
    procedure BitBtn5Click(Sender: TObject);
    procedure N2Click(Sender: TObject);
    procedure N3Click(Sender: TObject);
    procedure N4Click(Sender: TObject);
    procedure N5Click(Sender: TObject);
    procedure Edit1Click(Sender: TObject);
    procedure Edit2Click(Sender: TObject);
    procedure Edit3Click(Sender: TObject);
    procedure Edit4Click(Sender: TObject);
    procedure Edit5Click(Sender: TObject);
    procedure Edit6Click(Sender: TObject);
    procedure Edit7Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  SaS: TSaS;
  j:integer;
  
implementation

{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);
begin
  Edit1.Clear; Edit2.Clear; Edit3.Clear; Edit4.Clear;
  Edit5.Clear; Edit6.Clear; Edit7.Clear;
  Memo1.Clear;
  SaS:=TSaS.Create;
  sas.num:=0;
end;

procedure TForm1.BitBtn1Click(Sender: TObject);
begin
  SaS.PAdd(Edit1,Edit2,Edit3,Edit4,Edit5,Edit6,Edit7,Memo1);
end;

procedure TForm1.BitBtn3Click(Sender: TObject); //�������� �����
var i:integer; num:integer;
begin
  Memo1.Clear;  num:=1;
  k:=StrToInt(Edit5.Text);
  SaS.PLineSearch(k);
  if sas.s=[] then memo1.Lines.Add('����� �� ��� �����������') else begin
    for i:=1 to sas.num do
      if i in sas.s then begin
        with sas.MSport[i] do
          Memo1.Lines.Add(inttostr(num)+')'+'������: '+country+', �������: '
          +team+', �������: '+fio+', �����: '+IntToStr(number)+', ������� '
          +IntToStr(age)+', ���� '+IntToStr(growth)+', ��� '+IntToStr(weight));
        inc(num);
      end;
  end;
end;

procedure TForm1.BitBtn2Click(Sender: TObject);  //QuickSort
var i,num:word;
begin
  num:=0;
  SaS.PQuickSort;
  memo1.Clear;
  for i:=1 to sas.j do
    with sas.MSport[i] do begin
      inc(num);
      Memo1.Lines.Add(IntToStr(num)+') ������: '+country+', �������: '+team+
      ', �������: '+fio+', �����: '+IntToStr(number)+', �������: '+IntToStr(age)+
      ', ����: '+IntToStr(growth)+', ���: '+IntToStr(weight));
    end;
  end;


procedure TForm1.BitBtn5Click(Sender: TObject);
var a1,num:integer;
begin
  Memo1.Clear; num:=0;
  a1:=StrToInt(edit5.text);
  with sas.MSport[SaS.PDSearch(a1)] do begin
    if number<>0 then begin
      inc(num);
      Memo1.Lines.Add(IntToStr(num)+')������: '+country+', �������: '+team+
        ', �������: '+fio+', �����: '+IntToStr(number)+', �������: '+IntToStr(age)+
        ', ����: '+IntToStr(growth)+', ���:'+IntToStr(weight));
    end else Memo1.Lines.Add('����� �� ��� �����������');
  end;
end;

procedure TForm1.N2Click(Sender: TObject); //��������
begin
  SaS.PCreate(SaveDialog1);
end;

procedure TForm1.N3Click(Sender: TObject);//��������
begin
    Memo1.clear;
    SaS.POpen(OpenDialog1,Memo1);
end;

procedure TForm1.N4Click(Sender: TObject);//����������
begin
  SaS.PSave(SaveDialog1,SaveDialog2);
end;

procedure TForm1.N5Click(Sender: TObject);
begin
  Form1.Close;
end;

procedure TForm1.Edit1Click(Sender: TObject);
begin
  Edit1.Clear;
end;

procedure TForm1.Edit2Click(Sender: TObject);
begin
  Edit2.Clear;
end;

procedure TForm1.Edit3Click(Sender: TObject);
begin
  Edit3.Clear;
end;

procedure TForm1.Edit4Click(Sender: TObject);
begin
  Edit4.Clear;
end;

procedure TForm1.Edit5Click(Sender: TObject);
begin
  Edit5.Clear;
end;

procedure TForm1.Edit6Click(Sender: TObject);
begin
  Edit6.Clear;
end;

procedure TForm1.Edit7Click(Sender: TObject);
begin
  Edit7.Clear;
end;

procedure TForm1.Button3Click(Sender: TObject);
var a2,num,i:integer;
begin
  Memo1.Clear; num:=0;
  a2:=StrToInt(edit5.text);
  j:=Sas.PDelete(a2);
  for i:=1 to j do begin
    with sas.MSport[i] do begin
      inc(num);
      Memo1.Lines.Add(IntToStr(num)+')������: '+country+', �������: '+team+
      ', �������: '+fio+', �����: '+IntToStr(number)+', �������: '+IntToStr(age)+
      ', ����: '+IntToStr(growth)+', ���:'+IntToStr(weight));
  end;
  end;
end;
procedure TForm1.Button2Click(Sender: TObject);
var i,num:integer;
begin
  Memo1.Clear;
  i:=Sas.PYoungTeam; num:=1;
  with sas.MSport[i] do
      Memo1.Lines.Add(IntToStr(num)+')������: '+country+', �������: '+team+
      ', �������: '+fio+', �����: '+IntToStr(number)+', �������: '+IntToStr(age)+
      ', ����: '+IntToStr(growth)+', ���:'+IntToStr(weight));
end;

procedure TForm1.Button1Click(Sender: TObject); //SortSlip
var i,num:integer;
begin
  memo1.Clear;
  sas.PSortSlip; num:=0;
  for i:=1 to sas.j do begin
    with sas.MSport[i] do begin
      inc(num);
      Memo1.Lines.Add(IntToStr(num)+')������: '+country+', �������: '+team+
      ', �������: '+fio+', �����: '+IntToStr(number)+', �������: '+IntToStr(age)+
      ', ����: '+IntToStr(growth)+', ���:'+IntToStr(weight));
  end;
end;
end;
end.