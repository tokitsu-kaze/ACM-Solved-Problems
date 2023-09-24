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
ll Hash[MAX],temp[MAX];
void work(char *s,int len)
{
	int i;
	ll seed=10;
	Hash[0]=0;
	temp[0]=1;
	for(i=1;i<=len;i++)
	{
		Hash[i]=(Hash[i-1]*seed+s[i]-'0')%mod;
		temp[i]=temp[i-1]*seed%mod;
	}
}
int flag;
char s[MAX];
void check(int a,int b,int c)
{
	if(flag) return;
	if(a<1||b<1||c<1||c<min(a,b)) return;
	if(s[1]=='0'&&a>1) return;
	if(s[a+1]=='0'&&b>1) return;
	if(s[a+b+1]=='0'&&c>1) return;
	ll x,y,z,i;
	x=Hash[a];
	y=(Hash[a+b]-Hash[a]*temp[b]%mod+mod)%mod;
	z=(Hash[a+b+c]-Hash[a+b]*temp[c]%mod+mod)%mod;
	if((x+y)%mod==z)
	{
		flag=1;
		for(i=1;i<=a;i++) putchar(s[i]);
		putchar('+');
		for(;i<=a+b;i++) putchar(s[i]);
		putchar('=');
		for(;i<=a+b+c;i++) putchar(s[i]);
		puts("");
	}
}
int main()
{
	int i,len;
	while(~scanf("%s",s+1))
	{
		len=strlen(s+1);
		work(s,len);
		flag=0;
		for(i=len;i;i--)
		{
			check(i,len-i-i,i);
			check(i-1,len-i-i+1,i);
			check(len-i-i,i,i);
			check(len-i-i+1,i-1,i);
			if(flag) break;
		}
	}
	return 0;
}