#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int h,w;
	scanf("%d%d",&h,&w);
	if(w*100*100>=25*h*h) puts("Yes");
	else puts("No");
	return 0;
}
