fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main()
{
	var t=readint()
	while(t-->0)
	{
		var tmp=readline_int()
		var n=tmp[0]
		var m=tmp[1]
		var a=readline_int()
		var p=readline_int().sorted()
		var res=Array(n+5){mutableListOf<Int>()}
		var tot=0
		var now=0
		for(i in 0 until m)
		{
			if(p[i]-1==now)
			{
				res[tot].add(a[now])
				now++
			}
			else
			{
				res[tot].add(a[now])
				now++
				tot++
				while(now<p[i]-1)
				{
					res[tot].add(a[now])
					tot++
					now++
				}
				res[tot].add(a[now])
				now++
			}
		}
		if(now!=n)
		{
			res[tot].add(a[now])
			now++
			tot++
			while(now<n)
			{
				res[tot].add(a[now])
				tot++
				now++
			}
		}
		for(i in 0 until tot) res[i].sort()
		var ans=Array(n+5){0}
		now=0
		for(i in 0 until tot)
		{
			for(it in res[i])
			{
				ans[now]=it
				now++
			}
		}
		var ok=1
		for(i in 1 until n)
		{
			if(ans[i]<ans[i-1]) ok=0
		}
		if(ok==1) println("YES")
		else println("NO")
	}
}