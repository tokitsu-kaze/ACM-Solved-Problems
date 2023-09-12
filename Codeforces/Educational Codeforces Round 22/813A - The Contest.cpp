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
int flag[MAX],cnt[MAX],x[MAX];
int main()
{
	int n,i,s,m,l,r,ans,now;
	while(~scanf("%d",&n))
	{
		mem(flag,0);
		mem(cnt,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
		}
		
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&l,&r);
			flag[l]++;
			flag[r+1]--;
		}
		sort(x+1,x+1+n);
		s=0;
		for(i=1;i<=n;i++)
		{
			s+=x[i];
			if(s>MAX-10)
			{
				puts("-1");
				goto end;
			}
			cnt[s]++; 
		}
		now=s=0;
		ans=INF;
		for(i=1;i<=MAX-10;i++)
		{
			now+=cnt[i];
			flag[i]+=flag[i-1];
			if(flag[i])
			{
				if(now)
				{
					s+=now;
					now=0;
				}
			}
			if(s==n) ans=min(ans,i);
		}
		if(s!=n) puts("-1");
		else printf("%d\n",ans);
		end:;
	}
	return 0;
}