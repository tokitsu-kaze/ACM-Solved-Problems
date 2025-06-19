#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX],t[MAX];
int main()
{
	int T,n,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		vector<int> res;
		for(i=1;i<n;i++)
		{
			if(s[i]=='1' && s[i+1]=='0')
			{
				res.push_back(i);
				s[i+1]^=1;
			}
		}
		for(i=n-1;i;i--)
		{
			if(s[i]=='1' && s[i+1]!=t[i+1])
			{
				res.push_back(i);
				s[i+1]^=1;
			}
		}
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(s[i]!=t[i]) ok=0;
		}
		if(ok)
		{
			printf("%d\n",(int)res.size());
			for(i=0;i<(int)res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
		}
		else puts("-1");
	}
	return 0;
}

