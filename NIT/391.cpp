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
const int MAX=5e5+10;
const ll mod=1e9+7;
/*
int tot;
char mp[333];
void init()
{
	int i;
	tot=0;
	for(i='0';i<='9';i++) mp[tot++]=(char)i;
	for(i='a';i<='z';i++) mp[tot++]=(char)i;
	for(i='A';i<='Z';i++) mp[tot++]=(char)i;
}
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
	init();
	ll t=20,i,l,r,n,q;
	char c;
	printf("%lld\n",t);
	t--;
	n=(int)5e5;
	q=2000;
	printf("%lld %lld\n",n,q);
	for(i=1;i<=n;i++)
	{
		c=mp[rand()%tot];
		putchar(c);
	}
	puts("");
	while(q--)
	{
		l=1;
		r=n;
		c=mp[rand()%tot];
		printf("%lld %lld %c\n",l,r,c);
	}
	while(t--)
	{
		n=(int)5e5;
		q=(rand()%2000)+1;
		printf("%lld %lld\n",n,q);
		for(i=1;i<=n;i++)
		{
			c=mp[rand()%tot];
			putchar(c);
		}
		puts("");
		while(q--)
		{
			l=(llrand()%n)+1;
			r=l+(llrand()%(n-l+1));
			assert(l<=r);
			c=mp[rand()%tot];
			printf("%lld %lld %c\n",l,r,c);
		}
	}
	return 0;
}
*/
/*
int flag[MAX];
char s[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,q,l,r,len,i,t,cas=1;
	char op[11];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		mem(flag,0);
		while(q--)
		{
			scanf("%d%d%s",&l,&r,op);
			for(i=l;i<=r;i++)
			{
				if(s[i]==op[0]) flag[i]^=1;
			}
		}
		printf("Case #%d:",cas++);
		len=strlen(s+1);
		for(i=1;i<=len;i++)
		{
			if(!flag[i]) putchar(s[i]); 
		}
		puts("");
	}
	return 0;
}
*/
int tot;
ll mp[333];
void init()
{
	int i;
	mem(mp,0);
	tot=0;
	for(i='0';i<='9';i++) mp[i]=(1LL<<tot),tot++;
	for(i='a';i<='z';i++) mp[i]=(1LL<<tot),tot++;
	for(i='A';i<='Z';i++) mp[i]=(1LL<<tot),tot++;
//	cout<<tot<<endl;
}
ll bit[MAX];
char s[MAX];
int main()
{
	
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,q,l,r,len,i,j,t,cas=1;
	char op[11];
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		len=strlen(s+1);
		mem(bit,0);
		while(q--)
		{
			scanf("%d%d%s",&l,&r,op);
			bit[l]^=mp[op[0]];
			bit[r+1]^=mp[op[0]];
		}
		printf("Case #%d:",cas++);
		for(i=1;i<=len;i++)
		{
			bit[i]^=bit[i-1];
			if(!(bit[i]&mp[s[i]])) putchar(s[i]);
		}
		puts("");
	}
	return 0;
}
/*
2
4 1
aaaa
1 4 a
5 4
abcba
1 5 a
1 4 b
3 5 a
2 3 b
*/