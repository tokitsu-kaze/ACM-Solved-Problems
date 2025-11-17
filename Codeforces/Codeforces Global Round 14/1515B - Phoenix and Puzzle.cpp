#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,sq;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n%2==0)
		{
			sq=sqrt(n/2);
			while(sq*sq<n/2) sq++;
			while(sq*sq>n/2) sq--;
			if(sq*sq==n/2)
			{
				puts("YES");
				continue;
			}
		}
		if(n%4==0)
		{
			sq=sqrt(n/4);
			while(sq*sq<n/4) sq++;
			while(sq*sq>n/4) sq--;
			if(sq*sq==n/4)
			{
				puts("YES");
				continue;
			}
		}
		puts("NO");
	}
	return 0;
}
