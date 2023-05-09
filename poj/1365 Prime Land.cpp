#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
#include <limits>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
void go();
int main(){
	#ifdef tokitsukaze
	//	freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=4e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int p[MAX],tot,prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	mem(prime,0);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
        for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
void go()
{
	int i,len,a,b,x,f,now,cnt;
	char s[1111];
	init(4e4);
	while(~scanf(" %[^\n]",s))
	{
		len=strlen(s);
		if(len==1&&s[0]=='0') break;
		x=1;
		a=b=0;
		f=0;
		for(i=0;i<len;i++)
		{
			if(s[i]==' ')
			{
				if(f==1)
				{
					now=1;
					while(b--) now*=a;
					f=0;
					a=b=0;
					x*=now;
				}
				else
				{
					f=1;
				}
			}
			else
			{
				if(f==0) a=a*10+s[i]-'0';
				else b=b*10+s[i]-'0';
			}
		}
		now=1;
		while(b--) now*=a;
		x*=now;
		x--;
		VI res;
		for(i=tot-1;~i;i--)
		{
			if(x%p[i]) continue;
			cnt=0;
			while(x%p[i]==0)
			{
				x/=p[i];
				cnt++;
			}
			res.pb(p[i]);
			res.pb(cnt);
		}
		println(res);
	}
}
