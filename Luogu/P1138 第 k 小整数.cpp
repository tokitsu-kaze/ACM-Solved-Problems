#include<bits/stdc++.h>
using namespace std;
const int MAX=1e4+10;
int a[MAX];
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	if(k>n) puts("NO RESULT");
	else printf("%d\n",a[k]);
	return 0;
}
