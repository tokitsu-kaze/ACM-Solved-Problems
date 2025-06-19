#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int mp[MAX][MAX],up[MAX][MAX],l[MAX],r[MAX];
int st[MAX],top;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,n,m,i,j,ans;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>mp[i][j];
			}
		}
		memset(up[0],0,sizeof up[0]);
		for(j=1;j<=m;j++)
		{
			for(i=1;i<=n;i++)
			{
				if(i>1 && mp[i][j]>=mp[i-1][j]) up[i][j]=up[i-1][j]+1;
				else up[i][j]=1;
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			top=0;
			up[i][m+1]=-1;
			for(j=1;j<=m+1;j++)
			{
				while(top&&up[i][st[top-1]]>up[i][j])
				{
					r[st[top-1]]=j-1;
					top--;
				}
				st[top++]=j;
			}
			top=0;
			up[i][0]=-1;
			for(j=m;~j;j--)
			{
				while(top&&up[i][st[top-1]]>up[i][j])
				{
					l[st[top-1]]=j+1;
					top--;
				}
				st[top++]=j;
			}
			for(j=1;j<=m;j++) ans=max(ans,up[i][j]*(r[j]-l[j]+1));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
