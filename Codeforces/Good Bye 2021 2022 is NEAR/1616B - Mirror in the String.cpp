#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX],ans[MAX];
int main()
{
	int T,n,i,p,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		if(n==1 || (n>1 && s[1]==s[2]))
		{
			printf("%c%c\n",s[1],s[1]);
			continue;
		}
		p=n;
		for(i=1;i<n;i++)
		{
			if(s[i]<s[i+1])
			{
				p=i;
				break;
			}
		}
		for(i=1;i<=p;i++) ans[i]=s[i];
		tot=p;
		for(i=p;i;i--) ans[++tot]=s[i];
		ans[tot+1]='\0';
		puts(ans+1);
	}
	return 0;
}
/*
s[i]<s[i+1]情况很显然；
s[i]==s[i+1]，手玩发现：
- 要么s[1]==s[2]，
- 要么不存在s[i]<s[i+1]就取到末尾，
  因为前面一定是非递增的，当前这个是最小的，越长越好。
*/
