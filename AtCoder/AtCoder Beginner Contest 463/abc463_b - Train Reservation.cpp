#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;

int main()
{
	int n,i,j,ok;
	char s[3],mp[105][7];
	scanf("%d%s",&n,s);
	for(i=0;i<n;i++) scanf("%s",mp[i]);
	ok=0;
	for(i=0;i<n;i++)
	{
		if(mp[i][s[0]-'A']=='o') ok=1;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
