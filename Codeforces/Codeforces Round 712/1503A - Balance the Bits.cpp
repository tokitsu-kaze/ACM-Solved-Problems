#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX],a[MAX],b[MAX];
int main()
{
	int T,n,i,ok,cnt1,cnt0,tot1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		ok=1;
		cnt0=0;
		for(i=1;i<=n;i++) cnt0+=(s[i]=='0');
		if(cnt0&1) ok=0;
		tot1=n-cnt0;
		if(s[1]=='0' || s[n]=='0') ok=0;
		if(!ok)
		{
			puts("NO");
			continue;
		}
		cnt1=cnt0=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				cnt1++;
				if(cnt1<=tot1/2) a[i]='(';
				else a[i]=')';
				b[i]=a[i];
			}
			else
			{
				cnt0++;
				if(cnt0&1)
				{
					a[i]='(';
					b[i]=')';
				}
				else
				{
					a[i]=')';
					b[i]='(';
				}
			}
		}
		a[n+1]=b[n+1]='\0';
		puts("YES");
		puts(a+1);
		puts(b+1);
	}
	return 0;
}
