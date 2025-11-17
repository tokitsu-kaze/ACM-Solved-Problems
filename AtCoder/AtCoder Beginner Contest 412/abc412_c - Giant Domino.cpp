#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,now,mx,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		vector<int> res;
		for(i=2;i<n;i++) res.push_back(a[i]);
		sort(res.begin(),res.end());
		reverse(res.begin(),res.end());
		ans=2;
		now=a[1];
		while(now*2<a[n])
		{
			mx=-1;
			while(res.size() && now*2>=res.back())
			{
				mx=max(mx,res.back());
				res.pop_back();
			}
			if(mx==-1)
			{
				ans=-1;
				break;
			}
			if(now*2>=mx)
			{
				ans++;
				now=mx;
			}
			else
			{
				ans=-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
