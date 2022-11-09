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
int s[MAX],top,flag[MAX];
int main()
{
	int n,k,i,x,now,t;
	while(~scanf("%d%d",&n,&k))
	{
		vector<int> ans;
		top=0;
		mem(flag,0);
		now=1;
		for(i=0;i<k;i++)
		{
			scanf("%d",&x);
			flag[x]=1;
			ans.pb(x);
			s[top++]=x;
			while(top&&s[top-1]==now)
			{
				top--;
				now++;
			}
		}
		while(now<=n)
		{
			if(top==0)
			{
				for(i=n;!flag[i]&&i>=1;i--) ans.pb(i),flag[i]=1,s[top++]=i;
			}
			else
			{
				t=s[top-1];
				for(i=t-1;!flag[i]&&i>=1;i--) ans.pb(i),flag[i]=1,s[top++]=i;
				if(s[top-1]!=now)
				{
					puts("-1");
					goto end;
				}
			}
			while(top&&s[top-1]==now)
			{
				top--;
				now++;
			}
		}
		printf("%d",ans[0]);
		for(i=1;i<sz(ans);i++) printf(" %d",ans[i]);
		puts("");
		end:;
	}
	return 0;
}
/*
5 3
4 2 1
42135
*/