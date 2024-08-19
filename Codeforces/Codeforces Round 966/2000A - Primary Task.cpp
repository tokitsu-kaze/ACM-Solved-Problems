#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
int main()
{
	int t;
	char s[11];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		if(strlen(s)<3)
		{
			puts("NO");
			continue;
		}
		if(s[0]!='1'||s[1]!='0')
		{
			puts("NO");
			continue;
		}
		if(strlen(s)==3 && s[2]<'2')
		{
			puts("NO");
			continue;
		}
		if(s[2]!='0') puts("YES");
		else puts("NO");
	}
	return 0;
}
