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
int x[MAX],y[MAX];
int main()
{
	int n,i,ans;
	while(~scanf("%d",&n))
	{
		scanf("%s",s+1);
		ans=0;
		mem(x,0);
		mem(y,0);
		for(i=1;i<=n;i++)
		{
			if(s[i]=='R') x[i]=1;
			else y[i]=1;
			x[i]+=x[i-1];
			y[i]+=y[i-1];
		}
		for(i=2;i<=n-1;i++)
		{
			if(x[i]==y[i])
			{
				if(x[i-1]>y[i-1]&&x[i+1]<y[i+1]) ans++;
				else if(x[i-1]<y[i-1]&&x[i+1]>y[i+1]) ans++;
			}
	//		cout<<x[i]<<" "<<y[i]<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}