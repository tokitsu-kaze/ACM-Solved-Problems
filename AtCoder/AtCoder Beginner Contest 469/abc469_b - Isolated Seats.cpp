#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int n,i,cnt;
	char s[105];
	scanf("%d",&n);
	scanf("%s",s+1);
	s[0]=s[n+1]='x';
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(s[i-1]=='x' && s[i]=='x' && s[i+1]=='x') cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
