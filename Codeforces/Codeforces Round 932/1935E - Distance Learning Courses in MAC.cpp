#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct ST_table
{
	#define type int
	static const int N=MAX;
	static const int LOG=21;
	type v[N],orsum[LOG][N];
	int lg[N],bin[LOG];
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			orsum[0][i]=v[i];
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				orsum[j][i]=orsum[j-1][i]|orsum[j-1][i+bin[j-1]];
			}
		}
	}
	int ask_orsum(int l,int r)
	{
		int t=lg[r-l+1];
		return orsum[t][l]|orsum[t][r-bin[t]+1];
	}
	#undef type
}st;
int sum[MAX][32],v[MAX],ans[MAX];
int main()
{
	int T,n,q,l,r,x,y,i,j,p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(sum[0],0,sizeof sum[0]);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			v[i]=0;
			p=-1;
			for(j=30;~j;j--)
			{
				if(((x>>j)&1)!=((y>>j)&1))
				{
					p=j;
					break;
				}
				if(((x>>j)&1)) v[i]|=(1<<j);
			}
			for(j=0;j<=p;j++) sum[i][j]=sum[i-1][j]+((y>>j)&1);
			for(j=p+1;j<=30;j++) sum[i][j]=sum[i-1][j];
		}
		st.work(n,v);
		scanf("%d",&q);
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&l,&r);
			ans[i]=st.ask_orsum(l,r);
			for(j=30;~j;j--)
			{
				x=sum[r][j]-sum[l-1][j];
				if(x==0) continue;
				if(x==1)
				{
					if((ans[i]>>j)&1)
					{
						ans[i]|=((1<<j)-1);
						break;
					}
					else ans[i]|=(1<<j);
				}
				else
				{
					ans[i]|=((1<<j+1)-1);
					break;
				}
			}
		}
		for(i=1;i<=q;i++) printf("%d%c",ans[i]," \n"[i==q]);
	}
	return 0;
}
/*
x y 相同的高位肯定计入答案，找到第一个不同的位 p。
这样 x 就没用了， 记录 y 中 <=p 的位的 1 的个数：
如果 恰好 1 个 1，且答案这一位为 0，那么只能选这一位为 1；
如果 >=2 个 1，或者恰好 1 个 1 且 答案这一位为 1，那么后面全部位都能为 1。
因为一定能把 y 中 <=p 的位变成 0，且 y 的第 p 位一定为 1。 
*/
