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
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	int t=200,i,x,k;
	while(t--)
	{
		for(i=0;i<10;i++)
		{
			x=rand()%100+1;
			printf("%d ",x);
		}
		puts("");
		k=rand()%1000+1;
		printf("%d\n",k);
	}
	return 0;
}
*/
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int i,j,a[15],s,ans,k;
	while(~scanf("%d",&a[0]))
	{
		ans=0;
		for(i=1;i<10;i++) scanf("%d",&a[i]);
		scanf("%d",&k);
		for(i=1;i<(1<<10);i++)
		{
			s=0;
			for(j=0;j<10;j++)
			{
				if((1<<j)&i) s+=a[j];
			}
			if(s>=k) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10
*/