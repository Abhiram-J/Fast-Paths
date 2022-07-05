#include <bits/stdc++.h>
using namespace std;

void djikstra(vector<vector<pair<int, int>>> &adj, int V, int start, int end)
{

    vector<int> visited(V, false);
    vector<int> dist(V, 1e9);
    vector<int> parent(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});
    dist[start] = 0;
    while (!q.empty())
    {
        int curr_u = q.top().second;
        q.pop();
        if (visited[curr_u])
            continue;
        visited[curr_u] = 1;

        for (auto &ele : adj[curr_u])
        {
            int curr_v = ele.first;
            int new_w = ele.second;
            if (!visited[curr_v] && dist[curr_u] + new_w < dist[curr_v])
            {
                dist[curr_v] = dist[curr_u] + new_w;
                parent[curr_v] = curr_u;
                q.push({dist[curr_v], curr_v});
            }
        }
    }

    vector<int> ans = {end + 1};
    int temp = end;
    while (temp != start && temp != -1)
    {
        temp = parent[temp];
        ans.push_back(temp + 1);
    }
    reverse(ans.begin(), ans.end());

    if (ans[0] != start + 1)
    {
        cout << "There are no paths between city " << start + 1 << " and city " << end + 1 << "\n";
        cout << "\n";
        return;
    }
    cout << "The fastest path is : ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ((i == ans.size() - 1) ? "\n" : " -> ");
}

int main()
{
    ios_base::sync_with_stdio(false);

    int V, E, end, start;
    cout << "\n\n\tFast Paths\n\n";
    cout << "Enter number of cities : ";
    cin >> V;
    cout << '\n';
    cout << "Enter number of roads : ";
    cin >> E;
    cout << '\n';
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cout << "Enter the cities connected by road " << i + 1 << " : ";
        cin >> u >> v;
        cout << '\n';
        cout << "Enter the length of road " << i + 1 << " : ";
        cin >> w;
        cout << '\n';
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << "Enter the starting city number : ";
    cin >> start;
    cout << '\n';

    cout << "Enter destination city number : ";
    cin >> end;
    cout << '\n';
    djikstra(adj, V, start - 1, end - 1);

    return 0;
}
