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
	ll t=20,n,q,i,out[]={5,2,0},l,r;
	printf("%lld\n",t);
	t--;
	n=(ll)1e5;
	q=(ll)1e5;
	printf("%lld %lld\n",n,q);
	i=0;
	while(n--)
	{
		printf("%lld",out[i++]);
		i%=3;
	}
	puts("");
	while(q--)
	{
		l=1;
		r=(ll)1e5;
		printf("%lld %lld\n",l,r);
	}
	while(t--)
	{
		n=(llrand()%(ll)1e5)+1;
		q=(llrand()%(ll)1e5)+1;
		printf("%lld %lld\n",n,q);
		for(i=0;i<n;i++)
		{
			printf("%lld",out[rand()%3]);
		}
		puts("");
		while(q--)
		{
			l=(llrand()%n)+1;
			r=(llrand()%n)+1;
			if(r<l) swap(l,r);
			printf("%lld %lld\n",l,r);
		}
	}
	return 0;
}
/*
char s[MAX];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,q,l,r,i,res[3];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		assert(n<MAX);
		scanf("%s",s+1);
		ll ret=0;
		while(q--)
		{
			scanf("%d%d",&l,&r);
			assert(l<=r);
			assert(l<=n);
			assert(r<=n);
			int ans=INF;
			mem(res,0);
			for(i=l;i<=r;i++)
			{
				if(s[i]=='5') res[0]++;
				else if(s[i]=='2') res[1]++;
				else if(s[i]=='0') res[2]++;
			}
			for(i=0;i<3;i++)
			{
				ans=min(ans,res[i]);
			}
			ret+=ans;
		}
		printf("%lld\n",ret);
	}
	return 0;
}
*/
char s[MAX];
int bit[MAX][3];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,n,q,i,j,pos[11],l,r;
	scanf("%d",&t);
	pos['5'-'0']=0;
	pos['2'-'0']=1;
	pos['0'-'0']=2;
	while(t--)
	{
		scanf("%d%d",&n,&q);
		mem(bit,0);
		scanf("%s",s+1);
		for(i=1;i<=n;i++)
		{
			bit[i][pos[s[i]-'0']]++;
			for(j=0;j<3;j++)
			{
				bit[i][j]+=bit[i-1][j];
			}
		}
		ll ans=0; 
		while(q--)
		{
			scanf("%d%d",&l,&r);
			int res=INF;
			for(i=0;i<3;i++)
			{
				res=min(res,bit[r][i]-bit[l-1][i]);
			}
			ans+=res;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
4 3
5202
1 3
1 4
2 4
*/