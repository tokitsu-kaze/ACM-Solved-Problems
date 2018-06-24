////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-30 15:09:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4690
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:3056KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int MAX=1e7+10;
char a[MAX];
int main()
{
    map<string,string> mp;
    mp["00"]="00";
    mp["01"]="01";
    mp["02"]="02";
    mp["03"]="03";
    mp["37"]="04";
    mp["2D"]="05";
    mp["2E"]="06";
    mp["2F"]="07";
    mp["16"]="08";
    mp["05"]="09";
    mp["25"]="0A";
    mp["0B"]="0B";
    mp["0C"]="0C";
    mp["0D"]="0D";
    mp["0E"]="0E";
    mp["0F"]="0F";
    mp["10"]="10";
    mp["11"]="11";
    mp["12"]="12";
    mp["13"]="13";
    mp["3C"]="14";
    mp["3D"]="15";
    mp["32"]="16";
    mp["26"]="17";
    mp["18"]="18";
    mp["19"]="19";
    mp["3F"]="1A";
    mp["27"]="1B";
    mp["1C"]="1C";
    mp["1D"]="1D";
    mp["1E"]="1E";
    mp["1F"]="1F";
    mp["40"]="20";
    mp["5A"]="21";
    mp["7F"]="22";
    mp["7B"]="23";
    mp["5B"]="24";
    mp["6C"]="25";
    mp["50"]="26";
    mp["7D"]="27";
    mp["4D"]="28";
    mp["5D"]="29";
    mp["5C"]="2A";
    mp["4E"]="2B";
    mp["6B"]="2C";
    mp["60"]="2D";
    mp["4B"]="2E";
    mp["61"]="2F";
    mp["F0"]="30";
    mp["F1"]="31";
    mp["F2"]="32";
    mp["F3"]="33";
    mp["F4"]="34";
    mp["F5"]="35";
    mp["F6"]="36";
    mp["F7"]="37";
    mp["F8"]="38";
    mp["F9"]="39";
    mp["7A"]="3A";
    mp["5E"]="3B";
    mp["4C"]="3C";
    mp["7E"]="3D";
    mp["6E"]="3E";
    mp["6F"]="3F";
    mp["7C"]="40";
    mp["C1"]="41";
    mp["C2"]="42";
    mp["C3"]="43";
    mp["C4"]="44";
    mp["C5"]="45";
    mp["C6"]="46";
    mp["C7"]="47";
    mp["C8"]="48";
    mp["C9"]="49";
    mp["D1"]="4A";
    mp["D2"]="4B";
    mp["D3"]="4C";
    mp["D4"]="4D";
    mp["D5"]="4E";
    mp["D6"]="4F";
    mp["D7"]="50";
    mp["D8"]="51";
    mp["D9"]="52";
    mp["E2"]="53";
    mp["E3"]="54";
    mp["E4"]="55";
    mp["E5"]="56";
    mp["E6"]="57";
    mp["E7"]="58";
    mp["E8"]="59";
    mp["E9"]="5A";
    mp["BA"]="5B";
    mp["E0"]="5C";
    mp["BB"]="5D";
    mp["B0"]="5E";
    mp["6D"]="5F";
    mp["79"]="60";
    mp["81"]="61";
    mp["82"]="62";
    mp["83"]="63";
    mp["84"]="64";
    mp["85"]="65";
    mp["86"]="66";
    mp["87"]="67";
    mp["88"]="68";
    mp["89"]="69";
    mp["91"]="6A";
    mp["92"]="6B";
    mp["93"]="6C";
    mp["94"]="6D";
    mp["95"]="6E";
    mp["96"]="6F";
    mp["97"]="70";
    mp["98"]="71";
    mp["99"]="72";
    mp["A2"]="73";
    mp["A3"]="74";
    mp["A4"]="75";
    mp["A5"]="76";
    mp["A6"]="77";
    mp["A7"]="78";
    mp["A8"]="79";
    mp["A9"]="7A";
    mp["C0"]="7B";
    mp["4F"]="7C";
    mp["D0"]="7D";
    mp["A1"]="7E";
    mp["07"]="7F";
    char temp[5];
    while(~scanf("%s",a))
    {
        int len=(int)strlen(a);
        for(int i=0;i<len;i+=2)
        {
            temp[0]=a[i];
            temp[1]=a[i+1];
            temp[2]='\0';
            if(mp[temp][0]=='\0') printf("80");
            else cout<<mp[temp];
        }
        puts("");
    }
    return 0;
}
