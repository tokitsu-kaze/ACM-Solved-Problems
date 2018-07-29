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
int prime[MAX];
int a[MAX],c[MAX];
int main()  
{
	int n,i,j,count=0,k=1,f,x,y;
	c[0]=1;
	memset(prime,0,sizeof(prime));
	memset(a,0,sizeof(a));
	for(i=3;i<MAX;i+=2)
	{
		prime[i]=1;
	}
	prime[2]=1;
	for(i=2;i<sqrt(MAX);i++)
	{
		if(prime[i])
		{
		//	count++;
			for(j=i+i;j<MAX;j+=i)
			{
				prime[j]=0;
			}
		}
	//	a[i]=count;
	}
	for(i=2;i<MAX;i++)
	{
		if(prime[i]) count++;
		a[i]=count;
	}
	while(cin>>x>>y)
	{	
		if(x==-1&&y==-1) break;
		if(x<0||y<0) puts("0");
		else
		{
			if(prime[x]) cout<<a[y]-a[x-1]<<endl;
			else cout<<a[y]-a[x]<<endl;
		}
    }
    return 0;  
}  
  