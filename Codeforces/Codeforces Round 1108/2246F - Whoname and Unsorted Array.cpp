#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int n,p[MAX],pos[MAX];
vector<int> ans;
void work(int x)
{
	int i,t;
	t=p[x];
	for(i=x;i>=2;i--) p[i]=p[i-1];
	p[1]=t;
	t=p[x+1];
	for(i=x+1;i<n;i++) p[i]=p[i+1];
	p[n]=t;
	for(i=1;i<=n;i++) pos[p[i]]=i;
	ans.push_back(x);
}
int main()
{
	int T,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			pos[p[i]]=i;
		}
		ans.clear();
		for(i=2;i<n;i++)
		{
			if(pos[i]!=1) work(pos[i]-1);
			else
			{
				work(2);
				work(1);
				work(n-1);
			}
		}
		ok=1;
		if(pos[n]!=1) work(pos[n]-1);
		else
		{
			if(n&1)
			{
				for(i=1;i<=n-2;i++) work(2);
				work(1);
			}
			else ok=0;
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		printf("%d\n",(int)ans.size());
		for(i=0;i<ans.size();i++) printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
	}
	return 0;
}
