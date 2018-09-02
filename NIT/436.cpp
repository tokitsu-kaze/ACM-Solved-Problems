#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
	int cas;
	ll x;
	char s[111];
	mem(s,0);
	srand(time(0));
	for(cas=1;cas<=100;cas++)
	{
		sprintf(s,"%03d",cas);
		strcpy(s+strlen(s),".in");
		freopen(s,"w",stdout);
		x=1;
		while((x&1)&&x<=2) x=llrand()%(mod-7);
		printf("%lld\n",x);
	}
	x=0;
	for(cas=101;cas<=150;cas++)
	{
		sprintf(s,"%03d",cas);
		strcpy(s+strlen(s),".in");
		freopen(s,"w",stdout);
		x+=2;
		printf("%lld\n",x);
	}
	for(cas=151;cas<=151;cas++)
	{
		sprintf(s,"%03d",cas);
		strcpy(s+strlen(s),".in");
		freopen(s,"w",stdout);
		x=mod-7;
		printf("%lld\n",x);
	}
	return 0;
}
*/
/*
//特判程序
char IN_FILE[20];
char OUT_FILE[20];
char USER_ANS[20];
char USER_SRC[20];
int check(int x)
{
	int i;
	if(x<2) return 0;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	gets(IN_FILE);      //输入数据的文件名
	gets(OUT_FILE);     //标准输出的文件名
	gets(USER_ANS);     //用户输出的文件名
	gets(USER_SRC);     //用户源程序的文件名
	FILE *IN=fopen(IN_FILE,"r");
	FILE *OUT=fopen(OUT_FILE,"r");
	FILE *USER=fopen(USER_ANS,"r");
	int i,a,b,c,n;
	char tmp[1111];
	fscanf(IN,"%d",&n);
	if(n==2)
	{
		fscanf(USER,"%s",tmp);
		return !(strlen(tmp)==2&&tmp[0]=='-'&&tmp[1]=='1');
	}
	c=a=b=0; 
    fscanf(USER,"%d=%d+%d",&c,&a,&b);
    fclose(IN);
	fclose(USER);
	if(c<=0||a<=0||b<=0) return 1;
	if(c!=n) return 1;
	if(c!=a+b) return 1;
	if(!check(a)) return 1;
	if(!check(b)) return 1;
	return 0;
}
*/
int prime[MAX];
vector<int> p;
void init(int n)
{
	int i,j;
	mem(prime,0);
	p.clear();
	for(i=2;i<=n;i++)
	{
		if(prime[i]) continue;
		p.pb(i);
		for(j=i+i;j<=n;j+=i)
		{
			if(!prime[j]) prime[j]=i;
		}
	}
}
int check(int x)
{
	int i;
	if(x<2) return 0;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	init(sqrt(1e9));
	int i,a,b,n;
	while(~scanf("%d",&n))
	{
		if(n==2)
		{
			puts("-1");
			continue;
		}
		for(i=0;i<sz(p);i++)
		{
			if(check(n-p[i]))
			{
				a=p[i];
				b=n-p[i];
				break;
			}
		}
		printf("%d=%d+%d\n",n,a,b);
	}
	return 0;
}