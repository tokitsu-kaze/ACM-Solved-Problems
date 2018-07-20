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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,j,len,ans;
	char a[111];
	while(~scanf("%d",&n))
	{
		map<string,int> flag;
		map<string,pair<int,int> > mp;
		map<string,pair<int,int> > ::iterator it;
		for(j=0;j<n;j++)
		{
			flag.clear();
			scanf("%s",a);
			len=strlen(a);
			mp[a].fi++;
			flag[a]=1;
			for(i=1;i<len;i++)
			{
				a[len+i-1]=a[i-1];
				a[len+i]='\0';
	//			cout<<a+i<<endl;
				if(flag[a+i]) continue;
				mp[a+i].fi++;
				mp[a+i].se+=i;
				flag[a+i]=1;
			}
		}
		ans=INF;
		for(it=mp.begin();it!=mp.end();it++)
		{
			if(it->se.fi==n) ans=min(ans,it->se.se);
		}
		if(ans==INF) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}