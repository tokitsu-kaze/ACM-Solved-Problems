#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int x,c,tmp;
	scanf("%d%d",&x,&c);
	tmp=x/(1000+c);
	printf("%d\n",tmp*1000);
	return 0;
}
