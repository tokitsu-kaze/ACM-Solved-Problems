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
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(1<=T && T<=100)
	var sumn=0
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=1e5)
		var a=readline_ll()
		require(a.size==n)
		sumn+=n
		require(sumn<=2e5)
		var tmp=mutableListOf<pair>()
		for(i in 0..n-1)
		{
			require(1<=a[i] && a[i]<=1e18)
			tmp.add(pair(a[i],i))
		}
		tmp.sortWith(pair_cmp)
		var ans=IntArray(n){-1}
		var pre=mutableListOf<pair>()
		for(it in tmp)
		{
			for(i in pre.size-1 downTo 0)
			{
				if(it.fi%pre[i].fi!=0L)
				{
					ans[it.se]=pre[i].se+1
					break
				}
			}
			if(pre.size==0 || pre.last().fi!=it.fi) pre.add(it)
		}
		println(ans.joinToString(" "))
	}
}

