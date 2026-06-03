#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int n,be;
	char s[55];
	scanf("%d",&n);
	scanf("%s",s+1);
	be=1;
	while(be<=n && s[be]=='o') be++;
	s[n+1]='\0';
	puts(s+be);
	return 0;
}
