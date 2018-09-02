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
#define PII pair<int,int>
#define PLL pair<ll,ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	char a[222];
	while(~scanf("%s",a))
	{
		if(a[0]=='-')
		{
			puts(a);
			puts(a+1);
		}
		else
		{
			if(strlen(a)==1&&a[0]=='0')
			{
				puts(a);
				puts(a);
				continue;
			}
			putchar('-');
			puts(a);
			puts(a);
		}
	}
	return 0;
}