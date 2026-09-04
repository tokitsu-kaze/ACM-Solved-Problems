#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int l[MAX],ans[MAX];
ll sum[MAX];
int main()
{
	int n,m,i,lst,ok,mn,mx;
	scanf("%d%d",&n,&m);
	sum[0]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&l[i]);
		sum[i]=sum[i-1]+l[i];
	}
	if(m-1>n-l[m]) return 0*puts("-1");
	ok=1;
	lst=n;
	for(i=m;i;i--)
	{
		mn=max(1,lst-l[i]+1);
		mx=min({sum[i-1]+1,1LL*lst,n-l[i]+1LL});
//		printf("%d %d %d\n",i,mn,mx);
		if(mn>mx)
		{
			ok=0;
			break;
		}
		ans[i]=mx;
		lst=ans[i]-1;
	}
	if(ok)
	{
		for(i=1;i<=m;i++) printf("%d%c",ans[i]," \n"[i==m]);
	}
	else puts("-1");
	return 0;
}
/*
颜色是覆盖的，考虑倒着填。
维护没有颜色的最大位置 lst，对于第 i 次操作，填的区间为
- pos+l-1>=lst
- pos<=lst
- pos<=sum[i-1]+1
- pos>=1
- pos<=n-l+1
解得：max(1,lst-l+1)<=pos<=min({sum[i-1],lst,n-l+1})
能填的话就填最右端点。
*/
