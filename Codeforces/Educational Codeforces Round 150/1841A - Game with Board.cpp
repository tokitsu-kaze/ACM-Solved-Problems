#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n>=5) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
