#include<bits/stdc++.h>
using namespace std;
const int MAX=5e6+10;
int a[MAX];
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	nth_element(a+1,a+k+1,a+n+1);
	printf("%d\n",a[k+1]);
	return 0;
}
