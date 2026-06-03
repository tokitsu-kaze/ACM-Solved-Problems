#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
int mn[MAX],a[MAX],del[MAX],tot;
int main()
{
	int n,i,j,k,now,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=0;
	for(j=0;j<=20;j++)
	{
		memset(mn,0x3f,sizeof mn);
		now=0;
		mn[now]=0;
		tot=0;
		for(i=1;i<=n;i++)
		{
			if(!((a[i]>>j)&1))
			{
				for(k=0;k<tot;k++) mn[del[k]]=INF;
				tot=0;
				mn[0]=i;
				now=0;
				continue;
			}
			now^=(a[i]>>j);
			if(mn[now]<=n) ans=max(ans,i-mn[now]);
			else mn[now]=i;
			del[tot++]=now;
//			printf("%d %d %d %d\n",j,i,now,ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
要找到至少一位 p 全有并且是偶数，比 p 高的位需要都是偶数，比 p 低的位可以任意。
长度要是偶数。
>=p的部分，xor=0。
枚举p，做前缀xor，对下标分奇偶，放map。
噢好像不用对下标分奇偶，只要xor=0默认就是偶数。
*/
