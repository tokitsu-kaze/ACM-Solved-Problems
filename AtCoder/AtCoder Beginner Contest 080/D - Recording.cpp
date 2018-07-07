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
int bit[MAX][33],res[MAX];
int main()
{
	int n,x,i,j,a,b,c,ans,flag;
	while(~scanf("%d%d",&n,&x))
	{
		mem(bit,0);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			bit[a][c]++;
			bit[b+1][c]--;
		}
		mem(res,0);
		for(i=1;i<=x;i++)
		{
			flag=0;
			for(j=1;j<=100000;j++)
			{
				bit[j][i]+=bit[j-1][i];
				if(bit[j][i])
				{
					if(!flag) res[j]++;
					flag=1;
				}
				else
				{
					if(flag) res[j]--;
					flag=0;
				}
			}
		}
		ans=0;
		for(i=1;i<=(int)1e5;i++)
		{
			res[i]+=res[i-1];
			ans=max(ans,res[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
