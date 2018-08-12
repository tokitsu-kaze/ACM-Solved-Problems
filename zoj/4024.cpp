#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int main()
{
	int n,T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i) scanf("%d",&a[i]);
		i=1;
		while(i<n&&a[i]<a[i+1]) i++;
		if(i==n||i==1)
		{
			puts("No");
			continue;
		}
		while(i<n&&a[i]>a[i+1]) i++;
		i==n?puts("Yes"):puts("No");
	}
	return 0;
}