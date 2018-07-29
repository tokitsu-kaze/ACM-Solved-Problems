#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <list> 
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
#define pi acos(-1.0) 
#define MAX 100000+1
using namespace std;
typedef long long ll;
int gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}
int main()  
{
	int a,b,c,d,e,f,g;
	char s;
	while(~scanf("%d/%d%c%d/%d",&a,&b,&s,&c,&d))
	{	
		switch(s)
		{
			case '+':e=a*d+b*c;break;
			case '-':e=a*d-b*c;break;
		}
		if(e==0)
		{
			puts("0");
			continue;
		}
		f=b*d;
		g=gcd(abs(e),abs(f));
	//	cout<<g<<endl;
		if(f/g==1) cout<<e/g<<endl;
		else if(e/g==f/g) puts("1");
		else printf("%d/%d\n",e/g,f/g);
    }
    return 0;  
}  
  