#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
vector<int> mp[MAX];
int a[MAX];
int main()
{
	int T,n,x,i,ans,sum,now,mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		d.init();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			d.add(a[i]);
			d.add(1LL*a[i]*x);
		}
		d.work();
		for(i=1;i<=2*n;i++) mp[i].clear();
		for(i=1;i<=n;i++)
		{
			mp[d.get_pos(a[i])].push_back(1);
			if(x>1) mp[d.get_pos(1LL*a[i]*x)].push_back(-1);
		}
		ans=0;
		for(i=1;i<=2*n;i++)
		{
			sum=now=0;
			mx=-1e9;
			for(auto &it:mp[i])
			{
				if(it==1) now++;
				sum=max(0,sum-it);
				mx=max(mx,sum);
			}
			ans=max(ans,mx+now);
		}
		printf("%d\n",ans);
	}
	return 0;
}
