////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-04-03 15:57:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
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
const int MAX=1e4+10;
const ll mod=1e9+7;
int f[205],sg[MAX];
void SG(int n)
{
	int i,j,flag[222];
	mem(sg,0);
	for(i=1;i<=n;i++)
	{
		mem(flag,0);
		for(j=0;j<i;j++)
		{
			flag[sg[j]]=1;
		}
		for(j=1;j<=i/2;j++)
		{
			flag[sg[i-j]^sg[j]]=1;
		}
		for(j=0;;j++)
		{
			if(!flag[j])
			{
				sg[i]=j;
				break;
			}
		}
		cout<<i<<" "<<sg[i]<<endl;
	}
}
int main()
{
//	SG(200);
	int t,n,i,ans,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x%4==0) ans^=(x-1);
			else if(x%4==3) ans^=(x+1);
			else ans^=x;
		}
		if(ans) puts("Alice");
		else puts("Bob");
	}
	return 0;
}