////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-24 21:09:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1717
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:4620KB
//////////////////System Comment End//////////////////
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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-5;
const int MAX=1000000+10;
const ll mod=1e6;
char a[MAX],b[MAX],c[MAX];
ll gcd(ll x,ll y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	ll t,flag,i,len,k1,k2,fz,fm,g;
	scanf("%lld",&t);
	getchar();
	while(t--)
	{
		mem(a,0);
		mem(b,0);
		mem(c,0);
		scanf("%s",a);
		len=strlen(a);
		if(len==1)
		{
			puts("0");
			continue;
		}
		flag=0;
		k1=k2=0;
		for(i=0;i<len;i++)
		{
			if(i>=2)
			{
				if(a[i]>='0'&&a[i]<='9')
				{
					if(!flag) b[k1++]=a[i];
					else c[k2++]=a[i];
				}
				else flag=1;
			}
		}
		if(!flag)
		{
			fz=atol(b);
			fm=pow(10,len-2);
			g=gcd(fz,fm);
			printf("%lld/%lld\n",fz/g,fm/g);
		}
		else
		{
			if(a[2]=='(')
			{
				fz=atol(c);
				fm=pow(10,len-4)-1;
				g=gcd(fz,fm);
				printf("%lld/%lld\n",fz/g,fm/g);
			}
			else
			{
				int temp=atol(b);
				int temp0=strlen(b);
				strcat(b,c);
	//			cout<<b<<endl;
				fz=atol(b)-temp;
	//			cout<<fz<<endl;
				fm=pow(10,len-4)-pow(10,temp0);
				g=gcd(fz,fm);
				printf("%lld/%lld\n",fz/g,fm/g);
			}
		}
	}
	return 0;
}