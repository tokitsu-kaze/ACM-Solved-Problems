#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
char ans[11];
void itoa2(int a,int base)
{
	int t,i=0;
	while(a)  
    {  
        t=a%base;  
        a/=base;  
        if(t>=10)  
        ans[i++]=t-10+'A';
        else ans[i++] =t+'0';  
    }  
    ans[i]='\0';  
    reverse(ans,ans+i);  
}
int main()
{
	int b,c,temp;
	char a[10],*end;
	while(~scanf("%s%d%d",a,&b,&c))
	{
		temp=strtol(a,&end,b);
		itoa2(temp,c);
		if(strlen(ans)>7) printf("  ERROR\n");
		else printf("%7s\n",ans);
	}
    return 0;
}