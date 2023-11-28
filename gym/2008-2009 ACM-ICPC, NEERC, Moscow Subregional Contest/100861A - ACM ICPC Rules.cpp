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
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,ans[111],cnt;
	string a[111],b[111];
	while(~scanf("%d",&n))
	{
		map<string,int> mp;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
			if(a[i]=="SCH") continue;
			else if(a[i]=="MSU")
			{
				if(mp[a[i]]<4) ans[cnt++]=i;
				mp[a[i]]++;
			}
			else
			{
				if(mp[a[i]]<2) ans[cnt++]=i;
				mp[a[i]]++;
			}
			
		}
		cout<<min(cnt,10)<<endl;
		for(i=0;i<min(cnt,10);i++)
		{
			cout<<a[ans[i]]<<" "<<b[ans[i]]<<endl;
		}
	}
	return 0;
}