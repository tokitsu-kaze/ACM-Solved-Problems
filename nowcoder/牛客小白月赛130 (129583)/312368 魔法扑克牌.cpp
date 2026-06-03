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
	var sumn=0
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=1e6)
		sumn+=n
		require(sumn<=1e6)
		var a=readline_int()
		var b=readline_int()
		require(a.size==n)
		require(b.size==n)
		for(it in a) require(1<=it && it<=1e5)
		for(it in b) require(1<=it && it<=1e5)
		if(n>1)
		{
			for(i in 0..n-2)
			{
				var tmp=b[i]-a[i]
				a[i]+=tmp
				a[i+1]+=tmp
			}
		}
		if(a[n-1]==b[n-1]) println("Yes")
		else println("No")
	}
}
