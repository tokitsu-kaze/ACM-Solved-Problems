import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(n>=1 && n<=1e5)
	var a=readline_int()
	require(a.size==n)
	var negsum=IntArray(n+5)
	var cnt=Array(105){IntArray(n+5)}
	negsum[0]=0
	for(i in 0..100) cnt[i][0]=0
	for(i in 1..n)
	{
		require(abs(a[i-1])>=1 && abs(a[i-1])<=100)
		negsum[i]=negsum[i-1]
		for(j in 0..100) cnt[j][i]=cnt[j][i-1]
		if(a[i-1]<0) negsum[i]+=-a[i-1]
		else cnt[a[i-1]][i]++
	}
	var q=readint()
	require(q>=1 && q<=1e5)
	while(q-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var l=tmp_line[0]
		var r=tmp_line[1]
		require(l>=1 && l<=n)
		require(r>=l && r<=n)
		var now=negsum[r]-negsum[l-1]
		var ansr=1
		var sub=0
		for(i in 1..100)
		{
			var tmp=cnt[i][r]-cnt[i][l-1]
			ansr+=tmp
			if(now>0)
			{
				if(now>=tmp*i)
				{
					now-=tmp*i
					sub+=tmp
				}
				else
				{
					sub+=now/i
					now=0
				}
			}
		}
		var ansl=ansr-sub
//		println("${ansl} ${ansr} ${sub}")
		println("${ansr-ansl+1}")
	}
}

