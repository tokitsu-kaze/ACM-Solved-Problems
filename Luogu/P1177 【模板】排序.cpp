#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}
