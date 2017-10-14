std::vector<ll> adj[100010];
ll dis[100010];

void bfs(ll u)
{
	memset(dis, -1, sizeof(dis));
	queue<ll> q;
	q.push(u);
	dis[u] = 0;
	while(!q.empty())
	{
		ll t = q.front(); 
		// DEBUG(t);
		q.pop();
		for (auto it = adj[t].begin(); it != adj[t].end(); it++)
		{
			ll v = *it;
			if(dis[v] == -1)
			{
				q.push(v);
				dis[v] = dis[t] + 1;
				// DEBUG(v);
			}
		}
	}
}