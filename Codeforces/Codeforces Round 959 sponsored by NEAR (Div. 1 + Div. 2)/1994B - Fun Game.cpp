#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX],t[MAX];
int main()
{
	int T,n,i,pa,pb,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		pa=pb=-1;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='1' && pa==-1) pa=i;
			if(t[i]=='1' && pb==-1) pb=i;
		}
		ok=1;
		if(pa==-1 && pb!=-1) ok=0;
		if(pb!=-1 && pb<pa) ok=0;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
