#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e4+10;
int main()
{
	int t,n,i,flag;
	char a[22],b[22],c[22];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s%s%s",a,b,c);
		flag=0;
		for(i=0;i<n;i++)
		{
			if(a[i]!=c[i] && b[i]!=c[i]) flag=1;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
