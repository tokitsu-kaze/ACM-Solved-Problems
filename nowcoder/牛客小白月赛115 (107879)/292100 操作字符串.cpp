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
fun gcd(a:Int,b:Int):Int
{
	if(b==0) return a
	return gcd(b,a%b)
}
fun go()
{
	var sumlen=0
	var n=readint()
	require(n>=2 && n<=1e5)
	var tmp=mutableListOf<String>()
	var g=0
	for(i in 0..n-1)
	{
		var s=readstring()
		sumlen+=s.length
		require(sumlen>=1 && sumlen<=2e5)
		g=gcd(g,s.length)
		tmp.add(s)
	}
	var cnt=Array(g){IntArray(26){0}}
	var tot=IntArray(g){0}
	for(s in tmp)
	{
		for(i in 0..s.length-1)
		{
			require(s[i]>='a' && s[i]<='z')
			tot[i%g]++
			cnt[i%g][s[i]-'a']++
		}
	}
	var ans=0
	for(i in 0..g-1)
	{
		var mn=INF
		for(j in 0..25) mn=min(mn,tot[i]-cnt[i][j])
		ans+=mn
	}
	println("${ans}")
}

