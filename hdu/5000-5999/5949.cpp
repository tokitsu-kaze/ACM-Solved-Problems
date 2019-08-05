////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-30 17:42:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5949
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std; 
int main()
{
    int n,i,len,sum;
    char s[11];
    while(cin>>n)
    {
        while(n--)
        {
            sum=0;
            scanf("%s",s);
            len=strlen(s);
            for(i=0;i<len;i++)
            {
                switch(s[i])
                {
                    case 'H':sum+=1;break;
                    case 'C':sum+=12;break;
                    case 'O':sum+=16;break;
                }
            }
            cout<<sum<<endl;
        }
    } 
    return 0;
}