#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
char s[MAX];
int n;
int cal(char c)
{
	int i,tot,cnt,mx;
	tot=0;
	for(i=1;i<=n;i++) tot+=(s[i]==c);
	cnt=1;
	if(s[1]==c) mx=1;
	else mx=0;
	for(i=2;i<=n;i++)
	{
		if(s[i]==s[i-1]) cnt++;
		else cnt=1;
		if(s[i]==c) mx=max(mx,cnt);
	}
	return (n-mx)+(tot-mx);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		printf("%d\n",min(cal('0'),cal('1')));
	}
	return 0;
}
