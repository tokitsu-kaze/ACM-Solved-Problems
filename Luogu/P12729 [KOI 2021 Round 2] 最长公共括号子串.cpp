#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
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
struct Suffix_Array
{
	int s[MAX],n,SZ;
	int c[MAX],rk[MAX],tmp[MAX],sa[MAX],h[MAX];
	void get_sa()
	{
		int m,i,j,k,tot;
		m=SZ;
		for(i=1;i<=m;i++) c[i]=0;
		for(i=1;i<=n;i++) c[rk[i]=s[i]]++;
		for(i=2;i<=m;i++) c[i]+=c[i-1];
		for(i=n;i;i--) sa[c[rk[i]]--]=i;
		for(k=1;k<=n;k<<=1)
		{
			tot=0;
			for(i=n-k+1;i<=n;i++) tmp[++tot]=i;
			for(i=1;i<=n;i++)
			{
				if(sa[i]>k) tmp[++tot]=sa[i]-k;
			}
			for(i=1;i<=m;i++) c[i]=0;
			for(i=1;i<=n;i++) c[rk[i]]++;
			for(i=2;i<=m;i++) c[i]+=c[i-1];
			for(i=n;i;i--) sa[c[rk[tmp[i]]]--]=tmp[i];
			for(i=1;i<=n;i++) tmp[i]=rk[i];
			rk[sa[1]]=1;
			tot=1;
			for(i=2;i<=n;i++)
			{
				if(sa[i]+k>n||sa[i-1]+k>n||
				   (!(tmp[sa[i]]==tmp[sa[i-1]]&&
					  tmp[sa[i]+k]==tmp[sa[i-1]+k]))) tot++;
				rk[sa[i]]=tot;
			}
			if(tot==n) break;
			m=tot;
		}
	}
	void get_height()
	{
		int i,j,k;
		h[1]=0;
		k=0;
		for(i=1;i<=n;i++)
		{
			if(rk[i]==1) continue;
			if(k>0) k--;
			j=sa[rk[i]-1];
			while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k]) k++;
			h[rk[i]]=k;
		}
	}
	void work(int _n,char *_s) //s[1..n]
	{
		SZ=0; // char size
		n=_n;
		for(int i=1;i<=n;i++)
		{
			s[i]=_s[i];
			SZ=max(SZ,s[i]);
		}
		get_sa();
		get_height();
	}
}sa;
/*
sa[i]: s[sa[i]..n] rank is i
rk[i]: s[i..n] rank is rk[i]
h[i]: lcp(s[sa[i]..n],s[sa[i-1]..n])
lcp(s[i..n],s[j..n]) (i<j): min{h[i+1..j]}

sa.work(n,s) s[1..n]
*/
int sum[MAX];
char a[MAX],b[MAX],s[MAX];
vector<int> pos[2*MAX];
const int D=1e6+1;
int ck(int l,int r,int x)
{
	if(l>r) return 0;
	return st.ask_min(l,r)>=x-D;
}
int main()
{
	int T,n,m,i,l,r,mid,ans,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",a+1,b+1);
		n=strlen(a+1);
		m=strlen(b+1);
		for(i=1;i<=n;i++) s[i]=a[i];
		s[n+1]='#';
		for(i=1;i<=m;i++) s[n+1+i]=b[i];
		for(i=-(n+m+1);i<=n+1+m;i++) pos[i+D].clear();
		sum[0]=0;
		pos[sum[0]+D].push_back(0);
		for(i=1;i<=n+1+m;i++)
		{
			sum[i]=sum[i-1];
			if(s[i]=='(') sum[i]++;
			else if(s[i]==')') sum[i]--;
			pos[sum[i]+D].push_back(i);
		}
		st.work(n+1+m,sum);
		sa.work(n+1+m,s);
		ans=0;
		for(i=2;i<=n+1+m;i++)
		{
			if(sa.sa[i-1]<=n+1 && sa.sa[i]<=n+1) continue;
			if(sa.sa[i-1]>n+1 && sa.sa[i]>n+1) continue;
			x=D+sum[sa.sa[i]-1];
			l=lower_bound(pos[x].begin(),pos[x].end(),sa.sa[i]-1)-pos[x].begin();
			assert(pos[x][l]==sa.sa[i]-1);
			r=upper_bound(pos[x].begin(),pos[x].end(),sa.sa[i]-1+sa.h[i])-pos[x].begin()-1;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(ck(sa.sa[i],pos[x][mid+1],x)) l=mid+1;
				else r=mid;
			}
			if(ck(sa.sa[i],pos[x][l],x)) ans=max(ans,pos[x][l]-sa.sa[i]+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
考虑把 公共子串 和 合法括号子串 这两个限制分开处理。
先考虑公共子串：sa 经典应用。
再考虑合法括号子串：
先按括号序列套路，左括号是 1，右括号是 -1，做个前缀和。
用 vector 记录每种前缀和出现的位置。
在枚举 rank 相邻的两个串时，公共子串长度即为 height[i]，
当然需要判断一下这两个串是否分别是两个串的后缀。
找到子串前一位的前缀和，在该 vector 中二分长度不超过 height[i]，
并且区间中不存在小于该前缀和的数 的第一个位置，这个用 ST表 判断。
即能当前后缀的最长公共合法括号子串，对答案取 max 即可。
*/
