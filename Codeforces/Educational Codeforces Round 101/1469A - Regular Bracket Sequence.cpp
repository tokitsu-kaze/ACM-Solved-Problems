#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,l,r;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		l=r=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='(') l=i;
			else if(s[i]==')') r=i;
		}
		if(l<r)
		{
			if(n%2==0) puts("YES");
			else puts("NO");
		}
		else
		{
			if(l!=n && r!=1 && n%2==0) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
/*
?(?)
*/
