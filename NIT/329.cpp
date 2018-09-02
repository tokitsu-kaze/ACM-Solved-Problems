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
const int MAX=6e4+10;
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
	int t=30,n,k,x;
	printf("%d\n",t);
	t--;
	n=30000; 
	k=1;
	printf("%d %d\n",n,k);
	while(n--)
	{
		x=(llrand()%(ll)1e9)+1;
		printf("%d ",x);
	}
	puts("");
	t--;
	n=30000; 
	k=n;
	printf("%d %d\n",n,k);
	while(n--)
	{
		x=(llrand()%(ll)1e9)+1;
		printf("%d ",x);
	}
	puts("");
	while(t--)
	{
		n=(rand()%(int)3e4)+1;
		k=rand()%n+1;
		printf("%d %d\n",n,k);
		while(n--)
		{
			x=(llrand()%(ll)1e9)+1;
			printf("%d ",x);
		}
		puts("");
	}
	return 0;
}
*/
int bit[MAX],val[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int i,n,ans,k,t;
	char s[22];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			val[i]=strlen(s);
			bit[i]=bit[i-1]+val[i];
		}
		for(i=n+1;i<=2*n-1;i++)
		{
			bit[i]=bit[i-1]+val[i-n];
		}
		ans=0;
		for(i=1;i<=2*n-k;i++)
		{
			ans=max(ans,bit[i+k-1]-bit[i-1]);
	//		cout<<i<<" "<<i+k-1<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}