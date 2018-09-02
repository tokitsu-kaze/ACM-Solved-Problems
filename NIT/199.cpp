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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-3;
const int MAX=2e5+10;
const ll mod=1e9+7;
int a[MAX],n;
double cal(double x)
{
	int i;
	double now,res;
	res=0;
	now=0;
	for(i=0;i<n;i++)
	{
		now+=a[i]-x;
		if(now<0) now=0;
		res=max(res,now);
	}
	now=0;
	for(i=0;i<n;i++)
	{
		now+=a[i]-x;
		if(now>0) now=0;
		res=max(res,-now);
	}
	return res;
}
int main()
{
	int i;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		double l,r,lm,rm,tl,tr;
		l=-10000;
		r=10000;
		while(r-l>eps)  
		{  
			rm=(l+r)/2;  
			lm=(rm+r)/2;
			tl=cal(lm);
			tr=cal(rm);
			if(tr<=tl) r=lm;
			else l=rm;
		}
		printf("%.2lf\n",cal(l));
	}
	return 0;
}