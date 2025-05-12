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
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(n>=1 && n<=2e5)
	var a=readline_int()
	require(a.size==n)
	var cnt=IntArray(101){0}
	var res=IntArray(n){0}
	for(i in n-1 downTo 0)
	{
		require(a[i]>=1 && a[i]<=100)
		res[i]=cnt[a[i]]
		for(j in 1..a[i]-1) cnt[j]++
	}
	var q=readint()
	require(q==1)
	while(q-->0)
	{
		var v=readint()
		require(v>=1 && v<=100)
		var now=0
		var ans=INF
		for(i in 0..n-1)
		{
			ans=min(ans,now+res[i])
			if(a[i]>v) now++
		}
		println("${ans}")
	}
}

