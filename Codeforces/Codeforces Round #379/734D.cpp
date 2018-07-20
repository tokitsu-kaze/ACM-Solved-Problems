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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=5e5+10;
const ll mod=1e9+7;
map<pair<int,int>,pair<ll,ll> > mp;
int dir[8][2]={0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};
int main()
{
	ll n,x,y,i,a,b,flag;
	char c[11];
	while(~scanf("%lld",&n))
	{
		scanf("%lld%lld",&x,&y);
		mp.clear();
		for(i=0;i<8;i++)
		{
			mp[MP(dir[i][0],dir[i][1])]=MP((ll)8e18+10,-1);
		}
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			if(c[0]=='R') flag=0;
			else if(c[0]=='B') flag=1;
			else flag=2;
			scanf("%lld%lld",&a,&b);
			if(a==x)
			{
				if(mp[MP(0,(b-y)/abs(b-y))].fi>(b-y)*(b-y))
				{
					mp[MP(0,(b-y)/abs(b-y))]=MP((b-y)*(b-y),flag);
				}
			}
			else if(b==y)
			{
				if(mp[MP((a-x)/abs(a-x),0)].fi>(a-x)*(a-x))
				{
					mp[MP((a-x)/abs(a-x),0)]=MP((a-x)*(a-x),flag);
				}
			}
			else if(abs(a-x)==abs(b-y))
			{
				if(mp[MP((a-x)/abs(a-x),(b-y)/abs(b-y))].fi>(a-x)*(a-x)+(b-y)*(b-y))
				{
					mp[MP((a-x)/abs(a-x),(b-y)/abs(b-y))]=MP((a-x)*(a-x)+(b-y)*(b-y),flag);
				}
			}
		}
		flag=0;
		for(i=0;i<4;i++)
		{
			if(mp[MP(dir[i][0],dir[i][1])].se==0||mp[MP(dir[i][0],dir[i][1])].se==2) flag=1;
		}
		for(i=4;i<8;i++)
		{
			if(mp[MP(dir[i][0],dir[i][1])].se==1||mp[MP(dir[i][0],dir[i][1])].se==2) flag=1;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}