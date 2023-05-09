#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int prime[MAX],phi[MAX],cnt;
bool flag[MAX];
void Euler(int n)  
{  
	int i,j,k;
	cnt=0;  
	mem(flag,0);
	phi[0]=0;
	phi[1]=1;
	for(int i=2;i<=n;i++)  
	{  
		if(!flag[i])  
		{  
			prime[cnt++]=i;  
			phi[i]=i-1;
		}  
		for(int j=0;j<cnt&&i*prime[j]<=n;j++)  
		{  
			k=i*prime[j];
			flag[k]=1;
			if(i%prime[j]==0)
			{  
				phi[k]=phi[i]*prime[j];
				break;  
			}
			else phi[k]=phi[i]*(prime[j]-1);
		}
	}
}
void go()
{
	int n;
	Euler(MAX-10);
	while(~scanf("%d",&n))
	{
		printf("%d\n",phi[phi[n]]);
	}
}
