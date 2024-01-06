#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
void assert_range(ll x,ll l,ll r){assert(x>=l&&x<=r);}
int a[55],now[55],n,ok,len;
char s[55];
void cal()
{
	int i,j;
	for(i=2;i<=n;i++) now[i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			now[j-i+1]+=(s[i]=='0'&&s[j]=='1');
		}
	}
}
int ck()
{
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=now[i]) return 0;
	}
	return 1;
}
void dfs(int l,int r)
{
	if(ok) return;
	int i;
/*	printf("%d %d\n",l,r);
	for(i=2;i<=n;i++) printf("%d ",now[i]);
	puts("");
	puts(s+1);*/
	for(i=2;i<=n;i++)
	{
		if(now[i]>a[i]) return;
	}
	if(l>r)
	{
		if(ck()) ok=1;
		return;
	}
	if(l==r)
	{
		s[l]='0';
		for(i=l+1;i<=n;i++) now[i-l+1]+=(s[i]=='1');
		dfs(l+1,r);
		if(ok) return;
		for(i=l+1;i<=n;i++) now[i-l+1]-=(s[i]=='1');
		
		s[l]='1';
		for(i=1;i<l;i++) now[l-i+1]+=(s[i]=='0');
		dfs(l+1,r);
		if(ok) return;
		for(i=1;i<l;i++) now[l-i+1]-=(s[i]=='0');
		return;
	}
	if(a[len-l+1]-now[len-l+1]==0)
	{
		s[l]='1';
		s[r]='0';
		for(i=1;i<l;i++) now[l-i+1]+=(s[i]=='0');
		for(i=r+1;i<=n;i++) now[i-r+1]+=(s[i]=='1');
		dfs(l+1,r-1);
		if(ok) return;
		for(i=1;i<l;i++) now[l-i+1]-=(s[i]=='0');
		for(i=r+1;i<=n;i++) now[i-r+1]-=(s[i]=='1');
		return;
	}
	if(a[len-l+1]-now[len-l+1]==1)
	{
		s[l]='1';
		s[r]='1';
		for(i=1;i<l;i++)
		{
			now[l-i+1]+=(s[i]=='0');
			now[r-i+1]+=(s[i]=='0');
		}
		dfs(l+1,r-1);
		if(ok) return;
		for(i=1;i<l;i++)
		{
			now[l-i+1]-=(s[i]=='0');
			now[r-i+1]-=(s[i]=='0');
		}
		
		s[l]='0';
		s[r]='0';
		for(i=r+1;i<=n;i++)
		{
			now[i-l+1]+=(s[i]=='1');
			now[i-r+1]+=(s[i]=='1');
		}
		dfs(l+1,r-1);
		if(ok) return;
		for(i=r+1;i<=n;i++)
		{
			now[i-l+1]-=(s[i]=='1');
			now[i-r+1]-=(s[i]=='1');
		}
		return;
	}
	if(a[len-l+1]-now[len-l+1]==2)
	{
		s[l]='0';
		s[r]='1';
		for(i=1;i<l;i++) now[r-i+1]+=(s[i]=='0');
		for(i=r;i<=n;i++) now[i-l+1]+=(s[i]=='1');
		dfs(l+1,r-1);
		if(ok) return;
		for(i=1;i<l;i++) now[r-i+1]-=(s[i]=='0');
		for(i=r;i<=n;i++) now[i-l+1]-=(s[i]=='1');
		return;
	}
}
int main()
{
	int i;
	cin>>n;
	assert_range(n,2,40);
	for(i=2;i<=n;i++)
	{
		cin>>a[i];
		assert_range(a[i],0,n/2);
		now[i]=0;
	}
	for(i=1;i<=n;i++) s[i]='0';
	ok=1;
	for(i=n;i>=2;i--)
	{
		if(a[i])
		{
			if(a[i]!=1)
			{
				ok=0;
				break; 
			}
			ok=0;
			s[1]='0';
			s[i]='1';
			now[i]=1;
			len=i;
			dfs(2,i-1);
			break;
		}
	}
	s[n+1]='\0';
	if(ok)
	{
		cal();
		assert(ck());
		puts(s+1);
	}
	else puts("-1");
	return 0;
}

