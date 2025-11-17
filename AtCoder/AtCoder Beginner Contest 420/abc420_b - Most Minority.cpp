#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[105][105];
int main()
{
	int n,m,i,j,cnt[105],a,b,mx;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",s[i]+1);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=m;i++)
	{
		a=b=0;
		for(j=1;j<=n;j++)
		{
			if(s[j][i]=='0') a++;
			else b++;
		}
		if(a==0||b==0)
		{
			for(j=1;j<=n;j++) cnt[j]++;
			continue;
		}
		if(a<b)
		{
			for(j=1;j<=n;j++)
			{
				if(s[j][i]=='0') cnt[j]++;
			}
		}
		else
		{
			for(j=1;j<=n;j++)
			{
				if(s[j][i]=='1') cnt[j]++;
			}
		}
	}
	vector<int> res;
	mx=0;
	for(i=1;i<=n;i++) mx=max(mx,cnt[i]);
	for(i=1;i<=n;i++)
	{
		if(cnt[i]==mx) res.push_back(i);
	}
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	return 0;
}
