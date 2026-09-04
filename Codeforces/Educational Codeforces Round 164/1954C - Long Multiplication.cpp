#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
char a[MAX],b[MAX];
int main()
{
	int T,n,i,pos;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",a+1);
		scanf("%s",b+1);
		n=strlen(a+1);
		for(i=1;i<=n;i++)
		{
			if(a[i]!=b[i])
			{
				if(a[i]<b[i]) swap(a[i],b[i]);
				pos=i;
				break;
			}
		}
		for(i=pos+1;i<=n;i++)
		{
			if(a[i]>b[i]) swap(a[i],b[i]);
		}
		a[n+1]=b[n+1]='\0';
		puts(a+1);
		puts(b+1);
	}
	return 0;
}
/*
越靠近越好。
*/
