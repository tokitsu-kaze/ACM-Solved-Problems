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
const int MAX=1e5+10;
const ll mod=1e9+7;
bool sg[301][301][301]={0};
void init()
{
	int i,j,k,l;
	for(i=0;i<=300;i++)
	{
		for(j=0;j<=300;j++)
		{
			for(k=0;k<=300;k++)
			{
				if(sg[i][j][k]) continue;
				for(l=1;l+i<=300;l++) sg[i+l][j][k]=1;
				for(l=1;l+j<=300;l++) sg[i][j+l][k]=1;
				for(l=1;l+k<=300;l++) sg[i][j][k+l]=1;
				for(l=1;l+max(i,j)<=300;l++) sg[i+l][j+l][k]=1;
				for(l=1;l+max(i,k)<=300;l++) sg[i+l][j][k+l]=1;
				for(l=1;l+max(j,k)<=300;l++) sg[i][j+l][k+l]=1;
			}
		}
	}
}
int main()
{
	init();
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		printf("%d\n",sg[a][b][c]);
	}
	return 0;
}