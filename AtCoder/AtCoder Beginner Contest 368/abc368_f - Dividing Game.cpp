#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int sg[MAX];
set<int> s;
int dfs(int x)
{
	if(sg[x]!=-1) return sg[x];
	int i;
	set<int> del;
	for(i=1;i*i<=x;i++)
	{
		if(x%i) continue;
		if(i!=x) del.insert(dfs(i));
		if(x/i!=x) del.insert(dfs(x/i));
	}
	for(auto &it:del) s.erase(it);
	sg[x]=*s.begin();
	for(auto &it:del) s.insert(it);
	return sg[x];
}
int main()
{
	int n,i,ans,x;
	memset(sg,-1,sizeof sg);
	s.clear();
	for(i=0;i<=2e5;i++) s.insert(i);
	sg[0]=0;
	scanf("%d",&n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans^=dfs(x);
	}
	if(ans) puts("Anna");
	else puts("Bruno");
	return 0;
}
