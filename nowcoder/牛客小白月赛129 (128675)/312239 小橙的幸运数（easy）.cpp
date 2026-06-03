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
	var tmp_line=readline_int()
	require(tmp_line.size==3)
	var m=tmp_line[0]
	var c=tmp_line[1]
	var q=tmp_line[2]
	require(1<=m && m<=2e5)
	require(1<=c && c<=1e9)
	require(1<=q && q<=5)
	var a=readline_int()
	require(a.size==m)
	for(it in a) require(0<=it && it<=1e9)
	var sum=Array(32){IntArray(m)}
	for(i in 0..m-1) sum[0][i]=a[i]
	for(j in 1..30)
	{
		for(i in 0..m-1)
		{
			var nex=(sum[j-1][i]+i)%m
			sum[j][i]=min(sum[j-1][i]+sum[j-1][nex],INF)
		}
	}
	var res=mutableListOf<String>()
	while(q-->0)
	{
		var x=readint()
		require(1<=x && x<=1e9)
		if(x>c) res.add("No")
		else if(x==c) res.add("Yes")
		else
		{
			for(i in 30 downTo 0)
			{
				if(x+sum[i][x%m]>c) continue
				x=x+sum[i][x%m]
			}
			if(x==c) res.add("Yes")
			else res.add("No")
		}
	}
	println(res.joinToString("\n"))
}
