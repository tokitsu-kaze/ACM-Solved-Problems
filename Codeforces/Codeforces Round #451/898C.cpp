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
const int MAX=2e5+10;
const ll mod=1e9+7;
bool check(string a,string b)
{
	int len,i;
	len=min(a.length(),b.length());
	for(i=0;i<len;i++)
	{
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}
int main()
{
	int n,now,id,m,i,j,k,cnt,pos[22];
	char s[111];
	while(~scanf("%d",&n))
	{
		map<string,int> mp1;
		map<int,string> mp2;
		vector<string> res[22];
		vector<string> ans[22];
		now=0;
		while(n--)
		{
			scanf("%s",s);
			if(!mp1[s])
			{
				mp1[s]=++now;
			}
			id=mp1[s];
			mp2[id]=s;
			scanf("%d",&m);
			while(m--)
			{
				scanf("%s",s);
				reverse(s,s+strlen(s));
				res[id].pb(s);
			}
		}
		cnt=0;
		for(i=1;i<=now;i++)
		{
			int flag=0;
			sort(all(res[i]));
			for(j=0;j<sz(res[i]);j++)
			{
				int tag=0;
				for(k=j+1;k<sz(res[i]);k++)
				{
					if(check(res[i][j],res[i][k]))
					{
						tag=1;
						break;
					}
				}
				if(!tag) ans[cnt].pb(res[i][j]),flag=1,pos[cnt]=i;
			}
			if(flag) cnt++;
		}
		printf("%d\n",cnt);
		for(i=0;i<cnt;i++)
		{
			cout<<mp2[pos[i]];
			cout<<" "<<sz(ans[i]);
			for(j=0;j<sz(ans[i]);j++)
			{
				reverse(all(ans[i][j]));
				cout<<" "<<ans[i][j];
			}
			puts("");
		}
	}
	return 0;
}