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
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(1<=T && T<=1000)
	var sumn=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var k=tmp_line[1]
		require(3<=n && n<=2e5)
		require(1<=k && k<n)
		sumn+=n
		require(sumn<=1e6)
		if(k==1)
		{
			if(n<=4) println("No")
			else
			{
				println("Yes")
				var res=mutableListOf<String>()
				res.add("1 3")
				res.add("2 3")
				for(i in 4..n) res.add("${i} ${i-1}")
				println(res.joinToString("\n"))
			}
			continue
		}
		var tmp=(n-2)/(k-1)
		var cntfa=tmp*k-(n-2)
		if(tmp<(n-1+k-1)/k || (cntfa==1 && tmp!=1))
		{
			println("No")
			continue
		}
		var d=IntArray(cntfa+1){k}
		d[cntfa]=(tmp-(cntfa-1))*k
		println("Yes")
		var res=mutableListOf<String>()
		for(i in 1..cntfa-1)
		{
			res.add("${i} ${i+1}")
			d[i]--
			d[i+1]--
			require(d[i]>=0)
			require(d[i+1]>=0)
		}
		var now=cntfa+1
		for(i in 1..cntfa)
		{
			for(j in 1..d[i])
			{
				res.add("${i} ${now}")
				require(now<=n)
				now++
			}
		}
		require(res.size==n-1)
		println(res.joinToString("\n"))
	}
}

