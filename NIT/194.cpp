#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=5e4+10;
const ll mod=1e9+7;
vector<int> day[MAX];
int main()
{
	int n,i,j,d,v,now;
	ll ans;
	while(~scanf("%d",&n))
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&d,&v);
			if(d>50000) ans+=v;
			else day[d].pb(v);
		}
	//	cout<<tot<<endl;
		priority_queue<int> q;
		now=0;
		for(i=50000;i>=1;i--)
		{
			if(sz(day[i]))
			{
				for(j=0;j<sz(day[i]);j++)
				{
					q.push(day[i][j]);
				}
				day[i].clear();
			}
			if(sz(q))
			{
				ans+=(ll)q.top();
				q.pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}