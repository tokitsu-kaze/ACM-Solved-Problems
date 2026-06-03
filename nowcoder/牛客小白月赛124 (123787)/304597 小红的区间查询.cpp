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
	require(1<=T && T<=1e5)
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==4)
		var a=tmp_line[0]
		var b=tmp_line[1]
		var l=tmp_line[2]
		var r=tmp_line[3]
		require(1<=a && a<b && b<=2e5)
		require(b<l && l<=r && r<=1e9)
		var d=b-a;
		var res=mutableListOf<Int>()
		var i=1
		while(i*i<=d)
		{
			if(d%i==0)
			{
				res.add(i)
				if(d/i!=i) res.add(d/i)
			}
			i++
		}
		var ans=0
		for(it in res)
		{
			if(l<=b+it && b+it<=r) ans++
		}
		println("${ans}")
	}
}

