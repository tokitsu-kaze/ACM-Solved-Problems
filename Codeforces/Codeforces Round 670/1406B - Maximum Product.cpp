#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> a,b;
ll cal(int x,int y)
{
	int i,j;
	ll res=1;
	if(a.size()<x||b.size()<y) return -LLINF;
	if(y&1)
	{
		for(i=0,j=a.size()-1;i<x;i++,j--) res*=a[j];
		for(i=0,j=b.size()-1;i<y;i++,j--) res*=b[j];
	}
	else
	{
		for(i=0;i<x;i++) res*=a[i];
		for(i=0;i<y;i++) res*=b[i];
	}
	return res;
}
int main()
{
	int T,n,i,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		a.clear();
		b.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x>=0) a.push_back(x);
			if(x<=0) b.push_back(x);
		}
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		sort(b.begin(),b.end());
		ans=-LLINF;
		for(i=0;i<=5;i++) ans=max(ans,cal(i,5-i));
		printf("%lld\n",ans);
	}
	return 0;
}
