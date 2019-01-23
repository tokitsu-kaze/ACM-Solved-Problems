package main

import "fmt"
import "os"
import "bufio"
import "strconv"

const INF int =0x3f3f3f3f
const LLINF int64 = 0x3f3f3f3f3f3f3f3f


func solve(){
    var a [100010] int
    var n,i,mn,mx,ans,tmp int
    n=readInt()
    mx=-INF
    mn=INF
    for i=0;i<n;i++{
        a[i]=readInt()
        mx=max(mx,a[i])
        mn=min(mn,a[i])
    }
    var flag int
    flag=0
    ans=INF
    tmp=-INF
    for i=0;i<n;i++{
        if a[i]==mx&&flag==0{
            flag=1
        }else{
            tmp=max(tmp,a[i])
        }
    }
    ans=min(ans,tmp-mn)
    tmp=INF
    flag=0
    for i=0;i<n;i++{
        if a[i]==mn&&flag==0{
            flag=1
        }else{
            tmp=min(tmp,a[i])
        }
    }
    ans=min(ans,mx-tmp)
    fmt.Println(ans)
}


var scanner *bufio.Scanner

func main() {
    scanner = bufio.NewScanner(os.Stdin)
    const MaxTokenLength = 1024 * 1024
    scanner.Buffer(make([]byte, 0, MaxTokenLength), MaxTokenLength)
    scanner.Split(bufio.ScanWords)
    solve()
}
func readString() string {
    scanner.Scan()
    return scanner.Text()
}

func readInt() int {
    val, _ := strconv.Atoi(readString())
    return val
}

func readInt64() int64 {
    v, _ := strconv.ParseInt(readString(), 10, 64)
    return v
}

func min(a,b int)int {
    if a<b {
        return a
    } else {
        return b
    }
}

func max(a,b int)int {
    if a>b {
        return a
    } else {
        return b
    }
}