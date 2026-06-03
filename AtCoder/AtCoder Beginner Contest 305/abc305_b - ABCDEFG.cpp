#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int i;
	char a[3],b[3];
	int sum[7]={0,3,1,4,1,5,9};
	for(i=1;i<=6;i++) sum[i]+=sum[i-1];
	scanf("%s%s",a,b);
	if(a[0]>b[0]) swap(a[0],b[0]);
	printf("%d\n",sum[b[0]-'A']-sum[a[0]-'A']);
	return 0;
}
