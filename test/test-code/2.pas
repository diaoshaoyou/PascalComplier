program main;
var
  a, b, c : integer;
  d, e : Real;
  f: boolean;

function gcd(a:integer ; b:integer): integer;
  begin
    if b=0 then
      gcd:=a
    else 
      gcd:=gcd(b,a mod b);
  end;

begin
  a:=27;
  b:=12;
  c:=gcd(a,b);
  writeln('gcd=',c);
end.

