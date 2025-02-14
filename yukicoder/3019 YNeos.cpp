#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int n,m,i,j,k;
	char a[105],b[105],res[205];
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	if(n-m==0 || n-m==1)
	{
		for(i=1,j=1,k=1;k<=n+m;k++)
		{
			if(k&1) res[k]=a[i++];
			else res[k]=b[j++];
		}
		res[n+m+1]='\0';
		puts(res+1);
	}
	else puts("?");
	return 0;
}

