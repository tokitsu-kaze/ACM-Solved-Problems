#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
char s[MAX],ans[MAX];
int vis[MAX];
int main()
{
	int T,n,i,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		vector<int> ra,rb;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='b')
			{
				if(ra.size()) ra.pop_back();
			}
			else if(s[i]=='B')
			{
				if(rb.size()) rb.pop_back();
			}
			else
			{
				if('a'<=s[i] && s[i]<='z') ra.push_back(i);
				else rb.push_back(i);
			}
		}
		for(i=1;i<=n;i++) vis[i]=0;
		for(auto &it:ra) vis[it]=1;
		for(auto &it:rb) vis[it]=1;
		tot=0;
		for(i=1;i<=n;i++)
		{
			if(vis[i]) ans[++tot]=s[i];
		}
		ans[tot+1]='\0';
		puts(ans+1);
	}
	return 0;
}
