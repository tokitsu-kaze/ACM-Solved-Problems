#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==1) printf(" a\n");
		else if(n==2) printf("  a\n bcd\n");
		else if(n==3)
		{
			printf("   a\n");
			printf("  bcd\n");
			printf(" efghi\n");
		}
		else if(n==4)
		{
			printf("    a\n");
			printf("   bcd\n");
			printf("  efghi\n");
			printf(" jklmnop\n");
		}
		else if(n==5)
		{
			printf("     a\n");
			printf("    bcd\n");
			printf("   efghi\n");
			printf("  jklmnop\n");
			printf(" qrstuvwxy\n");
		}
		else if(n==6)
		{
			printf("      a\n");
			printf("     bcd\n");
			printf("    efghi\n");
			printf("   jklmnop\n");
			printf("  qrstuvwxy\n");
			printf(" zABCDEFGHIJ\n");
		}
		else if(n==7)
		{
			printf("       a\n");
			printf("      bcd\n");
			printf("     efghi\n");
			printf("    jklmnop\n");
			printf("   qrstuvwxy\n");
			printf("  zABCDEFGHIJ\n");
			printf(" KLMNOPQRSTUVW\n");
		}
		else if(n==8)
		{
			printf("        a\n");
			printf("       bcd\n");
			printf("      efghi\n");
			printf("     jklmnop\n");
			printf("    qrstuvwxy\n");
			printf("   zABCDEFGHIJ\n");
			printf("  KLMNOPQRSTUVW\n");
			printf(" XYZabcdefghijkl\n");
		}
		else if(n==9)
		{
			printf("         a\n");
			printf("        bcd\n");
			printf("       efghi\n");
			printf("      jklmnop\n");
			printf("     qrstuvwxy\n");
			printf("    zABCDEFGHIJ\n");
			printf("   KLMNOPQRSTUVW\n");
			printf("  XYZabcdefghijkl\n");
			printf(" mnopqrstuvwxyzABC\n");
		}
		else if(n==10)
		{
			printf("          a\n");
			printf("         bcd\n");
			printf("        efghi\n");
			printf("       jklmnop\n");
			printf("      qrstuvwxy\n");
			printf("     zABCDEFGHIJ\n");
			printf("    KLMNOPQRSTUVW\n");
			printf("   XYZabcdefghijkl\n");
			printf("  mnopqrstuvwxyzABC\n");
			printf(" DEFGHIJKLMNOPQRSTUV\n");
		}
	}
	return 0;
}