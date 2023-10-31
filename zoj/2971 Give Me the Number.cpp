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
const int MAX=50000+10;
const int EDGE=20000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int t,i,sum,ans,k;
	char s[1111],temp[111];
	map<string,int> m;
	m["zero"]=0;
    m["one"]=1;
    m["two"]=2;
    m["three"]=3;
    m["four"]=4;
    m["five"]=5;
    m["six"]=6;
    m["seven"]=7;
    m["eight"]=8;
    m["nine"]=9;
    m["ten"]=10;
    m["eleven"]=11;
    m["twelve"]=12;
    m["thirteen"]=13;
    m["fourteen"]=14;
    m["fifteen"]=15;
    m["sixteen"]=16;
    m["seventeen"]=17;
    m["eighteen"]=18;
    m["nineteen"]=19;
    m["twenty"]=20;
    m["thirty"]=30;
    m["forty"]=40;
    m["fifty"]=50;
    m["sixty"]=60;
    m["seventy"]=70;
    m["eighty"]=80;
    m["ninety"]=90;
    m["hundred"]=100;
    m["thousand"]=1000;
    m["million"]=1000000;
    while(~scanf("%d",&t))
    {
		getchar();
		while(t--)
		{
			gets(s);
			mem(temp,0);
			ans=sum=k=0;
			for(i=0;i<strlen(s);i++)
			{
				if(s[i]!=' ') temp[k++]=s[i];
				if(s[i]==' '||i==strlen(s)-1)
				{
					if(strcmp(temp,"and")==0)
					{
						mem(temp,0);
						k=0;
						continue;
					}
					if(strcmp(temp,"thousand")==0||strcmp(temp,"million")==0||strcmp(temp,"hundred")==0)
					{
						sum*=m[temp];
						if(strcmp(temp,"hundred"))
						{
							ans+=sum;
							sum=0;
						}
					}
					else sum+=m[temp];
					mem(temp,0);
					k=0;
					if(i==strlen(s)-1) ans+=sum;
				}
			}
			printf("%d\n",ans);
		}
	}
    return 0;
}