////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-08 22:25:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6029
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:1660KB
//////////////////System Comment End//////////////////
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
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;
int main()
{
	int t,n,i,op,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt=1;
		for(i=2;i<=n;i++)
		{
			scanf("%d",&op);
			if(op==1)
			{
				if(cnt) cnt--;
				else cnt++;
			}
			else cnt++;
		}
		if(n%2||cnt) puts("No");
		else puts("Yes");
	}
	return 0;
}