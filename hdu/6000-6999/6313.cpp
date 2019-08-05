#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
char mp[2222][2222];
int main()
{
	mem(mp,'0');
	const int t=47;
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<t;j++)
		{
			for(int k=0;k<t;k++)
			{
				mp[i*t+j][k*t+(j*k+i)%t]='1';
			}
		}
	}
	puts("2000");
	for(int i=0;i<2000;i++)
	{
		mp[i][2000]='\0';
		puts(mp[i]);
	}
	return 0;
}
