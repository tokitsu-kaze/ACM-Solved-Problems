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
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val mod=998244353//1e9.toInt()+7
const val MAX=300000+10
/*------------------------------------------------------------*/
var seed=0L
fun rnd():Long
{
	var p=(1L shl 32)
	var res=seed
	seed=(seed xor ((seed shl 13) and (p-1))) and (p-1)
	seed=(seed xor ((seed shr 17) and (p-1))) and (p-1)
	seed=(seed xor ((seed shl 5) and (p-1))) and (p-1)
	return res
}
fun go()
{
	var tmp_line=readline_ll()
	require(tmp_line.size==4)
	var n=tmp_line[0].toInt()
	var m=tmp_line[1].toInt()
	var k=tmp_line[2].toInt()
	seed=tmp_line[3]
	require(n>=1 && n<=2e4)
	require(m>=1 && m<=200)
	require(k>=1 && k<=5e6)
	require(seed>=0 && seed<(1L shl 32))
	var mp=Array(n+1){IntArray(m+1){0}}
	var del=Array(m+1){mutableListOf<Int>()}
	for(j in 1..m)
	{
		for(i in 1..n) del[j].add(i)
	}
	while(k-->0)
	{
		var op=(rnd() and 1).toInt()+1
		if(op==1)
		{
			var y=(rnd()%m).toInt()+1
			var x=(rnd()%(n*m)).toInt()+1
			for(it in del[y]) mp[it][y]=x
			del[y].clear()
		}
		else
		{
			var x=(rnd()%n).toInt()+1
			var y=(rnd()%m).toInt()+1
			if(mp[x][y]>0)
			{
				del[y].add(x)
				mp[x][y]=0
			}
		}
	}
	var ans=0L
	for(i in 1..n)
	{
		for(j in 1..m)
		{
			ans=ans xor (1L*mp[i][j]*((i-1)*m+j))
		}
	}
	println("${ans}")
}
