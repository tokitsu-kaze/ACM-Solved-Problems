#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int res[MAX];
int main()
{
	int T,n,k,i,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		now=0;
		for(i=1;i<n;i++)
		{
			s[i]^=now;
			if(s[i]=='1' && (k&1))
			{
				res[i]=1;
				k--;
				now^=1;
			}
			else if(s[i]=='0' && (!(k&1)) && k>0)
			{
				res[i]=1;
				k--;
				now^=1;
			}
			else res[i]=0;
			s[i]^=(k&1);
		}
		s[n]^=now;
		res[n]=k;
		s[n+1]='\0';
		puts(s+1);
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}
