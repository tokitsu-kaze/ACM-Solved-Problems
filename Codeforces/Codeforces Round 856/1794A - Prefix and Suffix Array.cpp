#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=800+10;
vector<string> res[22];
int main()
{
	int T,n,i,ok;
	char s[22];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<n;i++) res[i].clear();
		for(i=1;i<=2*n-2;i++)
		{
			scanf("%s",s);
			res[strlen(s)].push_back(string(s));
		}
		ok=1;
		for(i=1;i<n;i++)
		{
			assert(res[i].size()==2);
			reverse(res[i][0].begin(),res[i][0].end());
			if(res[i][0]!=res[i][1]) ok=0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
