var n,ans:int64;
begin
  readln(n);
  if n mod 2=1 then write(7);
  if n mod 2=1 then n:=n-3;
  while n>0 do
  begin
    write(1);
    n:=n-2;
  end
end.