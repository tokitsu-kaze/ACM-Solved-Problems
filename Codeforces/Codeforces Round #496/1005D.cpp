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
const int MAX=2e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int main()
{
	string s;
	int i,cnt[5],ans,sum;
	while(cin>>s)
	{
		mem(cnt,0);
		ans=sum=0;
		for(i=0;i<s.length();i++)
		{
			(sum+=s[i]-'0')%=3;
			if(!sum)
			{
				ans++;
				mem(cnt,0);
			}
			else
			{
				if(cnt[sum])
				{
					ans++;
					sum=0;
					mem(cnt,0);
				}
				else cnt[sum]++;
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}