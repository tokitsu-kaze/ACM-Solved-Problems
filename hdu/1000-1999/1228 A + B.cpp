////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-24 22:07:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1228
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	int n,sum,x,y;
	map <string,int> m;
	m["one"]=1;
	m["two"]=2;
	m["three"]=3;
	m["four"]=4;
	m["five"]=5;
	m["six"]=6;
	m["seven"]=7;
	m["eight"]=8;
	m["nine"]=9;
	m["zero"]=0;
	string a;
	while(1)
	{
		sum=x=y=0;
		while(cin>>a,a!="+")
		{
			x=x*10+m[a];
		}
		while(cin>>a,a!="=")
		{
			y=y*10+m[a];
		}
		sum=x+y;
		if(sum!=0) cout<<sum<<"\n";
		else break;
	}
	return 0;
}