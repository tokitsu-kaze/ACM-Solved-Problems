#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
struct node{int t,d;};
int id[MAX],w[MAX],x[MAX],d[MAX],l[MAX],r[MAX];
int main()
{
	int n,L,i,j,t;
	ll tot,now,ans;
	scanf("%d%d",&n,&L);
	vector<node> res;
	tot=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&w[i],&x[i],&d[i]);
		if(d[i]==1) res.push_back({L-x[i],d[i]});
		else res.push_back({x[i],d[i]});
		tot+=w[i];
		id[i]=i;
	}
	sort(id+1,id+1+n,[&](int a,int b){
		return x[a]<x[b];
	});
	sort(res.begin(),res.end(),[](node x,node y){
		return x.t<y.t;
	});
	now=0;
	i=1;
	j=n;
	for(auto &it:res)
	{
		if(it.d==1) now+=w[id[j--]];
		else now+=w[id[i++]];
		if(now*2>=tot)
		{
			t=it.t;
			break;
		}
	}
//	printf("%d\n",t);
	vector<int> tmp;
	map<pair<int,int>,int> mp;
	for(i=1;i<=n;i++)
	{
		if(d[i]==1)
		{
			l[i]=x[i];
			r[i]=min(L,x[i]+t);
		}
		else
		{
			r[i]=x[i];
			l[i]=max(0,x[i]-t);
			tmp.push_back(l[i]);
			tmp.push_back(r[i]);
			mp[{l[i],r[i]}]++;
		}
	}
	sort(tmp.begin(),tmp.end());
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(d[i]==-1) continue;
		ans+=upper_bound(tmp.begin(),tmp.end(),r[i])
			-lower_bound(tmp.begin(),tmp.end(),l[i]);
		if(mp.count({l[i],r[i]})) ans-=mp[{l[i],r[i]}];
	}
	printf("%lld\n",ans);
	return 0;
}
/*
两头牛相遇，从速度的角度上看是直接穿过，但从体重的角度上看是交换体重。
也就是说，体重的相对顺序是不变的。
考虑先算出时间 T，处理出每头牛到达牛棚的时间，根据体重相对顺序不变，能求出时间 T。
然后相当于求有交集的区间个数，但由于速度一样，同方向不可能相遇，所以要分开计算。
只要算一种方向即可，而且由于速度一样，不可能出现包含关系，直接算不会算重。
*/
