#include <bits/stdc++.h>
using namespace std;
int main()
{
	double m,h,bmi;
	scanf("%lf%lf",&m,&h);
	bmi=m/(h*h);
	if(bmi<18.5) puts("Underweight");
	else if(bmi>=18.5&&bmi<24) puts("Normal");
	else
	{
		cout<<bmi<<"\n";
		puts("Overweight");
	}
	return 0;
}
