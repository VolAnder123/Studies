unit Unit2;
interface
uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, TeEngine, Series, ExtCtrls, TeeProcs, Chart;
Type Fun=Function(x:extended):extended;
Procedure Resh(a,b:extended;n:integer;sx:fun;Chart1:TChart);
implementation
Procedure Resh;
var x,y:extended; i:integer;
begin
 With Chart1 do
 begin
  SeriesList[0].Clear;
  x:=a;
  for i:=1 to n do
    begin
      y:=Sx(x);
      serieslist[0].AddXY(x,y);
      x:=x+(b-a)/n;
    end;
 end;
end;
end.
 