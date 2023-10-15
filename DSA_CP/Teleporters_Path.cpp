/*
Teleporters Path
A game has n levels and m teleporters between them. You win the game if you move from level 1 to level n using every teleporter exactly once.

Can you win the game, and what is a possible way to do it?

Input
The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1,2,…,n.

Then, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.

You can assume that each pair (a,b) in the input is distinct.

Output
Print m+1 integers: the sequence in which you visit the levels during the game. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

Constraints
2 ≤ n ≤ 10^5
1 ≤ m ≤ 2*10^5
1 ≤ a,b ≤ n

Example
Input:

5 6
1 2
1 3
2 4
2 5
3 1
4 2
Output:

1 3 1 2 4 2 5
*/
//Solution
#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

bool vis[maxN];
int N, M, in[maxN];
vector<int> tour, G[maxN];
stack<int> S;

void dfs(int u = 1, int p = -1){
    vis[u] = true;
    for(int v : G[u])
        if(v != p && !vis[v])
            dfs(v, u);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        in[b]++;
    }

    dfs();
    bool exists = vis[N];
    exists &= (in[1]+1 == (int) G[1].size());
    exists &= (in[N]-1 == (int) G[N].size());
    for(int i = 2; i < N; i++){
        exists &= (in[i] == (int) G[i].size());
        if(!vis[i]) exists &= (in[i] == 0 && G[i].size() == 0);
    }

    if(!exists){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    S.push(1);
    while(!S.empty()){
        int u = S.top();
        if(!G[u].empty()){
            int v = G[u].back();
            G[u].pop_back();
            S.push(v);
        } else {
            tour.push_back(u);
            S.pop();
        }
    }

    reverse(tour.begin(), tour.end());
    for(int i = 0; i < M+1; i++)
        printf("%d%c", tour[i], (" \n")[i==M]);
}
