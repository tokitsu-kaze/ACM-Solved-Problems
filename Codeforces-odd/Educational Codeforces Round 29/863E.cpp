#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
struct node
{
	int l,r;
	void input()
	{
		scanf("%d%d",&l,&r);
	}
}a[MAX];
map<int,int> mp;
map<int,int> ::iterator it;
vector<int> v;
int main()
{
	int n,i,now,flag;
	while(~scanf("%d",&n))
	{
		mp.clear();
		for(i=0;i<n;i++)
		{
			a[i].input();
			mp[a[i].l]++;
			mp[a[i].r+1]--;
		}
		v.clear();
		now=0;
		for(it=mp.begin();it!=mp.end();it++)
		{
			now+=it->se;
			if(now==1) v.pb(it->fi);
		}
		if(!sz(v))
		{
			puts("1");
			continue;
		}
		v.pb(INF);
		sort(v.begin(),v.end());
		flag=0;
		for(i=0;i<n;i++)
		{
			int temp=*lower_bound(v.begin(),v.end(),a[i].l);
			if(temp==INF||temp>a[i].r)
			{
				printf("%d\n",i+1);
				flag=1;
				break;
			}
		}
		if(!flag) puts("-1"); 
	}
	return 0;
}