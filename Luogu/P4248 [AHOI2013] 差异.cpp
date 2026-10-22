#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int st[MAX];
void workl(int *x,int n,int *l)
{
	int i,top;
	top=0;
	for(i=n;i;i--)
	{
		while(top && x[st[top-1]]>=x[i]) l[st[--top]]=i;
		st[top++]=i;
	}
	while(top>0) l[st[--top]]=0;
}
void workr(int *x,int n,int *r)
{
	int i,top;
	top=0;
	for(i=1;i<=n;i++)
	{
		while(top && x[st[top-1]]>x[i]) r[st[--top]]=i;
		st[top++]=i;
	}
	while(top>0) r[st[--top]]=n+1;
}
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

sa.work(n,s) s[1..n]  O((n+charsize)*log n)
*/
char s[MAX];
int l[MAX],r[MAX];
int main()
{
	int n,i;
	ll ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	sa.work(n,s);
	workl(sa.h,n,l);
	workr(sa.h,n,r);
	ans=1LL*(n-1)*n*(n+1)/2;
	for(i=2;i<=n;i++) ans-=2LL*(i-l[i])*(r[i]-i)*sa.h[i];
	printf("%lld\n",ans);
	return 0;
}
