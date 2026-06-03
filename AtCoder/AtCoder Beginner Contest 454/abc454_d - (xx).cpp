#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
char a[MAX],b[MAX];
char sa[MAX],sb[MAX];
int ta,tb;
int main()
{
	int T,n,m,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",a+1);
		scanf("%s",b+1);
		n=strlen(a+1);
		m=strlen(b+1);
		ta=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==')')
			{
				if(ta-3>=0 && sa[ta-1]=='x'
						   && sa[ta-2]=='x'
						   && sa[ta-3]=='(')
				{
					sa[ta-3]='x';
					ta--;
				}
				else sa[ta++]=a[i];
			}
			else sa[ta++]=a[i];
		}
		tb=0;
		for(i=1;i<=m;i++)
		{
			if(b[i]==')')
			{
				if(tb-3>=0 && sb[tb-1]=='x'
						   && sb[tb-2]=='x'
						   && sb[tb-3]=='(')
				{
					sb[tb-3]='x';
					tb--;
				}
				else sb[tb++]=b[i];
			}
			else sb[tb++]=b[i];
		}
		sa[ta]='\0';
		sb[tb]='\0';
//		puts(sa);
//		puts(sb);
		if(ta!=tb)
		{
			puts("No");
			continue;
		}
		ok=1;
		for(i=0;i<ta;i++)
		{
			if(sa[i]!=sb[i]) ok=0;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
