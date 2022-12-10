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
const int MAX=2e5+10;
const ll mod=1e9+7;
vector<int> ans[MAX];
int tot;
queue<int> q[2];
char ss[MAX];
int main()
{
	int i,len,j,t;
	while(~scanf("%s",ss))
	{
		tot=0;
		len=strlen(ss);
		while(sz(q[0])) q[0].pop();
		while(sz(q[1])) q[1].pop();
		for(i=0;i<len;i++)
		{
			if(ss[i]=='0')
			{
				if(!sz(q[1]))
				{
					ans[tot].clear();
					ans[tot].pb(i+1);
					q[0].push(tot);
					tot++;
				}
				else
				{
					t=q[1].front();
					q[1].pop();
					ans[t].pb(i+1);
					q[0].push(t);
				}
			}
			else
			{
				if(!sz(q[0]))
				{
					puts("-1");
					goto end;
				}
				else
				{
					t=q[0].front();
					q[0].pop();
					ans[t].pb(i+1);
					q[1].push(t);
				}
			}
		}
		if(sz(q[1]))
		{
			puts("-1");
			goto end;
		}
		printf("%d\n",tot);
		for(i=0;i<tot;i++)
		{
			printf("%d",ans[i].size());
			for(j=0;j<ans[i].size();j++)
			{
				printf(" %d",ans[i][j]);
			}
			puts("");
		}
		end:;
	}
	return 0;
}