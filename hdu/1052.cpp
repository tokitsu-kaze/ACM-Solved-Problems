////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-12-02 21:18:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1052
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
#include <iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
  
bool cmp(int a,int b)  
{  
    return a>b;  
}  
  
int main()  
{  
    int n,money;  
    int a[1000],b[1000];  
    while(cin>>n)  
    {  
        if(!n)  
            break;  
        for(int i=0;i<n;i++)  
            cin>>a[i];  
        for(int i=0;i<n;i++)  
            cin>>b[i];  
        sort(a,a+n,cmp);  
        sort(b,b+n,cmp);  
        money=0;  
        for(int i=n-1;i>=0;i--)  
        {  
            if(a[i]>b[i])  
            {  
                money++;  
            }  
            else if(a[i]<b[i])  
            {  
                money--;  
                for(int j=0;j<i;j++)  
                    b[j]=b[j+1];  
            }  
            else if(a[i]==b[i])  
            {  
                if(a[0]>b[0])  
                {  
                    money++;  
                    for(int j=0;j<i;j++)  
                    {  
                        a[j]=a[j+1];  
                        b[j]=b[j+1];  
                    }  
                }  
                else if(a[0]<b[0])  
                {  
                    money--;  
                    for(int j=0;j<i;j++)  
                        b[j]=b[j+1];  
                }  
                else  
                {  
                    if(a[i]>b[0])  
                    {  
                        money++;  
                        for(int j=0;j<i;j++)  
                            b[j]=b[j+1];  
                    }  
                    else if(a[i]<b[0])  
                    {  
                        money--;  
                        for(int j=0;j<i;j++)  
                            b[j]=b[j+1];  
                    }  
                }  
            }  
        }  
        cout<<money*200<<endl;  
    }  
    return 0;  
}  