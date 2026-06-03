#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int K=3;
set<int> pos[3];
char s[MAX];
int main()
{
	int n,i,ans,b,c;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=0;i<3;i++) pos[i].clear();
	for(i=1;i<=n;i++) pos[s[i]-'A'].insert(i);
	for(i=0;i<3;i++) pos[i].insert(n+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]!='A') continue;
		b=*pos[1].lower_bound(i);
		c=*pos[2].lower_bound(b);
		if(b<=n && c<=n)
		{
			pos[1].erase(b);
			pos[2].erase(c);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
