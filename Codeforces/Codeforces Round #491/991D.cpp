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
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int i,j,k,ans,cnt;
	string s[2];
	while(cin>>s[0])
	{
		cin>>s[1];
		ans=0;
		for(i=0;i+1<s[0].length();i++)
		{
			cnt=0;
			cnt+=s[0][i]=='0';
			cnt+=s[0][i+1]=='0';
			cnt+=s[1][i]=='0';
			cnt+=s[1][i+1]=='0';
			if(cnt<3) continue;
			cnt=3;
			j=k=0;
			while(1)
			{
				if(k==2)
				{
					j=1;
					k=0;
				}
				if(s[j][i+k]=='0') s[j][i+k]='X',cnt--;
				k++;
				if(!cnt) break;
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
0X00
0000


000
000
*/
