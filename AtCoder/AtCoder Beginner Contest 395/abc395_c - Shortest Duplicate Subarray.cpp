#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=1e6+10;
int lst[MAX];
int main()
{
	int n,i,x,ans;
	scanf("%d",&n);
	memset(lst,0,sizeof lst);
	ans=INF;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(lst[x]) ans=min(ans,i-lst[x]+1);
		lst[x]=i;
	}
	if(ans==INF) ans=-1;
	printf("%d\n",ans);
	return 0;
}
