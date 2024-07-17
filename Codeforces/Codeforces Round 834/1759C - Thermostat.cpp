#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int main()
{
	int t,l,r,x,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&l,&r,&x);
		scanf("%d%d",&a,&b);
		if(a==b) puts("0");
		else if(abs(a-b)>=x) puts("1");
		else if(abs(a-l)>=x&&abs(l-b)>=x) puts("2");
		else if(abs(a-r)>=x&&abs(r-b)>=x) puts("2");
		else if(abs(a-r)>=x&&abs(r-l)>=x&&abs(l-b)>=x) puts("3");
		else if(abs(a-l)>=x&&abs(r-l)>=x&&abs(r-b)>=x) puts("3");
		else puts("-1");
	}
	return 0;
}
