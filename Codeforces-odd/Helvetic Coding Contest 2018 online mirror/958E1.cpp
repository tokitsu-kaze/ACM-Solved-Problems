#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const int MAX=2e5+10;
const ll mod=1e9+7;
struct Point
{  
	ll x,y;
	Point(){}
	Point(ll a,ll b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		scanf("%lld%lld",&x,&y);
	}
}a[22],b[22];
typedef Point Vector;
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);} 
ll cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
bool JudgeSegInter(Point a,Point b,Point c,Point d)
{
	ll t1,t2,t3,t4;
	t1=cross(b-a,c-a);
	t2=cross(b-a,d-a);
	t3=cross(d-c,a-c);
	t4=cross(d-c,b-c);
	return t1*t2<0&&t3*t4<0;
}
int flag[22],n,m,tag;
void dfs(int x)
{
	int i,j;
	if(x==n+1)
	{
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(JudgeSegInter(a[flag[i]],b[i],a[flag[j]],b[j])) return;
			}
		}
		tag=1;
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(flag[i]) continue;
		flag[i]=x;
		dfs(x+1);
		flag[i]=0;
	}
}
int main()
{
	int i;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) a[i].input();
		for(i=1;i<=m;i++) b[i].input();
		if(n!=m)
		{
			puts("No");
			continue;
		}
		mem(flag,0);
		tag=0;
		dfs(1);
		tag?puts("Yes"):puts("No");
	}
	return 0;
}