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
	require(1<=T && T<=5e5)
	var res=mutableListOf<Int>()
	while(T-->0)
	{
		var tmp_line=readline_ll()
		require(tmp_line.size==2)
		var x=tmp_line[0]
		var y=tmp_line[1]
		require(0<=x && x<=1e18)
		require(0<=y && y<=1e18)
		var ans=INF
		for(i in 0..60)
		{
			var tmp=(x shr i)
			if(tmp==y) ans=min(ans,i)
			else if(tmp xor (tmp and y)==0L) ans=min(ans,i+1)
		}
		res.add(ans)
	}
	println(res.joinToString("\n"))
}

