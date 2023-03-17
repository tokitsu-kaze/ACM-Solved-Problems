#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,ans,tmp;
	cin>>a>>b;
	a=abs(a-b);
	ans=0;
	ans+=a/10;
	a%=10;
	if(a==0);
	else if(a==1 || a==5) ans++;
	else if(a==2 || a==4 || a==6 || a==9) ans+=2;
	else ans+=3;
	printf("%d\n",ans);
	return 0;
}
