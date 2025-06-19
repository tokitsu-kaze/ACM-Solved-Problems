#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n;
	scanf("%d",&n);
	if(n%3==1) n--;
	else if(n%3==2) n++;
	printf("%d\n",n);
	return 0;
}
