#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
char s[MAX];
int main()
{
	int T,n,i,pos;
	char now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		pos=-1;
		for(i=1;i<n;i++)
		{
			if(s[i]>s[i+1])
			{
				pos=i;
				break;
			}
		}
		if(pos==-1)
		{
			puts(s+1);
			s[n+1]='\0';
			continue;
		}
		now=s[pos];
		for(i=pos;i<n;i++)
		{
			s[i]=s[i+1];
			if(now<s[i])
			{
				s[i]=now;
				now=0;
				break;
			}
		}
		if(now>0) s[n]=now;
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
