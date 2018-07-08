#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
	int n,k,i,ans,ans1,ans2,p1,p2;
	while(~scanf("%d%d",&n,&k))
	{
		scanf("%s",s);
		ans1=ans2=0;
		p1=p2=-1;
		for(i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				p1=i;
				break;
			}
			ans1++;
		}
		for(i=n-1;i>=0;i--)
		{
			if(s[i]=='1')
			{
				p2=i;
				break;
			}
			ans2++;
		}
		if(p1==p2&&p1==-1)
		{
			printf("%lld\n",(ll)n*k);
			continue;
		}
		ans=0;
		int now=0;
		for(i=p1;i<=p2;i++)
		{
			if(s[i]=='1')
			{
				ans=max(ans,now);
				now=0;
			}
			else now++;
		}
		if(k==1) printf("%d\n",max(max(ans1,ans2),ans));
		else printf("%d\n",max(ans1+ans2,ans));
	}
	return 0;
}