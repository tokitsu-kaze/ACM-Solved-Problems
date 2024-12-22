#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
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
	int find(type x){return (*lower_bound(all(a),x))==x?1:0;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}dx,dy;
int tx[MAX],ty[MAX];
multiset<ll> xx[MAX],yy[MAX];
int main()
{
	int n,m,i,ans;
	char op[2];
	ll nx,ny,x,y,c;
	scanf("%d%d%lld%lld",&n,&m,&x,&y);
	dx.init();
	dy.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&tx[i],&ty[i]);
		dx.add(tx[i]);
		dy.add(ty[i]);
		xx[i].clear();
		yy[i].clear();
	}
	dx.work();
	dy.work();
	for(i=1;i<=n;i++)
	{
		xx[dy.get_pos(ty[i])].insert(tx[i]);
		yy[dx.get_pos(tx[i])].insert(ty[i]);
	}
	ans=0;
	for(i=1;i<=m;i++)
	{
		nx=x;
		ny=y;
		scanf("%s%lld",op,&c);
		if(op[0]=='U') ny+=c;
		else if(op[0]=='D') ny-=c;
		else if(op[0]=='L') nx-=c;
		else nx+=c;
		vector<ll> del;
		if(x==nx && dx.find(x))
		{
			auto it=yy[dx.get_pos(x)].lower_bound(min(ny,y));
			for(;it!=yy[dx.get_pos(x)].end();it++)
			{
				if(*it>max(ny,y)) break;
				del.push_back(*it);
			}
			ans+=del.size();
			for(auto &it2:del)
			{
				yy[dx.get_pos(x)].erase(yy[dx.get_pos(x)].find(it2));
				xx[dy.get_pos(it2)].erase(xx[dy.get_pos(it2)].find(x));
			}
		}
		else if(dy.find(y))
		{
			auto it=xx[dy.get_pos(y)].lower_bound(min(nx,x));
			vector<int> del;
			for(;it!=xx[dy.get_pos(y)].end();it++)
			{
				if(*it>max(nx,x)) break;
				del.push_back(*it);
			}
			ans+=del.size();
			for(auto &it2:del)
			{
				xx[dy.get_pos(y)].erase(xx[dy.get_pos(y)].find(it2));
				yy[dx.get_pos(it2)].erase(yy[dx.get_pos(it2)].find(y));
			}
		}
		x=nx;
		y=ny;
	}
	printf("%lld %lld %d\n",nx,ny,ans);
	return 0;
}
