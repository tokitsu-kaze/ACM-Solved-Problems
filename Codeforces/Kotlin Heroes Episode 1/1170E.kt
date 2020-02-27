fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main()
{
	var tmp=readline_int()
	var n=tmp[0]
	var m=tmp[1]
	var a=readline_int()
	var bit=Array(n+1){0}
	bit[0]=0
	for(i in 0 until n) bit[i+1]=bit[i]+a[i]
	var q=readint()
	while(q-->0)
	{
		tmp=readline_int()
		var k=tmp[0]
		tmp[0]=0
		var pre=1;
		var ok=0
		for(i in 1 until k+2)
		{
			var l=pre
			var r=n
			var dt:Int
			if(i==k+1) dt=m-tmp[k]
			else dt=tmp[i]-tmp[i-1]-1
	//		println("${l} ${r} ${dt}")
			while(l<r)
			{
				var mid=(l+r)/2
				if(bit[mid+1]-bit[pre-1]<=dt) l=mid+1
				else r=mid
			}
			if(bit[l]-bit[pre-1]<=dt)
			{
				pre=l+1
				if(pre==n+1)
				{
					ok=1
					break
				}
			}
		}
		if(ok==1) println("YES")
		else println("NO")
	}
}