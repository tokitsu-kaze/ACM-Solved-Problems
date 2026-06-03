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
const val MAX=1e5.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(1<=T && T<=500)
	var sumn=0
	while(T-->0)
	{
		var n=readint()
		require(1<=n && 1<=1e5)
		sumn+=n
		require(sumn<=1e5)
		var res=mutableListOf<Long>()
		var ans=0L
		for(i in 1..n)
		{
			var tmp_line=readline_ll()
			require(tmp_line.size==2)
			var a=tmp_line[0]
			var b=tmp_line[1]
			require(1<=a && a<=1e8)
			require(1<=a && a<=1e8)
			ans+=a
			res.add(b)
		}
		res.sort()
		res.reverse()
		for(i in 0..n-1) ans-=res[i]*i
		println("${ans}")
	}
}

