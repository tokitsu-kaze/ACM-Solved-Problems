package main

import(
    "fmt"
    "os"
    "bufio"
    "strconv"
//    "sort"
)

const INF int =0x3f3f3f3f
const LLINF int64 = 0x3f3f3f3f3f3f3f3f
const MAX int =200000+10

func solve(){
    var n,k,i,tot,now int
    var res [MAX] int
    n=readInt()
    k=readInt()
    now=1
    for ;now<=n;now=now*2{
    }
    tot=0
    for ;n>0&&now>0;{
        if n>=now{
            n-=now
            res[tot]=now
            tot+=1
        }
        now>>=1
    }
    if tot>k{
        fmt.Println("NO")
        return
    }
    for i=0;i<tot;i++{
        for ;res[i]>1&&tot<k;{
            res[tot]=res[i]/2
            res[i]/=2
            tot+=1
        }
    }
    if tot<k{
        fmt.Println("NO")
    }else{
        fmt.Println("YES")
        for i=0;i<tot;i++{
            fmt.Print(res[i]," ")
        }
        fmt.Println()
    }
}

/***************************FastIO begin**********************************/
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
/***************************FastIO end**********************************/

/***************************sort begin**********************************/
type IntSlice []int

func (s IntSlice) Len() int { return len(s) }
func (s IntSlice) Swap(i,j int){ s[i],s[j]=s[j],s[i] }
func (s IntSlice) Less(i,j int) bool { return s[i]<s[j] }
/***************************sort end**********************************/

/*************************************************************/
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