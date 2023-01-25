#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=5e5+10;
const ll mod=1e9+7;
/********************************* std-head *********************************/
struct Fenwick_Tree
{
	#define type int
	type bit[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	int lowbit(int x){return x&(-x);}
	void insert(int x,type v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	type get(int x)
	{
		type res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	type ask(int l,int r)
	{
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr;
set<int> sa[4],sb[4];
int n;
int cal()
{
	int l,r,L,R;
	r=*sa[1].lower_bound(1);
	R=*(--sb[2].lower_bound(*sa[2].lower_bound(r-1)));
	l=*(--sa[3].lower_bound(n+1));
	L=*(--sa[2].lower_bound(*sb[2].lower_bound(l+1)))+1;
	r=min(r,R+1)-1;
	l=max(l,L-1)+1;
//	debug(l,r,L,R)
	if(L>R || l>R || r<L) return 0;
	return r+(n-l+1)+(R-L+1-tr.ask(L,R));
}
int main()
{
	int T,k,i,j,a,b;
	scanf("%d",&T);
	while(T--)
	{
	    scanf("%d%d",&n,&k);
		for(i=1;i<=3;i++)
		{
			sb[i].clear();
			sb[i].insert(0);
			sb[i].insert(n+1);
			
			sa[i].clear();
			sa[i].insert(0);
			sa[i].insert(n+1);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				sb[j].insert(i);
			}
		}
		tr.init(n);
		while(k--)
		{
			scanf("%d%d",&a,&b);
			if(sa[b].count(a))
			{
				sa[b].erase(a);
				if(b==2) tr.insert(a,-1);
				sb[b].insert(a);
			}
			else
			{
				sa[b].insert(a);
				if(b==2) tr.insert(a,1);
				sb[b].erase(a);
			}
			printf("%d\n",max(cal()-1,0));
		}
	}
	return 0;
}
