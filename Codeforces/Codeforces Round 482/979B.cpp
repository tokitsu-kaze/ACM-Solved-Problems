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
const int MAX=5e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,cnt[3],j;
	string s;
	while(~scanf("%d",&n))
	{
		mem(cnt,0);
		for(i=0;i<3;i++)
		{
			cin>>s;
			map<char,int> mp;
			for(j=0;j<s.length();j++)
			{
				mp[s[j]]++;
				cnt[i]=max(cnt[i],mp[s[j]]);
			}
			if(cnt[i]==(int)s.length()&&n==1) cnt[i]--; 
			else cnt[i]=min(cnt[i]+n,(int)s.length());
		}
		if(cnt[0]>cnt[1]&&cnt[0]>cnt[2]) puts("Kuro");
		else if(cnt[1]>cnt[0]&&cnt[1]>cnt[2]) puts("Shiro");
		else if(cnt[2]>cnt[0]&&cnt[2]>cnt[1]) puts("Katie");
		else puts("Draw");
	}
	return 0;
}