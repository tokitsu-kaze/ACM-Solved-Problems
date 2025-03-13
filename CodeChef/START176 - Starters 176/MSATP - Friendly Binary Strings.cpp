#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
char a[MAX],b[MAX];
int main()
{
	int T,i,n,cnt,ban[2];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		memset(ban,0,sizeof ban);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==b[i]) ban[a[i]-'0']++;
			else cnt++;
		}
		ban[0]&=1;
		ban[1]&=1;
		cnt&=1;
		if(ban[0]+ban[1]+cnt>1) puts("NO");
		else puts("YES");
	}
	return 0;
}
