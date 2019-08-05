////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-02 09:32:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2192
////Problem Title: 
////Run result: Accept
////Run time:374MS
////Run memory:1644KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
const int MAX=10001;
int s[MAX];
using namespace std;
int main()
{
	int t,n,m,i,j,sum,Max;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>s[i];
		sort(s,s+n);
		m=s[0];
		sum=1;
		Max=1;
		for(i=1;i<n;i++)
		{
			if(m==s[i])
			sum+=1;
			else
			{
			 m=s[i];
			 sum=1;
			}
			if(sum>Max)
			Max=sum;
		}
		cout<<Max<<endl;
	}
	return 0;
}