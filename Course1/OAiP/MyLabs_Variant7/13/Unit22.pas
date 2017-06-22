unit Unit22;

interface

uses Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Buttons, StdCtrls, ComCtrls;

Type
  TSport = record
    country:string[20];
    team:string[20];
    fio:string[20];
    number,age,weight,growth:word;
  end;
  TSaS = class (TObject)
    LInf,SInf:file of TSport;
    TInf:textfile;
    s:set of byte;
    MSport:array[1..15] of TSport;
    FileNameS,FileNameL:string;
    num,n,j:word;
    procedure PCreate(SaveDialog1: TSaveDialog);
    procedure POpen(OpenDialog1:TOpenDialog; Memo1: tmemo);
    procedure PSave(SaveDialog1,SaveDialog2: TSaveDialog);
    procedure PAdd(Edit1,Edit2,Edit3,Edit4,Edit5,Edit6,Edit7:TEdit;Memo1:TMemo);
    procedure PLineSearch(key:integer);
    procedure PQuickSort;
    function PDelete(key:integer):integer;
    function PYoungTeam:integer;
    procedure PSortSlip;
    function PDSearch(key:integer):word;
  end;
  var
    k:integer;
implementation

procedure TSaS.PCreate;
  begin
    if SaveDialog1.Execute then
      begin
        FileNameL:=SaveDialog1.FileName;
        AssignFile(LInf,FileNameL);
        Rewrite(LInf);
     end;
  end;

procedure TSaS.POpen;
  begin
    if OpenDialog1.Execute then
   begin
    FileNameL:=OpenDialog1.FileName;
    AssignFile(LInf,FileNameL);
    Reset(LInf);
  end;
  num:=0;
  while not eof(LInf) do
    begin
      Inc(num);
      Read(LInf,MSport[num]);
      with MSport[num] do
         Memo1.Lines.Add(IntToStr(num)+') ������: '+country+', �������: '+team+
         ', �������: '+fio+', �����: '+IntToStr(number)+', ������� '
         +IntToStr(age)+', ���� '+IntToStr(growth)+', ��� '+IntToStr(weight));
    end;
    j:=num;
  end;
procedure TSaS.PSave;
var
  i:word;
begin
  if SaveDialog1.Execute then
    begin
      FileNameS:=SaveDialog1.FileName;
      AssignFile(SInf,FileNameS);
      Rewrite(SInf);
    end;
  for i:=1 to num do
    write(SInf,MSport[i]);
  CloseFile(SInf);
  if SaveDialog2.Execute then
    begin
      FileNameS:=SaveDialog2.FileName;
      AssignFile(TInf,FileNameS);
      Rewrite(TInf);
    end;
  for i:=1 to num do
    with MSport[i] do writeln(Tinf,i:4,'.','������: '+country+', �������: '+team+
         ', �������: '+fio+' �����: '+IntToStr(number)+'�������'+IntToStr(age)+
         ' ����'+IntToStr(growth)+'���'+IntToStr(weight));
  CloseFile(TInf);
end;

procedure TSaS.PAdd;
begin
  num:=num+1;
  with MSport[num] do
    begin
      country:=Edit1.Text;
      team:=Edit2.Text;
      fio:=Edit3.Text;
      number:=StrToInt(Edit4.Text);
      age:=StrToInt(Edit5.Text);
      growth:=StrToInt(Edit6.Text);
      weight:=StrToInt(Edit7.Text);
      Memo1.Lines.Add(IntToStr(num)+') ������: '+country+', �������: '+team+
         ', �������: '+fio+', �����: '+IntToStr(number)+', ������� '+IntToStr(age)+
         ', ���� '+IntToStr(growth)+', ��� '+IntToStr(weight));
    end;
end;

procedure TSaS.PLineSearch;//�������� �����
  var i:byte;
  begin
    s:=[];
    for i:=1 to num do
      if MSport[i].age=k then include(s,i);
  end;


procedure TSaS.PQuickSort; //quicksort
  procedure sort(l,ra:integer);
  var
    i,j:byte;
    x:integer;
    r:TSport;
  begin
    i:=l;
    j:=ra;
    x:=MSport[(L+Ra) div 2].age;
    repeat
      while MSport[i].age<x do
        i:=i+1;
      while x<MSport[j].age do
        j:=j-1;
      if i<=j then
        begin
          r:=MSport[i];
          MSport[i]:=MSport[j];
          MSport[j]:=r;
          i:=i+1;
          j:=j-1;
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<ra then sort(i,ra);
    end;
begin
  sort(1,j);
end;

function tsas.pdsearch(key:integer):word; //�������� �����
  var i:word;
    function Del(L,R:word):word;
    var m:word;
    begin
      if R<=L then Del:=R
      else begin
            m:=(L+R) div 2;
            if MSport[m].age<key then Del:=Del(m+1,R)
                                else Del:=Del(L,m); end;
    end;
    begin  i:=del(1,j);
     if MSport[i].age=key then Result:=i
    else result:=0;
end;

function Tsas.PDelete;
var i,k:integer;
begin
k:=0;
for i:=1 to num do
  if MSport[i].age<>key then begin
    inc(k);
    MSport[k]:=MSport[i];
  end;
  j:=k;
Result:=j;
end;

function Tsas.PYoungTeam;
var i,min,j:integer;
begin
  min:=MSport[1].age; j:=1;
  for i:=2 to num do
    if MSport[i].age<min then begin
      j:=i;
      min:=MSport[j].age;
    end;
  Result:=j;
end;

Procedure tsas.PSortSlip; //SortSlip
  Procedure slip(l,spl,r:integer);
    var i,j,k:Integer; tmp:array[1..1000] of TSport;
  begin
    i:=L;  j:=Spl+1;  k:=1;
    while (i<=Spl) and (j<=r) do begin
      if MSport[i].age>MSport[j].age then begin
        tmp[k]:=MSport[j];
        Inc(j);
      end
      else begin
        tmp[k]:=MSport[i];
        Inc(i);
      end;
      Inc(k);
    end;
    if i<=Spl then
      for j:=i to Spl do begin
        tmp[k]:=MSport[j];
        Inc(k);
      end
    else
      for i:=j to R do begin
        tmp[k]:=MSport[i];
        Inc(k);
      end;
    for i:=1 to k-1 do begin
      MSport[l+i-1]:=tmp[i];
    end;
  end;

  procedure srsl(L,R:word);
    var Spl:integer;
  begin
    if l>=r then exit;
    spl:=(l+r) div 2;
    srsl(l,spl);
    srsl(spl+1,r);
    slip(l,spl,r);
  end;

begin
  srsl(1,j);
end;
end.
