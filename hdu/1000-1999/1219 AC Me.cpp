////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-10 16:18:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1219
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1492KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int x,i,b[30];
    char a[100001];
    while(gets(a))
    {
		memset(b,0,sizeof(b));
		x=strlen(a);
		for(i=0;i<x;i++)
		{
			switch(a[i])
			{
				case 'a':b[0]++;break;
				case 'b':b[1]++;break;
				case 'c':b[2]++;break;
				case 'd':b[3]++;break;
				case 'e':b[4]++;break;
				case 'f':b[5]++;break;
				case 'g':b[6]++;break;
				case 'h':b[7]++;break;
				case 'i':b[8]++;break;
				case 'j':b[9]++;break;
				case 'k':b[10]++;break;
				case 'l':b[11]++;break;
				case 'm':b[12]++;break;
				case 'n':b[13]++;break;
				case 'o':b[14]++;break;
				case 'p':b[15]++;break;
				case 'q':b[16]++;break;
				case 'r':b[17]++;break;
				case 's':b[18]++;break;
				case 't':b[19]++;break;
				case 'u':b[20]++;break;
				case 'v':b[21]++;break;
				case 'w':b[22]++;break;
				case 'x':b[23]++;break;
				case 'y':b[24]++;break;
				case 'z':b[25]++;break;
			}
		}
		printf("a:%d\n",b[0]);
		printf("b:%d\n",b[1]);
		printf("c:%d\n",b[2]);
		printf("d:%d\n",b[3]);
		printf("e:%d\n",b[4]);
		printf("f:%d\n",b[5]);
		printf("g:%d\n",b[6]);
		printf("h:%d\n",b[7]);
		printf("i:%d\n",b[8]);
		printf("j:%d\n",b[9]);
		printf("k:%d\n",b[10]);
		printf("l:%d\n",b[11]);
		printf("m:%d\n",b[12]);
		printf("n:%d\n",b[13]);
		printf("o:%d\n",b[14]);
		printf("p:%d\n",b[15]);
		printf("q:%d\n",b[16]);
		printf("r:%d\n",b[17]);
		printf("s:%d\n",b[18]);
		printf("t:%d\n",b[19]);
		printf("u:%d\n",b[20]);
		printf("v:%d\n",b[21]);
		printf("w:%d\n",b[22]);
		printf("x:%d\n",b[23]);
		printf("y:%d\n",b[24]);
		printf("z:%d\n",b[25]);
		printf("\n");
    }
    return 0;
}