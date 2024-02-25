#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int t,i,cnt;
	string s;
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		cnt=0;
		for(i=0;i<3;i++) cnt+=(s[i]-'a'==i);
		if(cnt==1||cnt==3) puts("YES");
		else puts("NO");
	}
	return 0;
}
