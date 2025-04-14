#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int n,k,i,j,cnt,now,cnto;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	cnto=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]!='o') continue;
		if(i-1>=1 && s[i-1]=='?') s[i-1]='.';
		if(i+1<=n && s[i+1]=='?') s[i+1]='.';
		cnto++;
	}
	if(cnto==k)
	{
		for(i=1;i<=n;i++)
		{
			if(s[i]=='?') s[i]='.';
		}
		s[n+1]='\0';
		puts(s+1);
		return 0;
	}
	cnt=now=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='?') now++;
		else
		{
			if(s[i]=='o') cnt++;
			cnt+=(now+1)/2;
			now=0;
		}
	}
	cnt+=(now+1)/2;
	if(cnt==k)
	{
		now=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='?') now++;
			else
			{
				if(now&1)
				{
					for(j=0;j<now;j+=2)
					{
						s[i-now+j]='o';
						if(i-now+j+1<i) s[i-now+j+1]='.';
					}
				}
				now=0;
			}
		}
		if(now&1)
		{
			for(j=0;j<now;j+=2)
			{
				s[n+1-now+j]='o';
				if(n+1-now+j+1<=n) s[n+1-now+j+1]='.';
			}
		}
	}
	s[n+1]='\0';
	puts(s+1);
	return 0;
}
/*
9 4
.???.??.?
5 1
??o.?
*/
