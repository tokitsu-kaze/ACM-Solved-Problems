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
const int MAX=2e5+10;
const ll mod=1e9+7;
int main()
{
	map<string,PDD > mp;
	mp["UFS2.0"]=MP(2,3);
	mp["UFS2.1"]=MP(3,5);
	mp["eMMC5.1"]=MP(5,2);
	mp["LPDDR3"]=MP(4,7);
	mp["LPDDR4"]=MP(6,3);
	mp["Sparse"]=MP(7,4);
	mp["Normal"]=MP(3,6);
	int i,j,n,t;
	double a,b;
	char s[111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		a=b=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%s",s);
				a+=log10(mp[s].fi);
				b+=log10(mp[s].se);
			}
		}
		if(fabs(a-b)<eps) puts("E");
		else if(a<b) puts("B");
		else puts("A");
	}
	return 0;
}