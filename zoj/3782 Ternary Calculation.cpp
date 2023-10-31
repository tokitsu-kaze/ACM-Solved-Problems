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
int op(int a,char b,int c)
{
	int ans=0;
	switch(b)
	{
		case '+':ans=a+c;break;
		case '-':ans=a-c;break;
		case '*':ans=a*c;break;
		case '/':ans=a/c;break;
		case '%':ans=a%c;break;
	}
	return ans;
}
int main()
{ 
	int t,ans,a,b,c,flag;
	char c1,c2;
	while(cin>>t)
	{
		while(t--)
		{
			ans=flag=0;
			scanf("%d %c %d %c %d",&a,&c1,&b,&c2,&c);
			if(!flag&&(c1=='*'||c1=='/'||c1=='%'))
			{
				ans=op(a,c1,b);
				flag=1;
			}
			if(!flag&&(c2=='*'||c2=='/'||c2=='%'))
			{
				ans=op(b,c2,c);
				flag=2;
			}
			if(flag==1) ans=op(ans,c2,c);
			else if(flag==2) ans=op(a,c1,ans);
			else ans=op(op(a,c1,b),c2,c);
			cout<<ans<<endl;
		}
	}
    return 0;
}