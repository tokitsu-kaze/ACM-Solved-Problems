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
int res[MAX][10];
void init()
{
	int i,j,now,temp;
	mem(res,0);
	for(i=1;i<=MAX-10;i++)
	{
		temp=i;
		now=1;
		while(temp)
		{
			if(temp%10!=0) now*=(temp%10);
			temp/=10;
		}
		while(now>=10)
		{
			temp=now;
			now=1;
			while(temp)
			{
				if(temp%10!=0) now*=(temp%10);
				temp/=10;
			}
		}
		res[i][now]++;
		for(j=1;j<=9;j++) res[i][j]+=res[i-1][j];
	}
}
int main()
{
	int q,l,r,k;
	init();
	while(~scanf("%d",&q))
	{
		while(q--)
		{
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",res[r][k]-res[l-1][k]);
		}
	}
	return 0;
}