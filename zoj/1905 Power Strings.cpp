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
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int nex[MAX];
void get_next(char *s,int *nex,int len)
{
	int i,j;
	i=0;
	j=nex[0]=-1;
	while(i<len)
	{
		if(j==-1||s[i]==s[j]) nex[++i]=++j;
		else j=nex[j];
	}
}
char s[MAX];
void go()
{
	int len;
	while(~scanf("%s",s)&&strcmp(s,".")!=0)
	{
		len=strlen(s);
		get_next(s,nex,len);
		if(len%(len-nex[len])==0) printf("%d\n",len/(len-nex[len]));
		else puts("1");
	}
}
/*
baabaab
nex[len]=4
len/(len-nex[len])=2
but ans=1
so need if(len%(len-nex[len])==0)
*/
