#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX];
int main()
{
	int T,n,i,ra,rb,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		ra=0;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]-'0'!=(i&1)) cnt=1;
			else
			{
				ra+=cnt;
				cnt=0;
			}
		}
		ra+=cnt;
		
		rb=0;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]-'0'!=(!(i&1))) cnt=1;
			else
			{
				rb+=cnt;
				cnt=0;
			}
		}
		rb+=cnt;
		printf("%d\n",min(ra,rb));
	}
	return 0;
}
