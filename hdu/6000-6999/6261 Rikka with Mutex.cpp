////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-05 00:33:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6261
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:2216KB
//////////////////System Comment End//////////////////
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
char s[MAX];
int main()
{
	int t,i,len,pre,now,ans,bit,mx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		if(s[1]=='P')
		{
			puts("-1");
			continue;
		}
		len=strlen(s+1);
		vector<int> res;
		now=0;
		for(i=1;i<=len;i++)
		{
			if(s[i]=='V')
			{
				if(now<0)
				{
					res.pb(now);
					now=1;
				}
				else now++;
			}
			else
			{
				if(now>0)
				{
					res.pb(now);
					now=-1;
				}
				else now--;
			}
		}
		res.pb(now);
		mx=bit=now=0;
		ans=1;
		for(i=0;i<sz(res)-1;i++)
		{
			bit+=res[i];
			mx=max(mx,bit);
			now=bit+(ans-1)*mx;
			if(now+res[i+1]<0) ans+=(-(now+res[i+1])+mx-1)/mx;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
100
VPP
VPPVVVVPPPPPPPP
VPPPPPPPPPPPPPP
P
VPPVVVPPPPP
*/