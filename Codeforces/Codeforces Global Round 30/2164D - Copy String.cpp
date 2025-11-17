#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
char s[MAX],t[MAX];
int pre[MAX];
int main()
{
	int T,n,k,i,j,ok,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		scanf("%s",t+1);
		if(s[1]!=t[1])
		{
			puts("-1");
			continue;
		}
		vector<int> pos[26];
		for(i=1;i<=n;i++) pos[s[i]-'a'].push_back(i);
		now=n;
		ok=1;
		for(i=n;i;i--)
		{
			auto it=upper_bound(pos[t[i]-'a'].begin(),pos[t[i]-'a'].end(),min(i,now));
			if(it==pos[t[i]-'a'].begin())
			{
				ok=0;
				break;
			}
			it--;
			if(*it>now)
			{
				ok=0;
				break;
			}
			now=*it;
			pre[i]=now;
//			cout<<i<<" "<<now<<endl;
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		vector<string> res;
		while(k--)
		{
			ok=1;
			for(i=1;i<=n;i++)
			{
				if(s[i]!=t[i]) ok=0;
			}
			if(ok) break;
			for(i=n;i>1;i--)
			{
				if(pre[i]<i)
				{
					pre[i]++;
					s[i]=s[i-1];
				}
			}
			res.push_back(string(s+1));
		}
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(s[i]!=t[i]) ok=0;
		}
		if(!ok) puts("-1");
		else
		{
			printf("%d\n",res.size());
			for(auto &it:res) puts(it.c_str());
		}
	}
	return 0;
}
