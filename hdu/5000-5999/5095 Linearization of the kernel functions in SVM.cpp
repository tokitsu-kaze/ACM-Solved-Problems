////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-18 22:03:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5095
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
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
int main()
{
	int i,f[12],t;
	char s[]={'p','q','r','u','v','w','x','y','z'};
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<10;i++) scanf("%d",&f[i]);
		i=0;
		while(i<10&&!f[i]) i++;
		if(i==10)
		{
			puts("0");
			continue;
		}
		else if(i==9)
		{
			printf("%d\n",f[i]);
			continue;
		}
		if(f[i]>1) printf("%d%c",f[i],s[i]);
		else if(f[i]==1) printf("%c",s[i]);
		else if(f[i]==-1) printf("-%c",s[i]);
		else if(f[i]<-1) printf("%d%c",f[i],s[i]);
		i++;
		for(;i<9;i++)
		{
			if(f[i]>1) printf("+%d%c",f[i],s[i]);
			else if(f[i]==1) printf("+%c",s[i]);
			else if(f[i]==-1) printf("-%c",s[i]);
			else if(f[i]<-1) printf("%d%c",f[i],s[i]);
		}
		if(f[9]>0) printf("+%d\n",f[9]);
		else if(f[9]<0) printf("%d\n",f[9]);
		else puts("");
	}
	return 0;
}
/*
100
1 1 1 1 1 1 1 1 1 1
0 1 1 1 1 1 1 1 1 0
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 -1 1
-2 0 0 0 0 0 0 0 -1 1
*/