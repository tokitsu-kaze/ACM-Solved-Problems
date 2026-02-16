#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int K=26;
int nex[MAX][K],pre[MAX][K];
void work(char *s,int len)
{
	for(int i=0;i<K;i++) pre[1][i]=pre[0][i]=0;
	for(int i=1;i<=len;i++)
	{
		for(int j=0;j<K;j++)
		{
			pre[i+1][j]=pre[i][j];
		}
		pre[i+1][s[i]-'a']=i;
	}
	
	for(int i=0;i<K;i++) nex[len][i]=nex[len+1][i]=len+1;
	for(int i=len;i;i--)
	{
		for(int j=0;j<K;j++)
		{
			nex[i-1][j]=nex[i][j];
		}
		nex[i-1][s[i]-'a']=i;
	}
}
char s[MAX];
int cnt[MAX][26],a[MAX];
int main()
{
	int n,i,j,q,op,x,y,lst;
	ll ans;
	scanf("%d",&n);
	scanf("%s",s+1);
	work(s,n);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		cnt[i][s[i]-'a']++;
		for(j=0;j<26;j++) cnt[i][j]+=cnt[i-1][j];
	}
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1) a[x]=y;
		else
		{
			ans=0;
			for(i=0;i<26;i++)
			{
				if((cnt[y][i]-cnt[x-1][i])%2==0) continue;
				lst=pre[y+1][i];
				ans+=a[lst];
				for(j=0;j<26;j++)
				{
					if(j==i) continue;
					if(cnt[y][j]-cnt[x-1][j]<=1) continue;
					if(((cnt[lst][j]-cnt[x-1][j])&1) && nex[lst][j]<=y)
					{
						ans-=a[lst];
						break;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
每种字母最多留一个，而且留的是固定的最后一个。
只要留下的那个考虑会不会被其他字母删掉的区间覆盖到。
删掉的区间会有很多段，如果一个位置不在区间内，
对于其他字符，要保证 不存在：左边出现奇数次且右边有。
用前缀和和序列机能做到O(nC^2)，常数小，先试试。
*/
