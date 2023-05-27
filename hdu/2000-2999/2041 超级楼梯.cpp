////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 10:39:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2041
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
#include <iostream>  
using namespace std;  
  
int main()  
{  
    int ans[41];  
    int n;  
    cin>>n;  
    int M;  
    ans[1]=1;  
    ans[2]=1;  
    for(int i=3;i<=40;i++)  
        ans[i]=ans[i-1]+ans[i-2];  
    while(n--){  
        cin>>M;  
        cout<<ans[M]<<endl;  
    }  
    return 0;  
}  