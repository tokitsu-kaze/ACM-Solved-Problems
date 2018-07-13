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
const double eps=1e-4;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int n,a,b,i,j,x,y,now;
	while(~scanf("%d%d%d",&n,&a,&b))
	{
		x=y=-1;
		for(i=0;i*a<=n;i++)
		{
			if((n-i*a)%b==0)
			{
				x=i;
				y=(n-i*a)/b;
				break;
			}
		}
		if(x==-1)
		{
			puts("-1");
			continue;
		}
		now=1;
		for(i=1;i<=x;i++)
		{
			printf("%d ",now+a-1);
			for(j=1;j<a;j++)
			{
				printf("%d ",now);
				now++;
			}
			now++;
		}
		for(i=1;i<=y;i++)
		{
			printf("%d ",now+b-1);
			for(j=1;j<b;j++)
			{
				printf("%d ",now);
				now++;
			}
			now++;
		}
		puts("");
	}
	return 0;
}
/*
2 1 4 3 9 5 6 7 8
*/