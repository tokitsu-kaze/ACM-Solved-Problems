#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
char mp[1010][1010];
int main()
{
	int T,n,m,i,j,k,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
		ans=0;
		for(k=0;1+k<=n-k && 1+k<=m-k;k++)
		{
			string tmp="";
			for(i=1+k;i<=m-k;i++) tmp.push_back(mp[1+k][i]);
			tmp.pop_back();
			for(i=1+k;i<=n-k;i++) tmp.push_back(mp[i][m-k]);
			tmp.pop_back();
			for(i=m-k;i>=1+k;i--) tmp.push_back(mp[n-k][i]);
			tmp.pop_back();
			for(i=n-k;i>=1+k;i--) tmp.push_back(mp[i][1+k]);
			tmp.pop_back();
//			cout<<tmp<<endl;
			tmp.push_back(tmp[0]);
			tmp.push_back(tmp[1]);
			tmp.push_back(tmp[2]);
			for(i=3;i<tmp.size();i++)
			{
				if(tmp[i-3]=='1' &&
				   tmp[i-2]=='5' &&
				   tmp[i-1]=='4' &&
				   tmp[i]=='3') ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
