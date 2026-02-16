#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int a[MAX];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<n;i++) a[i]=n-i;
		a[n]=n;
		for(i=n+1;i<=2*n;i++) a[i]=i-n;
		for(i=1;i<=2*n;i++) printf("%d%c",a[i]," \n"[i==2*n]);
	}
	return 0;
}
/*
3 2 1 4 1 2 3 4
*/
