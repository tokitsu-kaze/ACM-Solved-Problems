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
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int main()
{
	int a,b,flag,s;
	while(~scanf("%d%d",&a,&b))
	{
		flag=0;
		while(1)
		{
			s=0;
			if(!flag)
			{
				while(a>0)
				{
					if(s+100>220) break;
					s+=100;
					a--;
				}
				while(b>0)
				{
					if(s+10>220) break;
					s+=10;
					b--;
				}
			}
			else
			{
				while(b>0)
				{
					if(s+10>220) break;
					s+=10;
					b--;
				}
				while(s&&(220-s)%100!=0)
				{
					s-=10;
					b++;
				}
				while(a>0)
				{
					if(s+100>220) break;
					s+=100;
					a--;
				}
			}
			flag^=1;
			if(s!=220) break;
		}
		flag==0?puts("Ciel"):puts("Hanako");
	}
	return 0;
}