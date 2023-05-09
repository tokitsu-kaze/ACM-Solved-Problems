#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int n,m,i;
double tmp[1111],a[1111],b[1111],l,r,mid;
bool cmp(double a,double b){return a>b;}
int check(double x)
{
	x/=100.0;
	for(i=0;i<n;i++) tmp[i]=a[i]-b[i]*x;
	sort(tmp,tmp+n,cmp);
	double res=0;
	for(i=0;i<m;i++) res+=tmp[i];
	return res>=0;
}
void go()
{
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		for(i=0;i<n;i++) scanf("%lf",&a[i]);
		for(i=0;i<n;i++) scanf("%lf",&b[i]);
		m=n-m;
		l=0;
		r=1e9;
		while(r-l>eps)
		{
			mid=(l+r)/2;
			if(check(mid)) l=mid;
			else r=mid;
		}
		printf("%.0f\n",l);
	}
}
