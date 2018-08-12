#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    while(~scanf("%d",&t))
    {
	    while(t--)
	    {
	        char str[100];
	        int n;
			char s[100][100];
	        cin>>n>>str;
	        int point;
	        for(int i=1;i<=n;i++)
	        {
	            cin>>s[i];
	            if(strcmp(s[i],str)==0)
	            {
	                point=i;
	            }
	        }
	        int cnt=n/2;
	        for(int i=1;i<=n;i++)
	        {
	            if(abs(i-point)==cnt)
	            {
	                  cout<<s[i]<<endl;
	            }
	        }
	    }
	}
	return 0;
}