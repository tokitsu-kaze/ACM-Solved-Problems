#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k,n;
	double res;
	scanf("%d",&k);
	res=0;
	for(n=1;;n++)
	{
		res+=1.0/n;
		if(res>k)
		{
			printf("%d\n",n);
			break;
		}
	}
	return 0;
}
