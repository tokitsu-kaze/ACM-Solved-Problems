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
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val mod=998244353//1e9.toInt()+7
const val MAX=300000+10
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(T>=1 && T<=1e4)
	while(T-->0)
	{
		var n=readint()
		require(n>=1 && n<=1e9)
		var s=n.toString()
		var cnt=IntArray(11){0}
		for(it in s) cnt[it-'0']++
		require(cnt[0]==0)
		if(n%4==0)
		{
			println("YES")
			continue
		}
		var ok=0
		for(i in 12..96)
		{
			if(i%4!=0) continue
			cnt[i%10]--
			cnt[i/10]--
			if(cnt[i%10]>=0 && cnt[i/10]>=0) ok=1
			cnt[i%10]++
			cnt[i/10]++
		}
		if(ok==1) println("YES")
		else println("NO")
	}
}

