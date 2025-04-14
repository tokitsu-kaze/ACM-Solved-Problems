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
data class node(var p:Int,var f:Int)
fun go()
{
	var tmp_line=readline_int()
	var n=tmp_line[0]
	var k=tmp_line[1]
	var a=tmp_line[2]
	var b=tmp_line[3]
	var x=tmp_line[4]
	var y=tmp_line[5]
	require(n>=2 && n<=2e5 && n%2==0)
	require(k>=0 && k<=2e5)
	require(a>=1 && a<=n)
	require(b>=1 && b<=n)
	require(x>=1 && x<=n)
	require(y>=1 && y<=n)
	a-=1
	if(a<0) a+=n
	b-=1
	if(b<0) b+=n
	var dis=Array(n){IntArray(2){INF}}
	val q:Queue<node> = LinkedList()
	dis[a][0]=0
	q.offer(node(a,0))
	while(q.size>0)
	{
		var t=q.peek()
		q.poll()
		var nex=(t.p+x)%n
		if(dis[nex][t.f]>dis[t.p][t.f]+1)
		{
			dis[nex][t.f]=dis[t.p][t.f]+1
			q.offer(node(nex,t.f))
		}
		nex=(t.p-y+n)%n
		if(dis[nex][t.f]>dis[t.p][t.f]+1)
		{
			dis[nex][t.f]=dis[t.p][t.f]+1
			q.offer(node(nex,t.f))
		}
		if(t.f==0)
		{
			nex=(t.p+n/2)%n
			if(dis[nex][1]>dis[t.p][0]+1)
			{
				dis[nex][1]=dis[t.p][0]+1
				q.offer(node(nex,1))
			}
		}
	}
	if(k>1) k=1
	var ans=min(dis[b][k],dis[b][0])
	if(ans==INF) ans=-1
	println("${ans}")
}
