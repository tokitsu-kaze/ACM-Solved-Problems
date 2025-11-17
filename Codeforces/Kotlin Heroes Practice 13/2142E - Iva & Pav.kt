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
data class pair(var fi:Long,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var n=readint()
		var a=readline_int()
		var res=Array(20){IntArray(n+1)}
		for(i in 1..n) res[0][i]=a[i-1]
		
		for(i in 1..19)
		{
			for(j in 1..n-(1 shl (i-1)))
			{
				res[i][j]=(res[i-1][j] and res[i-1][j+(1 shl (i-1))])
			}
		}
		var q=readint()
		var ans=mutableListOf<Int>()
		while(q-->0)
		{
			var tmp_line=readline_int()
			var l=tmp_line[0]
			var k=tmp_line[1]
			var now=(1 shl 30)-1
			for(i in 19 downTo 0)
			{
				if(l+(1 shl i)-1<=n && (now and res[i][l])>=k)
				{
					now=now and res[i][l]
					l+=(1 shl i)
				}
			}
			if(now==(1 shl 30)-1) ans.add(-1)
			else ans.add(l-1)
		}
		println(ans.joinToString(" "))
	}
}

