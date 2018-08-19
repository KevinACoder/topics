#include "define.h"

void graph_demo()
{
	const int len = 5;
	graph *gh = new graph(len);

	gh->add_edge(0, 1);
	gh->add_edge(1, 2);
	gh->add_edge(2, 3);
	//gh->add_edge(3, 4);

	//gh->bfs_print(0);
	gh->dfs_print(0);
}

graph::graph(int num)
:_adj_list(nullptr),_node_list(nullptr),_node_num(num)
{
	_node_list = new int[_node_num];
	for(auto i = 0; i < _node_num; ++i)
		*(_node_list + i) = i;

	_adj_list = new sl_node*[_node_num];
	for(auto i = 0; i < _node_num; ++i)
	{
		*(_adj_list + i) = new sl_node(_node_list[i]);
	}
}

sl_node *graph::new_node(int data)
{
	return new sl_node((val_type)data);
}

void graph::add_edge(int u, int v)
{
	if(u > _node_num - 1 || v > _node_num - 1)
		return;

	sl_node *tail = get_tail(_adj_list[u]);
	tail->_next = new_node(v);
	tail = get_tail(_adj_list[v]);
	tail->_next = new_node(u);
}

void graph::bfs_print(int u)
{
	bool *visited = new bool[_node_num];
	for(int i = 0; i < _node_num; ++i)
		visited[i] = false;

	queue que;

	visited[u] = true;
	que.enqueue(u);

	while(!que.is_empty())
	{
		int s = que.dequeue();
		cout<< s <<" ";

		sl_node *adjs = _adj_list[s];
		while(adjs != nullptr)
		{
			if(!visited[(int)adjs->_val])
			{
				visited[(int)adjs->_val] = true;
				que.enqueue(adjs->_val);
			}
			adjs =adjs->_next;
		}
	}

	delete[] visited;
	cout<<endl;
}

void graph::dfs_print(int u)
{
	bool *visited = new bool[_node_num]{false};

	dfs_until(u, visited);

	delete[] visited;
	cout<<endl;
}

void graph::dfs_until(int u, bool visited[])
{
	visited[u] = true;
	cout<< u << " ";

	sl_node *adjs = _adj_list[u];
	while(adjs != nullptr)
	{
		if(!visited[(int)adjs->_val])
			dfs_until(adjs->_val, visited);

		adjs = adjs->_next;
	}

}