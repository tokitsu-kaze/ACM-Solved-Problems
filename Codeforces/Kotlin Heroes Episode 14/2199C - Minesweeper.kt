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
	while(T-->0)
	{
		var k=readint()
		if(k==1)
		{
			println("YES")
			println("1")
			println("*")
			println(".")
			continue
		}
		if(k==2)
		{
			println("NO")
			continue
		}
		if(k==3)
		{
			println("YES")
			println("2")
			println("*.")
			println("..")
			continue
		}
		if(k==4)
		{
			println("NO")
			continue
		}
		if(k%5==0)
		{
			var n=k/5
			println("YES")
			println("${n*3}")
			for(i in 1..n) print(".*.")
			println()
			for(i in 1..n) print("...")
			println()
			continue
		}
		if(k%5==3)
		{
			var n=k/5
			println("YES")
			println("${n*3+2}")
			print("*.")
			for(i in 1..n) print(".*.")
			println()
			print("..")
			for(i in 1..n) print("...")
			println()
			continue
		}
		if(k%5==1)
		{
			var n=(k-6)/5
			println("YES")
			println("${n*3+4}")
			print("*.")
			for(i in 1..n) print(".*.")
			print(".*")
			println()
			print("..")
			for(i in 1..n) print("...")
			print("..")
			println()
			continue
		}
		println("NO")
	}
}
