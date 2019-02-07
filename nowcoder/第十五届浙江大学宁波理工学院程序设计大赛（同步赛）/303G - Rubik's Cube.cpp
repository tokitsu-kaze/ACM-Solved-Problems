#include <bits/stdc++.h>
using namespace std; 
typedef std::vector<std::vector<int>> CubeGraph;
typedef int Center;
typedef std::pair<int, int> Edge;
typedef std::tuple<int, int, int> Corner;
typedef std::tuple<std::vector<Center>,
                   std::vector<Edge>,
                   std::vector<Corner>>
    Cube;

char input[11][15];
CubeGraph readCube()
{
    for(int i=0;i<9;i++) scanf(" %s",input[i]);
    CubeGraph cube(9, std::vector<int>(11, -1));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 12; j++)
            if (isdigit(input[i][j]))
                cube[i][j] = input[i][j] - '0';
    return cube;
}

const int CenterPos[][2] = {1, 4,
                            4, 1,
                            4, 4,
                            4, 7,
                            4, 10,
                            7, 4};
const int EdgePos[][2][2] = {0, 4, 3, 10,
                             1, 3, 3, 1,
                             1, 5, 3, 7,
                             2, 4, 3, 4,
                             4, 0, 4, 11,
                             4, 2, 4, 3,
                             4, 5, 4, 6,
                             4, 8, 4, 9,
                             5, 1, 7, 3,
                             5, 4, 6, 4,
                             5, 7, 7, 5,
                             5, 10, 8, 4};
const int CornerPos[][3][2] = {0, 3, 3, 0, 3, 11,
                               0, 5, 3, 8, 3, 9,
                               2, 3, 3, 2, 3, 3,
                               2, 5, 3, 5, 3, 6,
                               5, 0, 5, 11, 8, 3,
                               5, 2, 5, 3, 6, 3,
                               5, 5, 5, 6, 6, 5,
                               5, 8, 5, 9, 8, 5};

Cube resolveCube(const CubeGraph& cube)
{
    std::vector<Center> centers;
    std::vector<Edge> edges;
    std::vector<Corner> corners;
    for (int i = 0; i < 6; i++)
        centers.emplace_back(cube[CenterPos[i][0]][CenterPos[i][1]]);
    for (int i = 0; i < 12; i++)
        edges.emplace_back(cube[EdgePos[i][0][0]][EdgePos[i][0][1]],
                           cube[EdgePos[i][1][0]][EdgePos[i][1][1]]);
    for (int i = 0; i < 8; i++)
        corners.emplace_back(cube[CornerPos[i][0][0]][CornerPos[i][0][1]],
                             cube[CornerPos[i][1][0]][CornerPos[i][1][1]],
                             cube[CornerPos[i][2][0]][CornerPos[i][2][1]]);
    return make_tuple(centers, edges, corners);
}

typedef std::bitset<82> Result;
Result solveCenter(const std::vector<Center>& centers)
{
    Result dp;
    for (auto& c : centers) dp.set(c);
    return dp;
}

Result solveEdge(const std::vector<Edge>& edges)
{
    Result dp[5];
    dp[0].set(0);
    int a, b;
    for (auto& [a, b] : edges)
    {
        for (int i = 4; i; i--)
        {
            dp[i] |= (dp[i - 1] << a);
            dp[i] |= (dp[i - 1] << b);
        }
    }
    return dp[4];
}

Result solveCorner(const std::vector<Corner>& corners)
{
    Result dp[5];
    dp[0].set(0);
    for (auto& [a, b, c] : corners)
    {
        for (int i = 4; i; i--)
        {
            dp[i] |= (dp[i - 1] << a);
            dp[i] |= (dp[i - 1] << b);
            dp[i] |= (dp[i - 1] << c);
        }
    }
    return dp[4];
}

Result solve(const Result& centers, const Result& edges, const Result& corners)
{
    Result dp[3];
    dp[0] = centers;
    for (int i = 0; i < 82; i++)
        if (edges[i]) dp[1] |= (dp[0] << i);
    for (int i = 0; i < 82; i++)
        if (corners[i]) dp[2] |= (dp[1] << i);
    return dp[2];
}

const std::string yesno[] = {"No", "Yes"};

void solveTask()
{
    auto cube = resolveCube(readCube());
    auto centers = solveCenter(std::get<0>(cube));
    auto edges = solveEdge(std::get<1>(cube));
    auto corners = solveCorner(std::get<2>(cube));
    auto ans = solve(centers, edges, corners);
    int q;
    scanf("%d",&q);
    assert(q>=1&&q<=100);
    for (int i = 0, x; i < q; i++)
    {
        scanf("%d",&x);
        assert(x>=0&&x<=81);
        puts(yesno[ans[x]].c_str());
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    assert(T<=10000);
    while (T--) solveTask();
}