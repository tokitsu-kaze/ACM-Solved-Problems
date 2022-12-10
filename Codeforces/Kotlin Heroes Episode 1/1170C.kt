fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main()
{
	var t=readint()
	while(t-->0)
	{
		var a=readLine()!!
		var b=readLine()!!
		a=a+'#'
		b=b+'#'
		var i=0
		var j=0
		var ok=1
		while(1>0)
		{
			if(a[i]=='#'&&b[j]=='#') break
			if(a[i]=='#'||b[j]=='#')
			{
				ok=0
				break
			}
			if(a[i]==b[j])
			{
				i++
				j++
			}
			else
			{
				if(a[i]=='+'&&b[j]=='-')
				{
					ok=0
					break
				}
				else
				{
					if(a[i+1]!='#'&&a[i+1]==a[i]&&a[i]=='-')
					{
						i+=2
						j++
					}
					else
					{
						ok=0
						break
					}
				}
			}
		}
		if(ok==1) println("YES")
		else println("NO")
	}
}