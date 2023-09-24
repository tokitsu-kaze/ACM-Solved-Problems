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
const double eps=1e-8;
const int MAX=5e5+10;
const ll mod=1e9+7;
char a[2020][202],b[202][2020];
int main()
{
	int n,m,i,j,k,flag;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++) scanf("%s",a[i]);
		for(i=0;i<m;i++) scanf("%s",b[i]);
		for(i=0;i<=n-m;i++)
		{
			for(j=0;j<=n-m;j++)
			{
				flag=1;
				for(k=0;k<m;k++)
				{
					if(!flag) break;
					flag&=(memcmp(&a[i+k][0],&b[k][j],m)==0);
				}
				if(flag)
				{
					printf("%d %d\n",i+1,j+1);
					goto end;
				}
			}
		}
		end:;
	}
	return 0;
}