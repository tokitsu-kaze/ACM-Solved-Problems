#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=505+10;
char s[MAX];
int main()
{
	int n,i,j,cnt;
	scanf("%d",&n);
	cnt=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		for(j=0;j<n;j++) cnt+=(s[j]=='#');
	}
	cnt&=1;
	if(cnt==0) puts("Yes");
	else
	{
		if(n&1) puts("Yes");
		else puts("No");
	}
	return 0;
}
