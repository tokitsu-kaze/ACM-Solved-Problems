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
data class pair(var first:Int,var second:Int)
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e7.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(1<=n && n<=1e5)
	var a=readline_int()
	require(a.size==n)
	for(it in a) require(0<=it && it<=1e9)
	var mp:MutableMap<Int,Int> = mutableMapOf()
	for(i in 1..n)
	{
		var x=(a[i-1] xor i)
		mp[x]=(mp[x]?:0)+1
	}
	var ans=0
	for((v,cnt) in mp) ans=max(ans,cnt)
	println("${n-ans}")
}
