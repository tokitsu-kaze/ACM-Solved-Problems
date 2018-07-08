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
const int MAX=3e5+10;
const ll mod=1e9+7;

int top;
PII s[MAX];
int main()
{
	int n,i,t,pre,x,temp;
	while(~scanf("%d",&n))
	{
		
		top=pre=0;
		vector<pair<PII,int> > ans;
		for(i=1;i<=n+1;i++)
		{
			if(i<=n) scanf("%d",&x);
			else x=0;
			temp=x-pre;
			if(temp>0) s[top++]=MP(i,temp);
			else
			{
				while(temp<0)
				{
					PII p=s[--top];
					if(abs(temp)<p.se)
					{
						ans.pb(MP(MP(p.fi,i-1),abs(temp)));
						temp+=p.se;
						p.se=temp;
						s[top++]=p;
						temp=0;
					}
					else
					{
						ans.pb(MP(MP(p.fi,i-1),p.se));
						temp+=p.se;
					}
				}
			}
			pre=x;
		}
		printf("%d\n",sz(ans));
	//	for(i=0;i<sz(ans);i++) printf("%d %d %d\n",ans[i].fi.fi,ans[i].fi.se,ans[i].se);
	}
	return 0;
}
/*
10
4
3 4 2 1
+3 +1 -2 -1 -1

2 2 0 0
3 3 1 0
3 4 2 1


*/