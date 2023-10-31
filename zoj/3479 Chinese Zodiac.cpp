#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main()
{
	int t,y;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>y;
			y%=12;
			switch(y)
			{
				case 1:puts("Rabbit");break;
				case 2:puts("Tiger");break;
				case 3:puts("Ox");break;
				case 4:puts("Rat");break;
				case 5:puts("Pig");break;
				case 6:puts("Dog");break;
				case 7:puts("Rooster");break;
				case 8:puts("Monkey");break;
				case 9:puts("Ram");break;
				case 10:puts("Horse");break;
				case 11:puts("Snake");break;
				case 0:puts("Dragon");break; 
			}
		} 
	}
	return 0;
}