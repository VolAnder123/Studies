unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, TeEngine, Series, ExtCtrls, TeeProcs, Chart, StdCtrls, Buttons, Unit2;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Chart1: TChart;
    Series1: TLineSeries;
    BitBtn1: TBitBtn;
    Series2: TLineSeries;
    procedure FormCreate(Sender: TObject);
    procedure BitBtn1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;
var
  Form1: TForm1;


   function Divc(x,y:Complex):Complex;

implementation

 	  function Divc;
		var z:extended;
		begin
		  z:=sqr(y.re)+sqr(y.im);
		  Divc.re:=(x.re*y.re+x.im*y.im)/z;
		  Divc.im:=(x.im*y.re-x.re*y.im)/z;
		end;

{$R *.dfm}

function myfc(x:extended):complex;
 var a,b:complex;
 begin
  a.re:=2; a.im:=x;
  b.re:=sqr(x); b.im:=-2;
  result:=Divc(a,b);
end;


procedure TForm1.FormCreate(Sender: TObject);
begin
Edit1.Clear;
Edit2.Clear;
Edit3.Clear;
end;

procedure TForm1.BitBtn1Click(Sender: TObject);
var a,b,n:integer;
begin
a:=StrToInt(Edit1.Text);
b:=StrToInt(Edit2.Text);
n:=StrToInt(Edit3.Text);
Tabf(a,b,n,myfc,cHart1);
end;

end.
