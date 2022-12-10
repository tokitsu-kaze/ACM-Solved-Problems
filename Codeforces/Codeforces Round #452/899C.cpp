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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,l,r,res,s,pos,now;
	while(~scanf("%d",&n))
	{
		l=1;
		r=n;
		vector<int> ans;
		if((n%4)%2)
		{
			ans.pb(r);
			r--;
			l++;
			r--;
		}
		while(r-l+1>=4)
		{
			ans.pb(l);
			ans.pb(r);
			l++;
			r--;
			l++;
			r--;
		}
		res=INF;
		s=0;
		now=0;
		pos=-1;
		for(i=l;i<=r;i++)
		{
			s+=i;
		}
		for(i=l;i<=r;i++)
		{
			now+=i;
			if(abs(now-(s-now))<res)
			{
				pos=i;
				res=abs(now-(s-now));
			}
		}
		for(i=l;i<=pos;i++) ans.pb(i);
		if(pos==-1) res=0;
		printf("%d\n",res);
		printf("%d",(int)sz(ans));
		for(i=0;i<sz(ans);i++) printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}