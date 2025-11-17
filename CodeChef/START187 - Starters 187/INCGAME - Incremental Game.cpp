#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,x,y,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&x,&y,&k);
		if(k>=max(x,y)) puts("Alice");
		else if(k>=min(x,y) && k+k+1>max(x,y)) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
