#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
vector<int> res[MAX];
void init(int n)
{
	int i,j,mx;
	for(i=1;i<=n;i++) res[i].clear();
	mx=0;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i) res[j].push_back(i);
		mx=max(mx,(int)res[i].size());
	}
//	cout<<mx<<endl;
}
vector<int> pos[MAX];
int a[MAX];
int main()
{
	int T,n,q,i,k,l,r,mn,p,pre;
	ll ans;
	init(1e5);
	for(i=0;i<MAX;i++) pos[i].clear();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			pos[a[i]].push_back(i);
		}
		while(q--)
		{
			scanf("%d%d%d",&k,&l,&r);
			ans=0;
			pre=l;
			while(1)
			{
				mn=INF;
				for(auto &it:res[k])
				{
					p=lower_bound(pos[it].begin(),pos[it].end(),l)-pos[it].begin();
					if(p==pos[it].size()) continue;
					mn=min(mn,pos[it][p]);
				}
				if(mn>r) break;
				ans+=1LL*(mn-pre)*k;
				pre=mn;
				while(k%a[mn]==0) k/=a[mn];
			}
			ans+=1LL*(r-pre+1)*k;
			printf("%lld\n",ans);
		}
		for(i=1;i<=n;i++) pos[a[i]].clear();
	}
	return 0;
}

