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
int check(int x,int n)
{
	if(x<1||x>n) return 1;
	return 0;
}
int main()
{
	int i,j,q,x[6],y[6],k,xx,yy,flag,n,m;
	char op[11];
	while(~scanf("%d%d",&n,&m))
	{
		x[0]=y[0]=0;
		x[1]=y[1]=0;
		xx=yy=0;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%s",op);
			if(op[0]=='C') xx--;
			else if(op[0]=='D') yy--;
			else if(op[0]=='B') xx++;
			else yy++;
			x[0]=min(x[0],xx);
			y[0]=min(y[0],yy);
			x[1]=max(x[1],xx);
			y[1]=max(y[1],yy);
		}
		vector<PII > res;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				flag=0;
				flag|=check(i+xx,n);
				flag|=check(j+yy,m);
				flag|=check(i+xx-x[0],n);
				flag|=check(i+xx-x[1],n);
				flag|=check(j+yy-y[0],m);
				flag|=check(j+yy-y[1],m);
				if(!flag) res.pb(MP(i,j));
			}
		}
		printf("%d\n",sz(res));
		for(i=0;i<sz(res);i++)
		{
			printf("%d %d\n",res[i].fi,res[i].se);
		}
	}
	return 0;
}