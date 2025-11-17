#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
int f[MAX];
char s[MAX],t[MAX];
int main()
{
	int n,m,i,l,r;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(i=0;i<=n;i++) f[i]=0;
	while(m--)
	{
		scanf("%d%d",&l,&r);
		f[l]^=1;
		f[r+1]^=1;
	}
	for(i=1;i<=n;i++) f[i]^=f[i-1];
	for(i=1;i<=n;i++)
	{
		if(f[i]) s[i]=t[i];
	}
	s[n+1]='\0';
	puts(s+1);
	return 0;
}
