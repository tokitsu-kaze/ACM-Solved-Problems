#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}
int main()
{
	int n,m,a,b;
	while(~scanf("%d%d",&n,&m))
	{
		a=gcd(n,m);
		b=n*m/a;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}