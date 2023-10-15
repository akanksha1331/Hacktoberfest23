/*
Hamiltonian Flights
There are n cities and m flight connections between them. You want to travel from Syrjälä to Lehmälä so that you visit each city exactly once. How many possible routes are there?

Input
The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Lehmälä.

Then, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. All flights are one-way flights.

Output
Print one integer: the number of routes modulo 10^9+7.

Constraints
2 ≤ n ≤ 20
1 ≤ m ≤ n^2
1 ≤ a,b ≤ n

Example
Input:

4 6
1 2
1 3
2 3
3 2
2 4
3 4
Output:

2
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxN = 20;
const int SIZE = 1<<maxN;
const ll MOD = 1e9+7;

int N, M;
bool inqueue[maxN][SIZE];
ll dp[maxN][SIZE];
vector<int> G[maxN];
queue<pii> Q;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a-1].push_back(b-1);
    }

    dp[0][1] = 1;
    Q.push({0, 1});
    inqueue[0][1] = true;
    while(!Q.empty()){
        int u = Q.front().first;
        int mask = Q.front().second;
        Q.pop();

        if(u != N-1){
            for(int v : G[u]){
                int newMask = mask|(1<<v);
                if((mask&(1<<v)) == 0){
                    dp[v][newMask] += dp[u][mask];
                    dp[v][newMask] %= MOD;
                    if(!inqueue[v][newMask]){
                        Q.push({v, newMask});
                        inqueue[v][newMask] = true;
                    }
                }
            }
        }
    }

    printf("%lld\n", dp[N-1][(1<<N)-1]);
}
