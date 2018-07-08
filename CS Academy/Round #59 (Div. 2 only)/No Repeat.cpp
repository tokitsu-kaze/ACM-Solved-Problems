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
const int MAX=3e4+10;
const ll mod=1e9+7;
int main()
{
	int n,i,ans,a[222];
	char s[111];
	while(~scanf("%d",&n))
	{
		scanf("%s",s);
		mem(a,0);
		for(i=0;i<n;i++)
		{
			a[s[i]]++;
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			if(a[s[i]]==1)
			{
				ans=(int)s[i];
				break;
			}
		}
		if(ans==0) puts("-1");
		else printf("%c\n",(char)ans);
	}
	return 0;
}