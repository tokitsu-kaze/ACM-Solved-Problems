#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int T,n,i,cnt,pos,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cnt++;
				pos=i;
			}
		}
		if(cnt!=1)
		{
			puts("NO");
			continue;
		}
		ok=1;
		for(i=pos;i<n;i++)
		{
			if(a[i+1]-a[i]>1) ok=0;
		}
		a[0]=a[n];
		for(i=0;i<pos;i++)
		{
			if(a[i+1]-a[i]>1) ok=0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
2 1 4 3 6 5
2 2 4 4 6 6
3

5 2 1 4 3 6
5 5 5 5 5 6
2

6 5 2 1 4 3
6 6 6 6 6 6
1

3 6 5 2 1 4
3 6 6 6 6 6
2

4 3 6 5 2 1
4 4 6 6 6 6
2

1 4 3 6 5 2
1 4 4 6 6 6
3

2
6
3 2 1 2 2 3
6
4 2 3 1 2 3

*/

