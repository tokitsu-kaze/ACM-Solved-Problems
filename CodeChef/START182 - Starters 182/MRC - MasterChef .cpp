#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,k,i,ok,cnt,now,f,ff,tag;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		ok=1;
		now=1;
		cnt=0;
		string tmp;
		f=0;
		vector<int> pos[2];
		pos[f].push_back(0);
		f^=1;
		for(i=2;i<=n;i++)
		{
			if(s[i]==s[i-1]) now++;
			else
			{
				if(now>=k)
				{
					cnt++;
					tmp+=s[i-1];
					ff=f;
				}
				pos[f].push_back(now);
				f^=1;
				if(now>=k*2-1) ok=0;
				now=1;
			}
		}
		if(now>=k)
		{
			cnt++;
			tmp+=s[n];
			ff=f;
		}
		pos[f].push_back(now);
		f^=1;
		pos[f].push_back(0);
		if(now>=k*2-1) ok=0;
		if(cnt>=3) ok=0;
		if(now==n && now>=k) ok=0;
		if(cnt==2 && tmp[0]==tmp[1]) ok=0;
		if(ok && cnt==1)
		{
			tag=0;
			for(auto &it:pos[!ff])
			{
				if(it>=2) tag=1;
			}
			if(!tag)
			{
				sort(pos[ff].begin(),pos[ff].end());
				if(pos[ff].size()>1 && pos[ff][0]+pos[ff].back()>=2*k-1) ok=0;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}

