#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
int main()
{
	int d,f;
	scanf("%d%d",&d,&f);
	while(f<=d) f+=7;
	f-=d;
	printf("%d\n",f);
	return 0;
}
