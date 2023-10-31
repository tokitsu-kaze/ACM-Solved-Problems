#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
long long a[MAXN],need,sum,n;
int T,anser[MAXN];
char s[MAXN];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		scanf("%s",s+1);
		sum=(n+1)*n/2;
		if(sum&1)
		{
			printf("-1\n");
			continue;
		}
		need=sum/2;
		for(int i=n;i;--i)
		{
			if(i<=need)
			{
				need-=i;
				s[i]=(s[i]-'0')*2+'1';
			}
			else s[i]=(s[i]-'0'+1)*2+'0';
		}
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}