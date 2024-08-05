#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=59049+10;
int S,k;
char op[505][11];
int dp[2][MAX],vis[2][MAX];
int cal(int s,int id)
{
	int i,sd,a[11],res;
	for(i=k-1;~i;i--)
	{
		a[i]=s%3;
		s/=3;
	}
	reverse(a,a+k);
	sd=1;
	res=0;
	for(i=0;i<k;i++)
	{
		if(op[id][i]=='+')//2->0, 0->1, 1->2
		{
			a[i]++;
			if(a[i]==3) a[i]=0;
		}
		else if(op[id][i]=='-')//0->2, 1->0, 2->1
		{
			a[i]--;
			if(a[i]<0) a[i]+=3;
		}
		res+=a[i]*sd;
		sd*=3;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,n,mod,i,j,f,s,nex,a[11],tmp;
	char res[11];
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>mod;
		for(i=1;i<=n;i++) cin>>op[i];
		S=1;
		for(i=0;i<k;i++) S*=3;
		assert(S<=MAX);
		f=0;
		for(j=0;j<S;j++) dp[f][j]=vis[f][j]=0;
		dp[f][0]=1;
		vis[f][0]=1;
		for(i=1;i<=n;i++)
		{
			f^=1;
			for(j=0;j<S;j++) dp[f][j]=vis[f][j]=0;
			for(s=0;s<S;s++)
			{
				nex=cal(s,i);
				vis[f][s]|=vis[!f][s];
				dp[f][s]+=dp[!f][s];
				if(dp[f][s]>=mod) dp[f][s]-=mod;
				vis[f][nex]|=vis[!f][s];
				dp[f][nex]+=dp[!f][s];
				if(dp[f][nex]>=mod) dp[f][nex]-=mod;
			}
		}
		vector<pair<string,int>> ans;
		for(s=0;s<S;s++)
		{
			if(!vis[f][s]) continue;
			tmp=s;
			for(i=k-1;~i;i--)
			{
				a[i]=tmp%3;
				tmp/=3;
			}
			reverse(a,a+k);
			for(i=0;i<k;i++) res[i]='A'+a[i];
			res[k]='\0';
			ans.push_back({res,dp[f][s]});
		}
		sort(ans.begin(),ans.end());
		for(auto &it:ans) cout<<it.first<<" "<<it.second<<"\n";
	}
	return 0;
}
