#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
vector<int> pos[MAX];
int a[MAX],cnt[MAX];
int ask(int l,int r,int x)
{
	return upper_bound(pos[x].begin(),pos[x].end(),r)
		  -lower_bound(pos[x].begin(),pos[x].end(),l);
}
int main()
{
	int T,n,i,q,l,r,M;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		M=sqrt(3*n*18);
		d.init();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			d.add(a[i]);
			cnt[i]=0;
			pos[i].clear();
		}
		d.work();
		for(i=1;i<=n;i++)
		{
			a[i]=d.get_pos(a[i]);
			cnt[a[i]]++;
			pos[a[i]].push_back(i);
		}
		vector<int> tmp;
		for(i=1;i<=n;i++)
		{
			if(cnt[i]>=M/3) tmp.push_back(i);
			cnt[i]=0;
		}
		while(q--)
		{
			scanf("%d%d",&l,&r);
			vector<int> res;
			if(r-l+1<=M)
			{
				for(i=l;i<=r;i++)
				{
					cnt[a[i]]++;
					if(cnt[a[i]]==(r-l+1)/3+1) res.push_back(a[i]);
				}
				for(i=l;i<=r;i++) cnt[a[i]]=0;
			}
			else
			{
				for(auto &it:tmp)
				{
					if(ask(l,r,it)>(r-l+1)/3) res.push_back(it);
				}
			}
			if(res.size()==0)
			{
				puts("-1");
				continue;
			}
			sort(res.begin(),res.end());
			i=0;
			for(auto &it:res)
			{
				i++;
				printf("%d%c",(int)d.get_val(it)," \n"[i==res.size()]);
			}
		}
	}
	return 0;
}
/*
M=3n/M * log n
*/
