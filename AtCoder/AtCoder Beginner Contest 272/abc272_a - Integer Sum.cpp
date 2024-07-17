#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int main()
{
	int n,i,x,s;
	scanf("%d",&n);
	s=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s+=x;
	}
	printf("%d\n",s);
	return 0;
}
