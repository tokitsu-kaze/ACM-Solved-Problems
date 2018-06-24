////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-01 18:15:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2527
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1692KB
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
const int MAX=3e5+10;
const ll mod=1e9+7;
char s[MAX];
int main()
{
	int t,i,cnt[333],k,ans,len,res[3];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&k,s);
		len=strlen(s);
		mem(cnt,0);
		for(i=0;i<len;i++) cnt[s[i]]++;
		ans=0;
		priority_queue<int,vector<int>,greater<int> > q;
		for(i=0;i<256;i++)
		{
			if(cnt[i]) q.push(cnt[i]);
		}
		if(sz(q)==1) ans=q.top();
		while(sz(q)>1)
		{
			for(i=0;i<2;i++)
			{
				res[i]=q.top();
				q.pop();
			}
			ans+=res[0]+res[1];
			q.push(res[0]+res[1]);
		}
		ans<=k?puts("yes"):puts("no");
	}
	return 0;
}