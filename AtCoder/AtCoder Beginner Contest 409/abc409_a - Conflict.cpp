#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n,i,ok;
	char s[105],t[105];
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	ok=0;
	for(i=1;i<=n;i++) ok|=(s[i]=='o' && s[i]==t[i]);
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
