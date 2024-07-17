#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,i,a[22],ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ok=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			if(i%2==0) ok=1;
			break;
		}
	}
	for(i=n;i;i--)
	{
		if(a[i]==0)
		{
			if((n-i+1)%2==0) ok=1;
			break;
		}
	}
	puts(ok?"YES":"NO");
	return 0;
}
