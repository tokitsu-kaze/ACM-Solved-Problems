#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],pre[MAX],suf[MAX];
int main()
{
	int n,i,x,ans,mn,now;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=0;
	for(x=0;x<=30;x++)
	{
		vector<int> tmp;
		now=0;
		tmp.push_back(now);
		mn=INF;
		for(i=1;i<=n;i++)
		{
			now+=a[i];
			if(a[i]>x)
			{
				tmp.clear();
				mn=INF;
			}
			else if(a[i]==x)
			{
				for(auto &it:tmp) mn=min(mn,it);
				tmp.clear();
			}
			if(mn!=INF) ans=max(ans,now-mn-x);
			tmp.push_back(now);
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
枚举最大值，然后套用 2121F - Yamakasi 的做法
*/
