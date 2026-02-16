#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
int main()
{
	int n,m,i,j,now,ans;
	char s[MAX],t[MAX];
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	scanf("%s",t+1);
	ans=INF;
	for(i=1;i+m-1<=n;i++)
	{
		now=0;
		for(j=i;j<=i+m-1;j++)
		{
			if(s[j]>=t[j-i+1]) now+=s[j]-t[j-i+1];
			else now+=s[j]-'0'+10-(t[j-i+1]-'0');
		}
		ans=min(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}
