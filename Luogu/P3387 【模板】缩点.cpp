#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4e5+10;
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	void upd(int x,type v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr,tr2;
struct Z_Algorithm
{
	char s[MAX];
	int n,z[MAX],ex[MAX];
	void get_z_func(char *_s,int _n) // s[0..n-1]
	{
		int i,j,l,r;
		n=_n;
		memcpy(s,_s,n);
		z[0]=l=r=0;
		for(i=1;i<n;i++)
		{
			if(i+z[i-l]-1<r) z[i]=z[i-l];
			else
			{
				j=max(0,r-i+1);
				while(i+j<n&&s[i+j]==s[j]) j++;
				z[i]=j;
				if(i+z[i]-1>r)
				{
					l=i;
					r=i+z[i]-1;
				}
			}
		}
		z[0]=n;
	}
	void get_ex(char *t,int m) // t[0..m-1]
	{
		int i,j,l,r;
		j=l=0;
		while(j<n&&j<m&&t[j]==s[j]) j++;
		ex[0]=j;
		r=l+ex[0]-1;
		for(i=1;i<m;i++)
		{
			if(i+z[i-l]-1<r) ex[i]=z[i-l];
			else
			{
				j=max(0,r-i+1);
				while(i+j<m&&t[i+j]==s[j]) j++;
				ex[i]=j;
				if(i+ex[i]-1>r)
				{
					l=i;
					r=i+ex[i]-1;
				}
			}
		}
	}
}z;
/*
z[i]:  lcp(s,s[i..n-1]) i=0..n-1
ex[i]: lcp(s,t[i..m-1]) i=0..m-1

z.get_z_func(s,n) s[0..n-1]
z.get_ex(t,m) t[0..m-1]
*/
char s[MAX],t[MAX];
int pre[MAX],suf[MAX];
int main()
{
	int n,m,i,j,l,r;
	ll ans;
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	z.get_z_func(t+1,m);
	z.get_ex(s+1,n);
	for(i=1;i<=n;i++) pre[i]=min(z.ex[i-1],m-1);
	ans=0;
	for(i=1;i+m-1<=n;i++)
	{
		l=i;
		r=i+m-1;
		if(z.ex[i-1]!=m) continue;
		ans+=1ll*l*(l-1)/2;
		ans+=1ll*(n-r+1)*(n-r)/2;
	}
	reverse(t+1,t+1+m);
	reverse(s+1,s+1+n);
	z.get_z_func(t+1,m);
	z.get_ex(s+1,n);
	for(i=1;i<=n;i++) suf[i]=min(z.ex[i-1],m-1);
	reverse(suf+1,suf+1+n);
	tr.init(m);
	tr2.init(m);
	for(i=m+1;i<=n;i++)
	{
		if(pre[i-m])
		{
			tr.upd(pre[i-m],1);
			tr2.upd(pre[i-m],pre[i-m]);
		}
		ans+=tr2.ask(m-suf[i],m);
		ans+=tr.ask(m-suf[i],m)*(suf[i]-m+1);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
xxxxab xxxx baxxxx
    i        j

(i,pre[i])
(j,suf[j])
i<j
pre[i]+suf[j]>=m
j-i+1>m

*/
