#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int n,d,i,cnt;
	char s[111];
	scanf("%d%d",&n,&d);
	scanf("%s",s);
	cnt=0;
	for(i=0;i<n;i++) cnt+=(s[i]=='@');
	printf("%d\n",n-cnt+min(cnt,d));
	return 0;
}
