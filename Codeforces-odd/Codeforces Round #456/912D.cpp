#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int n,m,r,k,dir[4][2]={0,1,1,0,0,-1,-1,0};
map<PII,int> mp;
double ans;
struct node
{
	int x,y;
	ll v;
	node(){}
	node(int _x,int _y,ll _v):x(_x),y(_y),v(_v){}
	friend bool operator<(node a,node b)
	{
		return a.v<b.v;
	}
};
ll cal(int x,int y)
{
	return 1LL*(min(x,n-r+1)-max(1,x-r+1)+1)*(min(y,m-r+1)-max(1,y-r+1)+1);
}
bool check(int x,int y)
{
	if(x<1||y<1||x>n||y>m||mp.count(MP(x,y))) return 0;
	return 1;
}
void bfs()
{
	int i;
	node t,next;
	priority_queue<node> q;
	mp.clear();
	q.push(node(r,r,cal(r,r)));
	mp[MP(r,r)]=1;
	while(k--)
	{
		t=q.top();
		q.pop();
		ans+=t.v;
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y))
			{
				mp[MP(next.x,next.y)]=1;
				next.v=cal(next.x,next.y);
				q.push(next);
			}
		}
	}
}
int main()
{
	int i,j;
	while(~scanf("%d%d%d%d",&n,&m,&r,&k))
	{
		ans=0;
		bfs();
		ans/=1LL*(n-r+1)*(m-r+1);
		printf("%.9lf\n",ans);
	}
	return 0;
}