unit Unit2;
interface
uses SysUtils, StdCtrls;
procedure alg(n,i,k,y: integer;st:string; Edit1:TEdit; Edit2:TEdit);
implementation
  procedure alg;
  begin
  st:=Edit1.Text;
  n:=Length(st);
  k:=0;
  for i:=1 to n do begin
  if (st[i]<>' ') and ((st[i]='1') or (st[i]='0')) then begin k:=k+1;
  if k>y then y:=k; end
   else  k:=0;
  end;
  Edit2.Text:= inttostr(y);
  end;
end.