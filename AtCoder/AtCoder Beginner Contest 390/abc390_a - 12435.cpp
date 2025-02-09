#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int a[11],n,i,ok,f;
	n=5;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	f=0;
	for(i=1;i<n;i++)
	{
		if(a[i]==i+1 && a[i+1]==i)
		{
			swap(a[i],a[i+1]);
			f=1;
			break;
		}
	}
	ok=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=i) ok=0;
	}
	if(f && ok) puts("Yes");
	else puts("No");
	return 0;
}
