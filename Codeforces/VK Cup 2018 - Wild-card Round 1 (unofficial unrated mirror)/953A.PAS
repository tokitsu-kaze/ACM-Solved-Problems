var l,r,i,j,ans,now,tmp:int64;
begin
  readln(l,r);
  ans:=0;
  now:=0;
  for i:=1 to 100 do
  begin
    if now=0 then now:=1 else now:=now*2;
    tmp:=now;
    if (tmp>=l) and (tmp<=r) then ans:=ans+1;
    if tmp>r then break;
    for j:=1 to 100 do
    begin
      tmp:=tmp*3;
      if (tmp>=l) and (tmp<=r) then ans:=ans+1;
      if tmp>r then break;
    end;
  end;
  
  writeln(ans);
end.