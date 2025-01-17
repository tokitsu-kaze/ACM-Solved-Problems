#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
char s[MAX],t[MAX];
int main()
{
	int k,n,m,i,cnt,l,r;
	scanf("%d",&k);
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	if(n==m)
	{
		cnt=0;
		for(i=1;i<=n;i++) cnt+=(s[i]!=t[i]);
		if(cnt<=k) puts("Yes");
		else puts("No");
	}
	else if(n+1==m)
	{
		l=0;
		while(l<n && s[l+1]==t[l+1]) l++;
		r=n;
		while(r>0 && s[r]==t[r+1]) r--;
		if(l+k>=r) puts("Yes");
		else puts("No");
	}
	else if(n==m+1)
	{
		l=0;
		while(l<m && s[l+1]==t[l+1]) l++;
		r=m;
		while(r>0 && s[r+1]==t[r]) r--;
		if(l+k>=r) puts("Yes");
		else puts("No");
	}
	else puts("No");
	return 0;
}

