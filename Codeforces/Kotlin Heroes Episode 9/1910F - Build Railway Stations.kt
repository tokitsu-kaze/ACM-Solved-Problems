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
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
data class edge(var to:Int,var id:Int)
var mp=Array(1){mutableListOf<edge>()}
var a=IntArray(1)
var b=IntArray(1)
var vis=IntArray(1)
var sz=IntArray(1)
var res=mutableListOf<pair>()
var n=0
fun dfs(x:Int,fa:Int)
{
	sz[x]=1
	for(it in mp[x])
	{
		if(it.to==fa) continue
		dfs(it.to,x)
		sz[x]+=sz[it.to]
		res.add(pair(2L*sz[it.to]*(n-sz[it.to]),it.id))
	}
}
fun go()
{
	var t=readint()
	while(t-->0)
	{
		var tmp_line=readline_int()
		n=tmp_line[0]
		var k=tmp_line[1]
		mp=Array(n+1){mutableListOf<edge>()}
		a=IntArray(n-1){0}
		b=IntArray(n-1){0}
		for(i in 0..n-2)
		{
			tmp_line=readline_int()
			a[i]=tmp_line[0]
			b[i]=tmp_line[1]
			mp[a[i]].add(edge(b[i],i))
			mp[b[i]].add(edge(a[i],i))
		}
		sz=IntArray(n+1){0}
		res=mutableListOf<pair>()
		dfs(1,0)
		res.sortWith(cmp)
		vis=IntArray(n+1){1}
	//	for(it in res) println("${it.fi} ${it.se}")
		for(i in n-2 downTo 0)
		{
			var f=vis[a[res[i].se]]+vis[b[res[i].se]]
			if(k-f>=0)
			{
				k-=f
				vis[a[res[i].se]]=0
				vis[b[res[i].se]]=0
				res[i].fi/=2L
			}
		}
		var ans=0L
		for(i in 0..n-2) ans+=res[i].fi
		println("${ans}")
	}
}
