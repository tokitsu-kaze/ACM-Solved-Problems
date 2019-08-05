////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 18:05:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1859
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
int main ()  
{
    int i,j,x[1001],y[1001];
    while(cin>>x[0]>>y[0])
	{
		if(x[0]==0&&y[0]==0) break;
		for(i=0,j=0;;)
		{
			cin>>x[++i]>>y[++j];
			if(x[i]==0&&y[i]==0) break;
		}
		sort(x,x+i);
		sort(y,y+j);
		cout<<x[0]<<" "<<y[0]<<" "<<x[i-1]<<" "<<y[j-1]<<endl;
	}
    return 0;  
}