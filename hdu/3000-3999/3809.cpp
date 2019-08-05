////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-11 18:09:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3809
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1664KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#include <iostream>
using namespace std;
const double eps = 1e-9;
typedef long long LL;
int main()
{
    int t;
    double x1,y1,x,y,sx,sy;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        cin>>x1>>y1;
        sx=x1;
        sy=y1;
        do
        {
            y=y1;
            x=x1;
            x1=sx+sqrt(y);
            y1=sy+sqrt(x);
        }
        while(x1-x>eps||y1-y>eps);
        printf("Case %d: %.6lf %.6lf\n",cas,x1,y1);
    }
}