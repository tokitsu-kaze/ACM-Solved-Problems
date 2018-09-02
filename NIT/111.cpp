#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	int i,count1,count2,sum,j;
	char s[101],c[101];
	while(gets(s))
	{
		j=sum=count1=count2=0;
		for(i=0;i<strlen(s);i++)
		{
			if(isdigit(s[i]))
			{
				sum+=s[i]-'0';
				count1++;
			}
			else if(isalpha(s[i]))
			{
				if(islower(s[i])) s[i]=toupper(s[i]);
				else if(isupper(s[i])) s[i]=tolower(s[i]);
				count2++;
			}
			c[j++]=s[i];
			if(s[i]==' ') cout<<"NITACM";
			else cout<<s[i];
		}
		cout<<endl;
		if(count1>count2) printf("%.2lf\n",sum*1.0/count1);
		else if(count1<count2)
		{
			sort(c,c+j);
			cout<<c[j-1]<<endl;
		}
		else cout<<"214216"<<endl;
	}
	return 0;
}