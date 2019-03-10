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
#include <bitset>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
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
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
char s[444],a[222],b[222];
int dp[222][222];
void go()
{
	int t,cas=1,len,i,j,lena,lenb;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%s",a+1,b+1,s+1);
		lena=strlen(a+1);
		lenb=strlen(b+1);
		len=strlen(s+1);
		mem(dp,0);
		for(i=1;i<=lena;i++) dp[i][0]=(a[i]==s[i]);
		for(i=1;i<=lenb;i++) dp[0][i]=(b[i]==s[i]);
		for(i=1;i<=lena;i++)
		{
			for(j=1;j<=lenb;j++)
			{
				if(dp[i][j-1]&&b[j]==s[i+j]) dp[i][j]=1;
				if(dp[i-1][j]&&a[i]==s[i+j]) dp[i][j]=1;
			}
		}
		printf("Data set %d: ",cas++);
		if(dp[lena][lenb]) puts("yes");
		else puts("no");
	}
}

