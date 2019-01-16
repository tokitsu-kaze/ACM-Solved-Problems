n,c1,c2=map(int,raw_input().split())
s=raw_input()
cnt=0
for i in range(0,len(s)):
	if s[i]=='1':
		cnt=cnt+1;
ans=2**61
for i in range(1,cnt+1):
	tmp=n//i
	now=c1*i+c2*(tmp-1)*(tmp-1)*(i-n%i)+tmp*tmp*c2*(n%i)
	ans=min(ans,now)
print ans