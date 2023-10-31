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
using namespace std;
typedef long long ll;
int main()
{
	int c[10],lena,lenb,i,j,k;
	char a[10],b[10];
	while(~scanf("%s %s",a,b))
	{
		lena=strlen(a);
		lenb=strlen(b);
		for(i=lena-1,j=lenb-1,k=0;i>=0&&j>=0;i--,j--)
		{
			c[k++]=(a[i]-'0'+b[j]-'0')%10;
		}
		while(i>=0)
		{
			c[k++]=a[i--]-'0';
		}
		while(j>=0)
		{
			c[k++]=b[j--]-'0';
		}
		for(i=k-1;i>=0;i--)
		{
			cout<<c[i];
		}
		puts("");
	}
	return 0;
}