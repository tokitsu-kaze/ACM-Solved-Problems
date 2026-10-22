#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
struct ST_table
{
	#define type int
	static const int N=MAX;
	static const int LOG=21;
	type v[N];
	int n,lg[N],bin[LOG],pmn[LOG][N];
	int pmin(const int &a,const int &b){return v[a]<v[b]?a:b;}
	void work(int _n,type *a)
	{
		int i,j;
		n=_n;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			pmn[0][i]=i;
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				pmn[j][i]=pmin(pmn[j-1][i],pmn[j-1][i+bin[j-1]]);
			}
		}
	}
	int ask_pmin(int l,int r)
	{
		assert(1<=l && l<=r && r<=n);
		int t=lg[r-l+1];
		return pmin(pmn[t][l],pmn[t][r-bin[t]+1]);
	}
	type ask_min(int l,int r){return v[ask_pmin(l,r)];}
	#undef type
}st;
int a[MAX];
int dfs(int l,int r,int now)
{
	if(l>r) return 0;
	if(l==r)
	{
		if(a[l]-now==0) return 0;
		return 1;
	}
	int pos=st.ask_pmin(l,r);
	return min(r-l+1,dfs(l,pos-1,a[pos])+dfs(pos+1,r,a[pos])+a[pos]-now);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	st.work(n,a);
	printf("%d\n",dfs(1,n,0));
	return 0;
}
/*
发现答案不超过 n，首先想到个 dp 做法。
dp[i][j] 表示 1..i 变成 0，前面有 j 个区间延申到当前。
这是能做的。

另外发现一个贪心性质：一个区间能用操作1尽量用，使用次数是区间 min。
这样的话，每次可以找到区间最小值，然后递归下去做。
发现是个笛卡尔树。

多倍经验：1400E，448C，P2101
*/
