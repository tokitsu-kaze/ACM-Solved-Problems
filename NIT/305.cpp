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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=(1L<<20)+10;
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
	ll t,l,r,maxx=1e9;
	freopen("in.txt","w",stdout);
	srand((unsigned)time(0));
	t=1000;
	printf("%lld\n",t);
	printf("%lld %lld\n",(ll)1,maxx);
	t--;
	while(t--)
	{
		l=rand()%maxx+1;
		r=llrand()%maxx+1;
		while(l>r)
		{
			l=rand()%maxx+1;
			r=llrand()%maxx+1;
		}
		assert(l<=r);
		if(t<=20) l=r;
		printf("%lld %lld\n",l,r);
	}
	return 0;
}
*/
/*
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int l,r,i,j,t,ans[11];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		mem(ans,0);
		for(i=l;i<=r;i++)
		{
			for(j=1;j<=9;j++)
			{
				if(i%j==0) ans[j]++;
			}
		}
		for(i=1;i<=9;i++)
		{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
*/

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int l,r,i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		for(i=1;i<=9;i++)
		{
			int res=r/i-l/i+(l%i==0?1:0);
			printf("%d\n",res);
		}
	}
	return 0;
}