////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-18 22:57:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5097
////Problem Title: 
////Run result: Accept
////Run time:374MS
////Run memory:81244KB
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
const int MAX=1e6+10;
const ll mod=1e9+7;
char g[3005][3005];  
double mat[3005][3005];  
double res[2][3005];  
int n;
bool check()
{
	double ans=0;
	for(int i=1;i<= n;i++) ans+=(res[0][i]-res[1][i])*(res[0][i]-res[1][i]);
	if(ans<1e-10) return 1;
	else return 0;
}
int main(void)
{
	int i,j,t,now;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%s",g[i]+1);
		mem(mat,0);
		for(i=1;i<=n;i++)
		{
			t=0;
			for(j=1;j<=n;j++)
			{
				if(g[i][j]=='1') t++;
			}
			for(j=1;j<=n;j++)
			{
				if(g[i][j]=='1') mat[j][i]=1.0/t;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				mat[i][j]=0.85*mat[i][j]+0.15*1.0/n;
			}
		}
		now=0;
		for(i=1;i<=n;i++) res[now][i]=1.0;
		while(1)
		{
			if(check()) break;
			mem(res[now^1],0);
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					res[now^1][i]+=res[now][j]*mat[i][j];
				}
			}
			now^=1;
		}
		for(i=1;i<=n;i++) printf("%.2f%c", res[now][i]," \n"[i==n]);
	}
	return 0;
}