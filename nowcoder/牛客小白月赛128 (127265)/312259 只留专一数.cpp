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
	require(1<=T && T<=2e4)
	var sumn=0
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=2e5)
		sumn+=n
		require(sumn<=2e5)
		var a=readline_int()
		require(a.size==n)
		for(it in a) require(1<=it && it<=1e3)
		var vis=IntArray(1001){0}
		var ok=0
		for(it in a)
		{
			if(it==1)
			{
				ok=1
				break
			}
			if(vis[it]==1) continue
			vis[it]=1
			var x=it
			ok=1
			for(i in 2..x)
			{
				if(x%i!=0) continue
				while(x%i==0) x/=i
				if(x>1)
				{
					ok=0
					break
				}
			}
			if(ok==1) break
		}
		if(ok==1) println("YES")
		else println("NO")
	}
}

