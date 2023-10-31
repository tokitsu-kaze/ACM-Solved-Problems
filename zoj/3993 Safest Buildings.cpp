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
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
vector<int> ans;
int main()
{
	int t,i,n,x[111],y[111];
	double R,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lf%lf",&n,&R,&r);
		ans.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			if(sgn(2*r+(R-sqrt(x[i]*x[i]+y[i]*y[i]))-2*R)>=0) ans.pb(i);
		}
		if((int)sz(ans));
		else
		{
			double minn=INF;
			for(i=1;i<=n;i++)
			{
				minn=min(minn,max(2*r-(R-sqrt(x[i]*x[i]+y[i]*y[i])),0.0));
			}
			for(i=1;i<=n;i++)
			{
				if(sgn(max(2*r-(R-sqrt(x[i]*x[i]+y[i]*y[i])),0.0)-minn)==0) ans.pb(i);
			}
		}
		printf("%d\n",(int)sz(ans));
		if((int)sz(ans))
		{
			printf("%d",ans[0]);
			for(i=1;i<sz(ans);i++) printf(" %d",ans[i]);
			puts("");
		}
	}
	return 0;
}
