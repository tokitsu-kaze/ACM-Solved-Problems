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
char mp[10][10];
int main()
{
	int i,j,w,b;
	w=b=INF;
	for(i=0;i<8;i++) scanf("%s",mp[i]);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(mp[j][i]=='W')
			{
				w=min(w,j);
				break;
			}
			else if(mp[j][i]=='B') break;
		}
		for(j=7;j>=0;j--)
		{
			if(mp[j][i]=='B')
			{
				b=min(b,7-j);
				break;
			}
			else if(mp[j][i]=='W') break;
		}
	}
//	cout<<w<<" "<<b<<endl;
	if(w<=b) puts("A");
	else puts("B");
	return 0;
}