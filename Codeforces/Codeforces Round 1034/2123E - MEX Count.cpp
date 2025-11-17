#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],cnt[MAX],tot[MAX];
int main()
{
	int T,n,i,now,mex,ret,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n+1;i++) cnt[i]=tot[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		for(i=0;i<=n;i++) tot[cnt[i]]++;
		mex=0;
		while(cnt[mex]) mex++;
		ret=0;
		for(i=mex+1;i<=n;i++) ret+=cnt[i];
		for(i=0;i<mex;i++) ret+=max(0,cnt[i]-1);
		for(i=mex+1;i<=n;i++) tot[cnt[i]]--;
		now=1;
		printf("%d",1);
		for(i=1;i<=n;i++)
		{
			now+=tot[i];
			k=max(0,i-ret);
			printf(" %d",max(1,now-k));
		}
		puts("");
	}
	return 0;
}
/*
出现次数>1 和 >mex 的数随便删
有剩余的删除次数，比如剩k，答案就是 now-k
*/
