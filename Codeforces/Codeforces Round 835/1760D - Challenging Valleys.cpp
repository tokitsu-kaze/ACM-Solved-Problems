#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int t,n,i,ok,cnt,x,tot;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tot=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(!tot||a[tot]!=x) a[++tot]=x;
		}
		n=tot;
		ok=1;
		cnt=0;
		for(i=2;i<n;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1]) ok=0;
			if(a[i]<a[i-1]&&a[i]<a[i+1]) cnt++;
		}
		if(cnt>1) ok=0;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
