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
#include <vector>
#include <set>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100000+10;
const int EDGE=20000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int i,temp,k;
	char a[11111],t[11];
	while(~scanf("%s",a))
	{
		if(strlen(a)==1&&a[0]=='0') break;
		mem(t,0);
		k=0;
		temp=0;
		for(i=0;i<strlen(a);i++)
		{
			t[k++]=a[i];
			if(k==2)
			{
				temp+=atoi(t);
				mem(t,0);
				k=0;
				temp%=17;
				if(i+2<strlen(a)) temp*=100;
				else if(i+1<strlen(a)) temp*=10;
			}
		}
		temp+=atoi(t);
		temp%=17;
		if(temp) puts("0");
		else puts("1");
	}
	return 0;
}