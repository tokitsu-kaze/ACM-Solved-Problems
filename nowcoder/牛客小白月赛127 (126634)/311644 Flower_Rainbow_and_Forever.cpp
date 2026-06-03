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
data class edge(var x:Int,var y:Int)
fun go()
{
	var T=readint()
	require(1<=T && T<=1e4)
	var sumn=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var k=tmp_line[1]
		require(1<=n && n<=2e5)
		require(1<=k && k<=1e9)
		sumn+=n
		require(sumn<=2e5)
		var a=readline_int()
		require(a.size==n)
		var p=Array(3){mutableListOf<Int>()}
		// p[0]->odd, p[1]->even, p[2]->4
		for(i in 0..n-1)
		{
			require(1<=a[i] && a[i]<=1e9)
			if(a[i]%4==0) p[2].add(i)
			else if(a[i]%2==0) p[1].add(i)
			else p[0].add(i)
		}
		val q:Queue<Int> = LinkedList()
		var rt=0
		for(i in 0..2)
		{
			if(p[i].size>0)
			{
				q.offer(p[i].last())
				rt=p[i].last()
				p[i].removeLast()
				break
			}
		}
		var res=mutableListOf<edge>()
		while(!q.isEmpty())
		{
			var t=q.peek()
			q.poll()
			if(a[t]%2==1)
			{
				if(p[2].size==0) continue
				res.add(edge(p[2].last(),t))
				q.offer(p[2].last())
				p[2].removeLast()
			}
			else if(a[t]%4==0)
			{
				var nowk=k
				while(nowk>0)
				{
					if(p[0].size>0)
					{
						res.add(edge(p[0].last(),t))
						q.offer(p[0].last())
						p[0].removeLast()
						nowk--
					}
					else if(p[1].size>0)
					{
						res.add(edge(p[1].last(),t))
						q.offer(p[1].last())
						p[1].removeLast()
						nowk--
					}
					else break
				}
				if(nowk==k)
				{
					if(p[2].size>0)
					{
						res.add(edge(p[2].last(),t))
						q.offer(p[2].last())
						p[2].removeLast()
					}
				}
			}
			else // even
			{
				for(i in 1..2)
				{
					if(p[i].size>0)
					{
						res.add(edge(p[i].last(),t))
						q.offer(p[i].last())
						p[i].removeLast()
						break
					}
				}
			}
		}
		if(res.size==n-1)
		{
			println("${rt+1}")
			for(it in res)
			{
				require(1L*a[it.x]*a[it.y]%4==0L)
				println("${it.x+1} ${it.y+1}")
			}
		}
		else println("-1")
	}
}
/*
1个奇-1个4倍数-k个奇-1个4倍数-偶偶偶偶
4倍数底下送k-1个奇数
先把奇偶接完，最后接4 
*/
