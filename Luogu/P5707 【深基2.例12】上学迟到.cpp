#include <bits/stdc++.h>
using namespace std;
int main()
{
	int s,v,now;
	scanf("%d%d",&s,&v);
	now=8*60-10-(s+v-1)/v;
	if(now<0) now+=24*60;
	printf("%02d:%02d\n",now/60,now%60);
	return 0;
}
