unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Unit2;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    Edit2: TEdit;
    Label2: TLabel;
    Edit3: TEdit;
    Label3: TLabel;
    SaveDialog1: TSaveDialog;
    Edit4: TEdit;
    Label4: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  a,b,x:Extended;
  n:Integer;
  FileName:String;
  Fl:TextFile;
implementation

{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);
begin
Edit1.Text:='1'; Edit2.Text:='5'; Edit3.Text:='10'; Edit4.Text:='10';
end;

Function Sx(x:extended):extended;
var k:integer; b,s:Extended;
begin
k:=1; s:=0; b:=1;
while k<m do
  begin
    b:=b*x/k;
    S:=S+b;
    k:=k+1;
  end;
Result:=s;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
M:=StrToInt(Edit4.Text); a:=StrToFloat(edit1.Text);
b:=StrToFloat(edit2.Text);
N:=StrToInt(edit3.Text);
If SaveDialog1.Execute then
begin
  FileName:=SaveDialog1.FileName;
  AssignFile(Fl,FileName);
  Rewrite(Fl);
end;
  Resh(a,b,n,Sx,fl);
  closefile(fl);
  ShowMessage('���������� � ���� ���������');
end;

end.
