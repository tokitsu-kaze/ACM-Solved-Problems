#include <bits/stdc++.h>
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
char a[MAX];
int vis[MAX];
int main()
{
	int i,ans,t,len,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&len,a);
		ans=0;
		flag=0;
		for(i=0;i<len;i++) vis[i]=0;
		for(i=3;i<len;i++)
		{
			if(a[i-3]=='C'&&a[i-2]=='C'&&a[i-1]=='P'&&a[i]=='C')
			{
				vis[i-3]++;
				vis[i-2]++;
				vis[i-1]++;
				vis[i]++;
				ans++;
			}
		}
		for(i=2;i<len;i++)
		{
			if(a[i-2]=='C'&&a[i-1]=='C'&&a[i]=='C'&&!vis[i-1]) flag=1;
			if(a[i-2]=='C'&&a[i-1]=='C'&&a[i]=='P'&&(i+1==len||(i+1!=len&&a[i+1]!='C'))) flag=1;
			if(((i-3>=0&&a[i-3]!='C')||i-3<0)&&a[i-2]=='C'&&a[i-1]=='P'&&a[i]=='C') flag=1;
		}
		printf("%d\n",ans+flag);
	}
	return 0;
}
/*
100
5
CCCPC
6
CCCCPC
6
CCPCCC
*/