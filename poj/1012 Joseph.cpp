#include <stdio.h>
int main()
{
    int k;
    int joseph[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
    while(~scanf("%d",&k))
    {
		if(k==0) break;
		printf("%d\n",joseph[k]);
	} 
    return 0;
}