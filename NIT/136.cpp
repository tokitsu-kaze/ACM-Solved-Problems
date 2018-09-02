#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
using namespace std;
int main()
{
	int a,i,sum;
	char b;
	while(cin>>a>>b)
	{
		sum=0;
		if(a%2)
		{
			if((a+1)%4==0) a-=2;
		}
		else
		{
			if(a%4==0) a-=2;
		}
		switch(b)
		{
			case 'a':sum+=7;break;
			case 'b':sum+=6;break;
			case 'c':sum+=5;break;
			case 'd':sum+=3;break;
			case 'e':sum+=2;break;
			case 'f':sum+=1;break;
		}
		if(a%2) sum+=(a-1)*7;
		else sum+=a*7-1;
		cout<<sum<<endl;
	}
    return 0;
}