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
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var t=readint()
	require(t>=1 && t<=100)
	while(t-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==3)
		var n=tmp_line[0]
		var a=tmp_line[1]
		var k=tmp_line[2]
		require(n>=1 && n<=100)
		require(a>=1 && a<=100)
		require(k>=1 && k<=100)
		for(i in 1..k)
		{
			if(i==1) a++
			else a+=n
			var f=0
			var tmp=a.toString()
			for(it in tmp)
			{
				if(it=='7') f=1
			}
			if(f==1||a%7==0) print("p")
			else print(tmp)
			if(i==k) println()
			else print(' ')
		}
	}
}

