#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
int main()  
{
	long long i,count,len,flag,k,a[101];
	char s[101],b[101];
	char *end;
	while(~scanf("%s",s))
	{	
		memset(b,0,sizeof(b));
		len=strlen(s);
		flag=0;
		k=0;
		for(i=0,count=0;i<len;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				b[k++]=s[i];
				flag=1;
			}
			else if(flag)
			{
				sscanf(b,"%lld",&a[count++]);
				memset(b,0,sizeof(b));
				flag=0;
				k=0;
			}
		//	cout<<b<<endl;
		}
		if(flag) sscanf(b,"%lld",&a[count++]);
		sort(a,a+count);
		cout<<a[0];
		for(i=1;i<count;i++)
		{
			if(a[i-1]!=a[i]) cout<<" "<<a[i];
		}
		cout<<endl;
    }
    return 0;  
}  
  