#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=3e5+10;
const ll mod=1e9+7;
char s[MAX];
int main()
{
	int i,len,cnt[333],t[3],ans;
	while(~scanf("%s",s))
	{
		if(strcmp(s,"END")==0) break;
		len=strlen(s);
		mem(cnt,0);
		for(i=0;i<len;i++) cnt[s[i]]++;
		priority_queue<int,vector<int>,greater<int> > q;
		for(i=0;i<256;i++)
		{
			if(cnt[i]) q.push(cnt[i]);
		}
		ans=0;
		if(sz(q)==1) ans=q.top();
		while(sz(q)>1)
		{
			for(i=0;i<2;i++)
			{
				t[i]=q.top();
				q.pop();
			}
			q.push(t[0]+t[1]);
			ans+=t[0]+t[1];
		}
		printf("%d %d %.1f\n",8*len,ans,8*len*1.0/ans);
	}
	return 0;
}