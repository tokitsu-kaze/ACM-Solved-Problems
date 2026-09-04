#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	set<int> s={1,3,5,7,8,10,12};
	int y,m;
	scanf("%d%d",&y,&m);
	if(s.count(m)) puts("31");
	else if(m==2)
	{
		if(y%400==0 || (y%4==0 && y%100!=0)) puts("29");
		else puts("28");
	}
	else puts("30");
	return 0;
}
