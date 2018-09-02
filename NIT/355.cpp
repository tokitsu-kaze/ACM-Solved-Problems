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
const double eps=1e-8;
const int MAX=1e6+10;
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
	srand(time(0));
	freopen("in.txt","w",stdout);
	int t=87,l,r;
	printf("%d\n",t);
	t--;
	l=1;
	r=MAX-10;
	printf("%d %d\n",l,r);
	t--;
	l=(int)(llrand()%(MAX-10))+1;
	r=l;
	printf("%d %d\n",l,r);
	while(t--)
	{
		l=(int)(llrand()%(MAX-10))+1;
		r=(int)(llrand()%(MAX-10-l+1))+l;
		assert(l<=r);
		printf("%d %d\n",l,r);
	}
	return 0;
}
*/
int main()
{
	int a,b,i,ans,t;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		ans=0;
		for(i=1;i*i<=MAX-10;i++)
		{
			ans+=(i*i>=a&&i*i<=b);
		}
		printf("%d\n",b-a+1-ans);
	}
	return 0;
}
/*
1
1 10


7

*/