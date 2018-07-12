import std.stdio;

int main()
{
	int i,j,now,x,y;
	int[][] v = [
	[3,3,0,4,4,0,3,3],
	[3,3,0,4,4,0,3,3],
	[2,2,0,3,3,0,2,2],
	[2,2,0,3,3,0,2,2],
	[1,1,0,2,2,0,1,1],
	[1,1,0,2,2,0,1,1]
	];
	char[11][11] mp;
	char tmp;
	now=0;
	x=y=0;
	for(i=0;i<6;i++)
	{
		for(j=0;j<8;j++)
		{
			scanf("%c ",&mp[i][j]);
			if(mp[i][j]=='.'&&v[i][j]>now)
			{
				now=v[i][j];
				x=i;
				y=j;
			}
		}
	}
	mp[x][y]='P';
	for(i=0;i<6;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("%c",mp[i][j]);
		}
		printf("\n");
	}
	return 0;
}