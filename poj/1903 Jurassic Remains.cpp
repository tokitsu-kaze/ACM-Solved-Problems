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
char s[1111];
int main()
{
	int n,i,j,now,cnt,ans;
	while(~scanf("%d",&n))
	{
		vector<int> a,b;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			now=0;
			for(j=0;j<strlen(s);j++)
			{
				now^=(1<<(s[j]-'A'));
			}
			if(i<n/2) a.pb(now);
			else b.pb(now);
		}
		map<int,PII > mp;
		for(i=0;i<(1<<(sz(a)));i++)
		{
			cnt=now=0;
			for(j=0;j<sz(a);j++)
			{
				if((i>>j)&1)
				{
					cnt++;
					now^=a[j]; 
				}
			}
			mp[now]=MP(i,cnt);
		}
		vector<int> ans;
		for(i=0;i<(1<<(sz(b)));i++)
		{
			cnt=now=0;
			for(j=0;j<sz(b);j++)
			{
				if((i>>j)&1)
				{
					cnt++;
					now^=b[j]; 
				}
			}
			PII temp=mp[now];
			if(temp.se==0&&now) continue;
	//		cout<<i<<" "<<temp.fi<<" "<<temp.se+cnt<<endl;
			if(temp.se+cnt>sz(ans))
			{
				ans.clear();
				for(j=0;j<sz(a);j++)
				{
					if((temp.fi>>j)&1) ans.pb(j);
				}
				for(j=0;j<sz(b);j++)
				{
					if((i>>j)&1) ans.pb(j+n/2);
				}
			}
		}
		sort(all(ans));
		printf("%d\n",sz(ans));
		for(i=0;i<sz(ans);i++) printf("%d ",ans[i]+1);
		puts("");
	}
	return 0;
}