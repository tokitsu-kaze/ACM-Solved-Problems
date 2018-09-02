#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		if(n%(k+1)==1)  cout<<"Wang xue zhang is happy!"<<endl;
		else cout<<"Yuan xue zhang is happy!"<<endl;
	}
	return 0;
}