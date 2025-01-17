#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int n,i,cnt;
	char s[1010];
	scanf("%s",s+1);
	n=strlen(s+1);
	cnt=n;
	for(i=2;i<=n;i++)
	{
		if(s[i]==s[i-1] && s[i]=='0')
		{
			cnt--;
			i++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
