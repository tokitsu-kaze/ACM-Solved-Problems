////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-08 22:04:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2516
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()  
{
	__int64 n,i,flag,f[50];
	f[0]=1;
	f[1]=2;
	for(i=2;i<=44;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	while(cin>>n)
	{	
		if(n==0) break;
		for(i=0,flag=0;i<=44;i++)
		{
			if(n==f[i])
			{
				flag=1;
				break;
			}
		}
		if(flag) cout<<"Second win"<<endl;
		else cout<<"First win"<<endl;
    }
    return 0;  
}  
  