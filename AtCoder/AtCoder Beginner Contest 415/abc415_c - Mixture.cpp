#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
char s[MAX];
int vis[MAX];
int main()
{
	int T,n,i,t;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(i=0;i<=(1<<n);i++) vis[i]=0;
		queue<int> q;
		q.push(0);
		vis[0]=1;
		while(!q.empty())
		{
			t=q.front();
			q.pop();
			for(i=0;i<n;i++)
			{
				if(s[t|(1<<i)]=='1') continue;
				if(vis[t|(1<<i)]) continue;
				vis[t|(1<<i)]=1;
				q.push(t|(1<<i));
			}
		}
		if(vis[(1<<n)-1]) puts("Yes");
		else puts("No");
	}
	return 0;
}
