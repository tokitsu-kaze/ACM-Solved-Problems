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
char s[MAX];
struct Manacher
{
	int r[MAX];
	int work(char *s,int len)//return max length of palindrome
	{
		int right,mid,i,res=0;
		//odd
		right=mid=0;
		mem(r,0); 
		for(i=1;i<=len;i++)
		{
			//substring s[i,i]
			if(right>i) r[i]=min(r[2*mid-i],right-i);
			while(i+r[i]+1<=len&&s[i+r[i]+1]==s[i-r[i]-1])
			{
				//substring s[i-r[i]-1,i+r[i]+1]
				r[i]++;
			}
			if(i+r[i]>right)
			{
				right=i+r[i];
				mid=i;
			}
			res=max(res,r[i]*2+1);
		}
		//even
		right=mid=0;
		mem(r,0);
		for(i=2;i<=len;i++)
		{
			if(right>i) r[i]=min(r[2*mid-i],right-i+1);
			while(i+r[i]<=len&&s[i+r[i]]==s[i-r[i]-1])
			{
				//substring s[i-r[i]-1,i+r[i]]
				r[i]++;
			}
			if(i+r[i]-1>right)
			{
				right=i+r[i]-1;
				mid=i;
			}
			res=max(res,r[i]*2);
		}
		return res;
	}
}la;
void go()
{
	int cas=1;
	while(~scanf("%s",s+1)&&strcmp(s+1,"END"))
	{
		printf("Case %d: %d\n",cas++,la.work(s,strlen(s+1)));
	}
}
