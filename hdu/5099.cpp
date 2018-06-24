////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-18 22:13:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5099
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1704KB
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
const int MAX=1e5+10;
const ll mod=1e9+7;
string a,b;
char judge()
{
	int i;
	for(i=2;i<=4;i++)
	{
		if(a[i]!=b[i]) return a[i]<b[i]?'<':'>';
	}
	if(a[1]==b[1])
	{
		char t1=(a[5]=='\0'?'a':a[5]);
		char t2=(b[5]=='\0'?'a':b[5]);
		return(t1==t2?'=':(t1<t2?'<':'>'));
	}
	return '=';
}
int main()
{
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		cin>>a>>b;
		char ch1=(a[0]==b[0]?'=':(a[0]<b[0]?'<':'>'));
		char ch2=judge();
		printf("Case %d: %c %c\n",cas++,ch1,ch2);
	}
	return 0;
}