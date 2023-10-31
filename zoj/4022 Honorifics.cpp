#include<bits/stdc++.h>
using namespace std;
char h[505][505]={"A","Bae","Baek","Bak","Ban","Bang","Beom","Beon","Bi","Bin","Bing","Bong","Bu","Cha","Chang","Cho","Choe","Chong","Chu","Chun","Da","Dae","Dam","Dan","Dang","Deungjeong","Dok","Dokgo","Don","Dong","Dongbang","Du","Eo","Eogeum","Eom","Eum","Gae","Gal","Gam","Geum","Geun","Gi","Gil","Gim","Go","Gong","Guk","Gung","Gwak","Gwan","Gwon","Gyeon","Gyeong","Gyo","Ha","Hae","Hak","Ham","Han","Heo","Ho","Hong","Hu","Hwa","Hwan","Hwang","Hwangbo","Hwangmok","Hyeong","I","Im","In","Jam","Jang","Je","Jeo","Jeong","Jeup","Jin","Ju","Jun","Kwae","Mae","Maeng","Man","Mangjeol","Mi","Min","Mo","Mok","Mu","Muk","Myeong","Myo","Na","Nae","No","Noe","Nu","O","Ong","Pan","Po","Pung","Pyeon","Pyeong","Pyo","Ra","Ran","Rang","Roe","Ryeo","Sa","Sagong","Sam","Seo","Seok","Seomun","Seong","Seonu","Seung","Si","Sim","Sin","So","Song","Su","Sun","Tae","Tak","Tan","Tang","U","Un","Wan","Wang","Won","Ya","Yeong","Yeop","Yo","Yong","Yu","Yuk"};
char r[505][505]={"Abe","Adati","Aizawa","Akimoto","Akiyama","Andou","Aoyagi","Arai","Araki","Araya","Asada","Asano","Azuma","Baba","Eguti","Endou","Fukazawa","Fukuda","Fukui","Fukumoto","Fukunaga","Fukuoka","Fukusima","Furukawa","Fuzii","Fuzimoto","Fuzimura","Fuzino","Fuzita","Fuziwara","Hamada","Hamaguti","Hamano","Hara","Harada","Haraguti","Hasegawa","Hatakeyama","Hatanaka","Hattori","Hayakawa","Hayasi","Hayasida","Hidaka","Higa","Higuti","Hiramatu","Hirano","Hirata","Hirayama","Hirose","Hirota","Honma","Horiguti","Horikawa","Horiuti","Hosi","Hosokawa","Hotta","Iiduka","Iizima","Ikeda","Ikegami","Imamura","Inada","Inagaki","Inoue","Isibasi","Isida","Isiguro","Isihara","Isii","Isiyama","Itikawa","Itou","Iwai","Iwamoto","Iwase","Iwata","Izumi","Kamata","Kamei","Kamiya","Kanai","Kanazawa","Kaneda","Kanesiro","Kanno","Kanou","Kasahara","Kasiwagi","Kataoka","Kawabata","Kawaguti","Kawahara","Kawai","Kawamoto","Kawamura","Kawasima","Kawata","Kaziwara","Kimura","Kitagawa","Kitano","Kitazima","Kobayasi","Koga","Koide","Koizumi","Komatu","Komori","Kondou","Konisi","Kosaka","Kouda","Kouno","Koyanagi","Kozima","Kubo","Kubota","Kudou","Kumagaya","Kurihara","Kurita","Kuroda","Kurokawa","Kurosawa","Maeda","Makino","Matubara","Matui","Matumoto","Matumura","Matuno","Matuoka","Matusita","Matuyama","Matuzaki","Miki","Minami","Misima","Miura","Miwa","Miyagawa","Miyahara","Miyamoto","Miyasita","Miyata","Miyazaki","Miyazawa","Miyazima","Miyosi","Mizoguti","Mizuno","Mizutani","Mogi","Mori","Morikawa","Morioka","Morisita","Morita","Motiduki","Mukai","Murai","Murakami","Murase","Murayama","Nagaoka","Nagasima","Nagata","Naitou","Nakagawa","Nakahara","Nakanisi","Nakao","Nakata","Nakatani","Nakayama","Nakazima","Narita","Negisi","Nemoto","Ninomiya","Nisi","Nisida","Nisihara","Nisikawa","Nisimoto","Nisimura","Nisio","Nisioka","Nisiyama","Nisizawa","Niwa","Noda","Noguti","Nomura","Nozaki","Numata","Oda","Ogasawara","Ogata","Ogawa","Ogino","Oikawa","Oka","Okabe","Okamoto","Okano","Okazaki","Okuda","Okumura","Okuyama","Ono","Onodera","Ooba","Oohira","Ookawa","Ookubo","Oomori","Oomura","Oonisi","Oono","Oosaki","Oosawa","Oosima","Oosiro","Oota","Ootake","Ootuka","Oouti","Oti","Otiai","Ozawa","Saeki","Saitou","Sakaguti","Sakai","Sakakibara","Sakamoto","Sakata","Sakuma","Sakurai","Satou","Seki","Sekine","Senda","Seto","Sibata","Sibuya","Simada","Simamura","Simizu","Simura","Sinden","Sinoda","Sinohara","Sinozaki","Siraisi","Sonoda","Suda","Sudou","Sugahara","Suge","Sugihara","Sugimoto","Sugita","Sugiura","Suzuki","Syouzi","Tabata","Taguti","Tahara","Takada","Takagi","Takahasi","Takai","Takase","Takasima","Takeda","Takei","Takemura","Takenaka","Takesita","Taketa","Takeuti","Takizawa","Tamura","Tanabe","Tani","Tanigawa","Tanoue","Tasiro","Tazima","Terada","Terazima","Tiba","Tomita","Toyoda","Tuda","Tukada","Tukamoto","Tutiya","Tutui","Tutumi","Tuzi","Ueda","Uehara","Uemura","Umeda","Uno","Usui","Utiyama","Wada","Yagi","Yaguti","Yamaguti","Yamamoto","Yamamura","Yamanaka","Yamane","Yamaoka","Yamazaki","Yano","Yasuda","Yazima","Yokawa","Yokoi","Yokota","Yokoyama","Yosida","Yosihara","Yosii","Yosimoto","Yosimura","Yosino","Yosizawa","Yuasa"};
set<string>hanguoren,ribenren;
string a;
char s[505];
int T,ans;
int ff[333];
void work()
{
	int i,len,flag=0,cnt=0,p;
	len=strlen(s);
	for(i=1;i<len;i++)
	{
		if(s[i]==' ')
		{
			p=i-1;
			break;
		}
		if(s[i-1]=='n'&&s[i]=='g') flag=1;
		if(!ff[s[i-1]]&&ff[s[i]]) cnt++;
		if(ff[s[i-1]]&&ff[s[i]]&&s[i-1]!=s[i]) cnt++;
		if(ff[s[i-1]]&&ff[s[i]]&&s[i]!=s[i-1]&&s[i]=='e') flag=1;
		if(!ff[s[i-1]]&&s[i-1]==s[i]) flag=2;
		if((s[i-1]=='e'||s[i-1]=='E')&&s[i]=='o') flag=1;
	}
	if(!ff[s[p]]&&s[p]!='n') flag=1;
	if(ff[s[0]]&&len==1) flag=1;
	if(cnt<2) flag=1;
	if(flag==1) printf("%s-ssi\n",s);
	else printf("%s-san\n",s);
/*	if(flag==1)
	{
		if(s[len-1]=='n')
		{
			ans++;
			puts(s);
		}
		
	}
	else
	{
		if(s[len-1]=='i')
		{
			ans++;
			puts(s);
		}
		
	}*/
}
int main()
{
	ans=0;
//	freopen("I.txt","r",stdin);
	memset(ff,0,sizeof(ff));
	ff['A']=ff['a']=1;
	ff['E']=ff['e']=1;
	ff['I']=ff['i']=1;
	ff['O']=ff['o']=1;
	ff['U']=ff['u']=1;
    for(int i=0;h[i][0]!='\0';++i)
    {
        a.clear();
        for(int j=0;h[i][j]!='\0';++j)
        {
            a+=h[i][j];
        }
        hanguoren.insert(a);
    }
    for(int i=0;r[i][0]!='\0';++i)
    {
        a.clear();
        for(int j=0;r[i][j]!='\0';++j)
        {
            a+=r[i][j];
        }
        ribenren.insert(a);
    }
    scanf("%d",&T);
    getchar();
    for(int i=1;i<=T;++i)
    {
        gets(s);
        a.clear();
        for(int j=0;s[j]!=' ';++j)
        {
            a+=s[j];
        }
        if(hanguoren.find(a)!=hanguoren.end())
        {
            printf("%s-ssi\n",s);
        }
        else if(ribenren.find(a)!=ribenren.end())
        {
			printf("%s-san\n",s);
		}
        else work();
    }
 //   cout<<ans<<endl;
    return 0;
}