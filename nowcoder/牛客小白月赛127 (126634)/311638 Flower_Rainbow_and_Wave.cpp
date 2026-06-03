import java.util.*
import kotlin.math.*
import kotlin.random.Random

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
const val MAX=1e7.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(1<=T && T<=1e4)
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=2e5)
		if(n<=2 || n==4)
		{
			println("-1")
			continue
		}
		var res=mutableListOf<Int>()
		var x=(n+1)/2
		n=n-(x*2-1)
		if(n==1)
		{
			x--
			n+=2
		}
		require(n==0 || n==3)
		if(n==3)
		{
			res.add(1)
			res.add(2)
			res.add(1)
		}
		for(i in 1..x) res.add(i)
		for(i in x-1 downTo 1) res.add(i)
		println(res.joinToString(" "))
	}
}

