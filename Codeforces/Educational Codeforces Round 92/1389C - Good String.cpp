#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,x,y,ans,now;
	char tmp[3];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		for(x='0';x<='9';x++)
		{
			for(y='0';y<='9';y++)
			{
				tmp[0]=x;
				tmp[1]=y;
				now=0;
				for(i=1;i<=n;i++)
				{
					if(s[i]==tmp[now&1]) now++;
				}
				if(x!=y) now-=(now&1);
				ans=max(ans,now);
			}
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
/*
看着是要变成 xyxy 形式，x可以=y，不等的时候需要长度是偶数。
*/
