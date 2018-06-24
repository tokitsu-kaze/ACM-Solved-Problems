////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-28 16:56:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2567
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1584KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main()
{ 
	int n,i,len,k;
	char a[51],b[51],c[102];
    while(cin>>n)
	{  
		while(n--)
		{
			cin>>a>>b;
			mem(c,0);
			len=strlen(a);
			k=0;
			for(i=0;i<len/2;i++)
			{
				c[k++]=a[i];
			}
			for(i=0;i<strlen(b);i++)
			{
				c[k++]=b[i];
			}
			for(i=len/2;i<len;i++)
			{
				c[k++]=a[i];
			}
			cout<<c<<endl;
		} 
    }  
    return 0;  
}  