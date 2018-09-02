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
const int MAX=1e7+10;
const ll mod=1e9+7;
int ans[MAX],aa[MAX],bb[MAX],temp[MAX],res[2][MAX];
void work(int *a,int n,int f)
{
	int top,i;
	top=0;
	temp[0]=0;
	for(i=1;i<n;i++)  
	{
		while(top>-1&&a[i]>a[temp[top]])
		{
			res[f][temp[top]]=i+1;
			top--;
		}
		top++;
		temp[top]=i;
	}
}
int main()
{
	int n,i,q,x;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&aa[i]);
			res[0][i]=res[1][i]=-1;
			bb[n-i-1]=aa[i];
		}
		work(aa,n,0);
		work(bb,n,1);
	//	for(i=0;i<n;i++) printf("%d%c",res[0][i]," \n"[i==n-1]);
		for(i=n-1;~i;i--)
		{
			if(res[1][i]!=-1) res[1][i]=n-res[1][i]+1;
	//		printf("%d%c",res[1][i]," \n"[i==0]);
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&x);
			x--;
			int ans=INF;
			if(res[0][x]!=-1) ans=min(ans,res[0][x]-x-1);
			if(res[1][n-x-1]!=-1) ans=min(ans,x-res[1][n-x-1]+1);
			if(ans==INF) puts("Game Over");
			else printf("%d\n",ans);
		}
	}
	return 0;
}
/*
4
5 2 3 1
100
4
*/