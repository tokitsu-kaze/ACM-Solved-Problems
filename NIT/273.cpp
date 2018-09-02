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
	freopen("in.txt","w",stdout);
	srand(time(0));
	ll t=10,n,out[]={5,2,0},temp;
	printf("%lld\n",t);
	t--;
	n=(ll)1e6;
	printf("%lld\n",n);
	temp=n/3;
	ll cnt=0;
	while(temp--) printf("5"),cnt++;
	temp=n/3;
	while(temp--) printf("2"),cnt++;
	temp=n/3+1;
	while(temp--) printf("0"),cnt++;
	puts("");
	assert(cnt==n);
	while(t--)
	{
		n=(llrand()%(ll)1e6)+1;
		printf("%lld\n",n);
		while(n--)
		{
			printf("%lld",out[rand()%3]);
		}
		puts("");
	}
	return 0;
}
*/
char a[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ll t,n,i,cnt[3];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%s",&n,a);
		mem(cnt,0);
		for(i=0;i<n;i++)
		{
			if(a[i]=='5') cnt[0]++;
			else if(a[i]=='2') cnt[1]+=cnt[0];
			else if(a[i]=='0') cnt[2]+=cnt[1];
		}
		printf("%lld\n",cnt[2]);
	} 
	return 0;
}