#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
struct ll_hash{size_t operator()(ll x)const{return x;}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
char s[MAX];
int pre[333];
int main()
{
	int i,len,ans[333],res;
	while(~scanf("%s",s+1))
	{
		mem(ans,0);
		len=strlen(s+1);
		mem(pre,0);
		for(i=1;i<=len;i++)
		{
			ans[s[i]]=max(ans[s[i]],i-pre[s[i]]);
			pre[s[i]]=i;
		}
		res=INF;
		for(i='a';i<='z';i++)
		{
			ans[i]=max(ans[i],len-pre[i]+1);
			res=min(res,ans[i]);
		}
		printf("%d\n",res);
	}
	return 0;
}
/*
bba
*/