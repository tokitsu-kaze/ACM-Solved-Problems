#include <bits/stdc++.h>
using namespace std;
string tmp="AGCT";
char s[11][11];
int n,pos[11],len[11],ok,ans,id[266];
void dfs(int x)
{
	if(x>ans) return;
	if(ok) return;
	int i,j,cnt,prepos[11],retcnt[5],retmx[5],retsum;
	cnt=0;
	memset(retmx,0,sizeof retmx);
	for(i=0;i<n;i++)
	{
		if(pos[i]==len[i]) cnt++;
		prepos[i]=pos[i];
		memset(retcnt,0,sizeof retcnt);
		for(j=pos[i];j<len[i];j++)
		{
			retcnt[id[s[i][j]]]++;
		}
		for(j=0;j<4;j++) retmx[j]=max(retmx[j],retcnt[j]);
	}
	if(cnt==n)
	{
		ok=1;
		return;
	}
	retsum=0;
	for(i=0;i<4;i++) retsum+=retmx[i];
	if(x+retsum>ans) return;
	for(auto &ch:tmp)
	{
		if(ok) return;
		for(i=0;i<n;i++)
		{
			if(pos[i]==len[i]) continue;
			if(s[i][pos[i]]==ch) pos[i]++;
		}
		dfs(x+1);
		for(i=0;i<n;i++) pos[i]=prepos[i];
	}
}
int main()
{
	int t,i;
	memset(id,0,sizeof id);
	for(i=0;i<4;i++) id[tmp[i]]=i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
			len[i]=strlen(s[i]);
		}
		ans=0;
		while(1)
		{
			ans++;
	//		printf("%d\n",ans);
			ok=0;
			memset(pos,0,sizeof pos);
			dfs(0);
			if(ok) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
4
AAAA
CCCC
GGGG
TTTT
*/
