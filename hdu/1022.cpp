////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-04 20:48:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1022
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll; 
int main()//123 213
{
    int n,i,j,k,flag[21];
    char in[11],out[11];
    stack<char> s;
    while(cin>>n)
    {
		scanf(" %s %s",in,out);
		mem(flag,0);
		j=k=0;
		for(i=0;i<n;i++)
		{
			s.push(in[i]);
			flag[k++]=1;
			while(!s.empty()&&s.top()==out[j])
			{
				k++;
				j++;
				s.pop();
			}
		}
		if(s.empty())
		{
			puts("Yes.");
			for(i=0;i<2*n;i++)
			{
				if(flag[i]) puts("in");
				else puts("out");
			}
		}
		else
		{
			puts("No.");
			while(!s.empty())
			{
				s.pop();
			}
		}
		puts("FINISH");
	}
    return 0;
}
