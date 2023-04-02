#include <bits/stdc++.h>
using namespace std;
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

// recursive DFS
void DFS(int node, vector<int> adj[], vector<int> &ans, int visited[])
{
    visited[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            DFS(it, adj, ans, visited);
        }
    }
}

vector<int> DFS(int n, vector<int> adj[])
{
    vector<int> ans;
    int visited[n] = {0};
    stack<int> s;
    s.push(0);
    visited[0] = 1;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        ans.push_back(node);
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                s.push(it);
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
    vector<int> ans = DFS(6, adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}