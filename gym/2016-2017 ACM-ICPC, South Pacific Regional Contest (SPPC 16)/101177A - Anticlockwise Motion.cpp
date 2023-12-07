#include <bits/stdc++.h>
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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
PII cal(int m)
{
	int pos=1,i,d,x,y;
	for(i=1;i<=sqrt(1e9);i++)
	{
		if((2*i-1)*(2*i-1)>=m)
		{
			pos=i;
			break;
		}
	}
	int hen=(m-(2*pos-3)*(2*pos-3));
	int maxx=pos-1;
	x=y=-maxx;
	d=0;
	for(i=0;i<hen;i++)
	{
		x+=dir[d][0];
		y+=dir[d][1];
		if(d==0&&x==maxx) d++;
		if(d==1&&y==maxx) d++;
		if(d==2&&x==-maxx) d++;
	}
	return MP(x,y);
};
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		PII p1,p2;
		p1=cal(n);
		p2=cal(m);
		printf("%d\n",abs(p1.fi-p2.fi)+abs(p1.se-p2.se));
	}
	return 0;
}