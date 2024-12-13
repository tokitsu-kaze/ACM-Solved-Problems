#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
char s[MAX];
int main()
{
	int T,n,q,i,x,v,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		cnt=0;
		for(i=4;i<=n;i++)
		{
			if(s[i-3]=='1' &&
			   s[i-2]=='1' &&
			   s[i-1]=='0' &&
			   s[i]=='0') cnt++;
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&x,&v);
			if(s[x]-'0'==v)
			{
				if(cnt>0) puts("YES");
				else puts("NO");
				continue;
			}
			for(i=x;i<=min(n,x+3);i++)
			{
				if(s[i-3]=='1' &&
				   s[i-2]=='1' &&
				   s[i-1]=='0' &&
				   s[i]=='0') cnt--;
			}
			s[x]='0'+v;
			for(i=x;i<=min(n,x+3);i++)
			{
				if(s[i-3]=='1' &&
				   s[i-2]=='1' &&
				   s[i-1]=='0' &&
				   s[i]=='0') cnt++;
			}
			if(cnt>0) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
