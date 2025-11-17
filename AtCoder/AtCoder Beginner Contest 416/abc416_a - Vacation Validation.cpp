#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,l,r,i,ok;
	char s[105];
	scanf("%d%d%d",&n,&l,&r);
	scanf("%s",s+1);
	ok=1;
	for(i=l;i<=r;i++)
	{
		if(s[i]=='x') ok=0;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
