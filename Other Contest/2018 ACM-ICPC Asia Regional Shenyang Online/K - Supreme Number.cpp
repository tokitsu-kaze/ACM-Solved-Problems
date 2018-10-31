#include<bits/stdc++.h>
using namespace std;

bool check(int x)
{
	int sqrtN=sqrt(x+0.5);
	for(int i=2;i<=sqrtN;i++)
	{
		if(x%i==0)
		{
			cout<<i<<endl;
			return 0;}
	}
	return 1;
}

int arr[5000]=
		{
				2,
				3,
				5,
				7,
				11,
				13,
				17,
				23,
				31,
				37,
				53,
				71,
				73,
				113,
				131,
				137,
				173,
				311,
				317,
		};
int main()
{

	//cout<<check(5317)<<endl;
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++)
	{
		string s;
		cin>>s;
		printf("Case #%d: ",cas);
		if(s.length()>3)
		{
			puts("317");
		}
		else
		{
			int now=stoi(s);
			int ans=upper_bound(arr,arr+19,now)-arr;
			ans--;
			cout<<arr[ans]<<endl;
		}
	}

	/*for(int i=2;i<100000;i++)
	{
		string temp=to_string(i);
		for(int j=1;j<(1<<temp.length());j++)
		{
			string now;
			for(int k=0;k<temp.length();k++)
			{
				if(j & (1<<k))
				{
					now.push_back(char(temp[k]));
				}
			}
			int ans=stoi(now);
			if(!check(ans))
				goto end;
		}
		cout<<i<<endl;
		end:;
	}*/




	/*while(t--)
	{
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{

		}



	}*/



	return 0;
}