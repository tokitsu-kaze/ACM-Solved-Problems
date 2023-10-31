#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int main()
{
	int n,i,d,cnt[55],ans,pre;
	string s,res;
	while(~scanf("%d%d",&n,&d))
	{
		cin>>s;
		mem(cnt,0);
		for(i=0;i<n;i++) cnt[s[i]-'a']++;
		ans=0;
		pre=-INF;
		res="";
		for(i=0;i<26;i++)
		{
			if(sz(res)==d) break;
			if(cnt[i])
			{
				if(i-pre>1)
				{
					pre=i;
					ans+=i+1;
					res+='a'+i;
				}
			}
		}
		if(sz(res)!=d) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}