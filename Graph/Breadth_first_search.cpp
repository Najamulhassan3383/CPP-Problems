#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// make a adjacency list
void adjacency_list(vector<int> adj[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
vector<int> BFS(int n, vector<int> adj[])
{
    vector<int> ans;
    int visited[n] = {0};
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> adj[5 + 1];
    adjacency_list(adj);
    vector<int> ans = BFS(6, adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}