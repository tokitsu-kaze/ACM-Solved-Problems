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
const val MAX=1e6.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(T>=1 && T<=100)
	var sumn=0
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=2e5)
		sumn+=n
		require(sumn<=2e5)
		var res=mutableListOf<Int>()
		if(n%2==1)
		{
			for(i in 1..n) res.add(i)
		}
		else
		{
			if(n==2)
			{
				println("-1")
				continue
			}
			res.add(2)
			res.add(4)
			res.add(1)
			res.add(3)
			for(i in 5..n) res.add(i)
		}
		println(res.joinToString(" "))
	}
}
/*
2 4 1 3 5 6
*/
