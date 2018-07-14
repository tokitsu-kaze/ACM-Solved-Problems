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
const int MAX=1e3+10;
const ll mod=1e9+7;
int main()
{
	int ans,x,h,m,now,l,r,f,i,j,tag;
	while(~scanf("%d%d%d",&x,&h,&m))
	{
		r=now=m+h*60;
		j=0;
		while(1)
		{
			h=now/60;
			m=now%60;
			f=0;
	//		cout<<h<<" "<<m<<endl;
			while(h)
			{
				if(h%10==7) f=1;
				h/=10;
			}
			while(m)
			{
				if(m%10==7) f=1;
				m/=10;
			}
			if(f&&j%x==0)
			{
				l=now;
				break;
			}
			now--;
			j++;
			if(now==-1) now+=24*60,r+=24*60;
		}
		printf("%d\n",j/x);
	}
	return 0;
}