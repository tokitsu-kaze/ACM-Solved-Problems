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
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e7+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int dp[MAX]={0};
void init()
{
    ll sq=sqrt(MAX-10),i,j;
    for(i=2;i<=sq;i++)
    {
        for(j=i;j<=MAX-10;j+=i)
        {
            dp[j]++;
        }
    }
}

int main()
{
    int l,r,i,j,p,now;
    init();
    while(~scanf("%d%d",&l,&r))
    {
		if(l==1&&r==1)
		{
			printf("[%d,%d] %d %d\n",1,1,1,1);
			puts("1");
			continue;
		}
		now=0;
		for(i=l;i<=r;i++)
		{
			if(dp[i]>now)
			{
				now=dp[i];
				p=i;
			}
		}
		VI res;
		int sq=sqrt(p+0.5);
		for(i=1;i<=sq;i++)
		{
			if(p%i==0)
			{
				res.pb(i);
				if(p/i!=i) res.pb(p/i);
			}
		}
		sort(all(res));
		printf("[%d,%d] %d %d\n",l,r,p,sz(res));
		for(i=0;i<sz(res);i++) printf("%d%c",res[i]," \n"[i==sz(res)-1]);
    }
    return 0;
}