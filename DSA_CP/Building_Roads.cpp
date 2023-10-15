/*
Building Roads
Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,… n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints
1<=n<=10^5
1<=m<=2*(10^5)
1<=a,b<=n
Example
Input:
4 2
1 2
3 4
Output:
1
2 3
*/
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int N, M, a, b, ds[100001];
vector<pii> ans;

int find(int u){
    if(ds[u] < 0)   return u;
    ds[u] = find(ds[u]);
    return ds[u];
}

bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v)  return false;
    if(ds[u] < ds[v])   swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) ds[i] = -1;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        merge(a, b);
    }

    for(int i = 1; i < N; i++)
        if(merge(i, i+1))
            ans.push_back({i, i+1});

    printf("%d\n", (int) ans.size());
    for(pii P : ans)
        printf("%d %d\n", P.first, P.second);
}
