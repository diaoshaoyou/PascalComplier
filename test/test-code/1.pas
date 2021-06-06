program main;
VAR
    i: integer;
begin
    i := 1 * 3 + sqr(10) - 4 div 2;
    writeln(i);
    
    if i < 100 then writeln('i < 100')
    else writeln('i >= 100');

    i:=1;
    while i<10 do begin
        write(i);
        i := i + 1;
    end;
    writeln;
end.
