#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4e5+10;
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
			for(i=n;i;i--)
			{
				sa[c[rk[tmp[i]]]--]=tmp[i];
				tmp[i]=0;
			}
			swap(rk,tmp);
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
	void work(char *_s,int _n) //s[1..n]
	{
		SZ=0; // char size
		n=_n;
		for(int i=1;i<=n;i++)
		{
			s[i]=_s[i];
			SZ=max(SZ,s[i]);
		}
		get_sa();
	}
}sa;
/*
sa[i]: s[sa[i]..n] rank is i
rk[i]: s[i..n] rank is rk[i]
h[i]: lcp(s[sa[i]..n],s[sa[i-1]..n])
lcp(s[i..n],s[j..n]) (i<j): min{h[i+1..j]}

sa.work(s,n) s[1..n]
*/
char a[MAX],b[MAX];
char s[MAX];
int st[MAX],lmn[MAX],rmn[MAX];
ll cal(int n)
{
	int top,i;
	ll res;
	top=0;
	for(i=n;i;i--) lmn[i]=0;
	for(i=n;i;i--)
	{
		while(top&&sa.h[st[top-1]]>sa.h[i])
		{
			lmn[st[top-1]]=i;
			top--;
		}
		st[top++]=i;
	}
	top=0;
	for(i=1;i<=n;i++) rmn[i]=n+1;
	for(i=1;i<=n;i++)
	{
		while(top&&sa.h[st[top-1]]>=sa.h[i])
		{
			rmn[st[top-1]]=i;
			top--;
		}
		st[top++]=i;
	}
//	for(i=1;i<=n;i++) printf("i sa[i] h[i]: %d %d %d\n",i,sa.sa[i],sa.h[i]);
	res=0;
	for(i=1;i<=n;i++)
	{
//		printf("i lmn[i] rmn[i]: %d %d %d\n",i,lmn[i],rmn[i]);
		res+=1ll*sa.h[i]*(i-lmn[i])*(rmn[i]-i);
	}
//	printf("res: %lld\n",res);
	return res;
}
int main()
{
	int n,n1,n2,i;
	ll ans;
	scanf("%s",a+1);
	scanf("%s",b+1);
	n1=strlen(a+1);
	n2=strlen(b+1);
	for(i=1;i<=n1;i++) s[i]=a[i];
	s[n1+1]='#';
	for(i=1;i<=n2;i++) s[n1+1+i]=b[i];
	n=n1+1+n2;
	sa.work(s,n);
	ans=cal(n);
	sa.work(a,n1);
	ans-=cal(n1);
	sa.work(b,n2);
	ans-=cal(n2);
	printf("%lld\n",ans);
	return 0;
}
