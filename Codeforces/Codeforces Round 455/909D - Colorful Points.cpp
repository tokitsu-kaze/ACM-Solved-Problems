#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int l[MAX],r[MAX];
int vis[MAX];
char s[MAX];
int main()
{
	int n,i,ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	vector<int> now;
	s[0]=s[1];
	s[n+1]=s[n];
	for(i=1;i<=n;i++)
	{
		vis[i]=0;
		l[i]=i-1;
		r[i]=i+1;
		if(s[i]!=s[i-1] || s[i]!=s[i+1])
		{
			now.push_back(i);
			vis[i]=1;
		}
	}
	ans=0;
	while(now.size()>0)
	{
		ans++;
		vector<int> tmp;
		for(auto &x:now)
		{
			l[r[x]]=l[x];
			r[l[x]]=r[x];
			tmp.push_back(l[x]);
			tmp.push_back(r[x]);
		}
		now.clear();
		for(auto &x:tmp)
		{
			if(x<1||x>n) continue;
			if(vis[x]) continue;
			if((l[x]>=1 && s[l[x]]!=s[x]) ||
			   (r[x]<=n && s[r[x]]!=s[x]))
			{
				now.push_back(x);
				vis[x]=1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
