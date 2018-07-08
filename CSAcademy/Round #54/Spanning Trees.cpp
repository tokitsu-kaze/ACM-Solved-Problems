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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,m,i,j,tot;
	while(~scanf("%d%d",&n,&m))
	{
		if(n==1)
		{
			puts("0");
			continue;
		}
		if(n<=3&&m==0)
		{
			puts("-1");
			continue;
		}
		tot=1;
		if(m==n-1)
		{
			printf("%d\n",n-1);
			for(i=2;i<=n;i++)
			{
				printf("1 %d %d\n",i,tot++);
			}
		}
		else if(m==0)
		{
			printf("%d\n",2*(n-1));
			for(i=2;i<=n;i++)
			{
				printf("%d %d %d\n",i-1,i,tot++);
			}
			for(i=3;i<=n;i++)
			{
				printf("1 %d %d\n",i,tot++);
			}
			printf("2 %d %d\n",n,tot++);
		}
		else
		{
			printf("%d\n",2*(n-1)-m);
			for(i=2;i<=n;i++)
			{
				printf("1 %d %d\n",i,tot++);
			}
			m=n-1-m;
			for(i=n;i>=2;i--)
			{
				for(j=2;j<i;j++)
				{
					if(m==0) break;
					printf("%d %d %d\n",i,j,tot++);
					m--;
				}
			}
		}
	}
	return 0;
}