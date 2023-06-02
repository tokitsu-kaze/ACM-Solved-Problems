#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int i,j,flag[11],ok;
	string tmp;
	for(i=100;3*i<=999;i++)
	{
		memset(flag,0,sizeof flag);
		for(j=1;j<=3;j++)
		{
			tmp=to_string(j*i);
			for(auto &it:tmp) flag[it-'0']++;
		}
		ok=1;
		for(j=1;j<=9;j++) ok&=(flag[j]==1);
		if(ok) printf("%d %d %d\n",i,2*i,3*i);
	}
	return 0;
}
