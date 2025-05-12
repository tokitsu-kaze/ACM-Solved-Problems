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
	var T=readint()
	require(T>=1 && T<=1000)
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var m=tmp_line[1]
		require(n>=1 && n<=2e5)
		require(m>=0 && m<=n)
		var ind=IntArray(n+1){0}
		var outd=IntArray(n+1){0}
		while(m-->0)
		{
			var tmp_line=readline_int()
			require(tmp_line.size==2)
			var a=tmp_line[0]
			var b=tmp_line[1]
			require(a>=1 && a<=n)
			require(b>=1 && b<=n)
			require(a!=b)
			ind[b]++
			outd[a]++
		}
		var res=mutableListOf<Int>()
		for(i in 1..n)
		{
			require(ind[i]<=1 && outd[i]<=1)
			if(ind[i]==0 && outd[i]==1) res.add(1)
			else if(ind[i]==1 && outd[i]==0) res.add(-1)
			else res.add(0) 
		}
		res.sort()
		res.reverse()
		var ans=0
		for(i in 0..n-1)
		{
			if(i%2==0) ans+=res[i]
		}
		println("${ans}")
	}
}
