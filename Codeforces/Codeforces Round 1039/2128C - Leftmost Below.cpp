#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,ok,mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ok=1;
		mn=1e9;
		for(i=1;i<=n;i++)
		{
			mn=min(mn,a[i]);
			if(a[i]>=mn*2) ok=0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
4
3
1 100 2
3
3 5 4
2
0 1
4
3 5 2 3

0 0 0 0
3 0 0 0
3 2 0 0
3 5 0 0
3 5 2 0
3 5 2 1
3 5 2 3

*/
