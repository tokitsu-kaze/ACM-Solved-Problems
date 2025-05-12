#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int n,i,ans;
	scanf("%d",&n);
	scanf("%s",s+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(i-1>=1)
		{
			if(s[i-1]=='0' && s[i]=='0')
			{
				ans++;
				s[i]='1';
			}
		}
		if(i-2>=1)
		{
			if(s[i-2]=='0' && s[i-1]=='1' && s[i]=='0')
			{
				ans++;
				s[i]='1';
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

