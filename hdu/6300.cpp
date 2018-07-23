#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=4e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
struct Point
{ 
	int id;
	double x,y,ang;
	Point(){}
	Point(double a,double b)
	{
		x=a;
		y=b;
	}
	void input(int _id)
	{
		id=_id;
		scanf("%lf%lf",&x,&y);
		ang=atan2(y,x);
	}
}p[11111];
bool operator <(Point a,Point b){return a.ang<b.ang;}
int main()
{
	int n,i,j,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=3*n;i++) p[i].input(i);
		sort(p+1,p+1+3*n);
		for(i=1;i<=n;i++)
		{
			printf("%d %d %d\n",p[(i-1)*3+1].id,p[(i-1)*3+2].id,p[i*3].id);
		}
	}
	return 0;
}
