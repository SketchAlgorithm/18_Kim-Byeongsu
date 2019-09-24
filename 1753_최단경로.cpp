#include<iostream>

using namespace std;

int V, E;
char** weight;
char* shortPath;
bool* visited;
void Dijkstra(int start);

int main(void)
{
	cin >> V >> E;

	int start;
	cin >> start;
	start--;

	weight = new char* [V];
	for (int i = 0; i < V; i++)
		weight[i] = new char[V];

	shortPath = new char[V];
	
	visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
			weight[i][j] = 11;
		shortPath[i] = 11;
		visited[i] = false;
	}
	shortPath[start] = 0;

	for (int i = 0; i < E; i++)
	{
		int row, col;
		cin >> row >> col;
		row--, col--;
		cin >> weight[row][col];
	}

	Dijkstra(start);

	for (int i = 0; i < V; i++)
	{
		if (shortPath[i] == 11)
			cout << "INF" << endl;
		else
			cout << shortPath[i] << endl;
	}

	return 0;
}

// 정점 start로 부터 시작되는 모든 정점으로의 최단 거리를 구하는 함수
void Dijkstra(int start)
{
	visited[start] = true;

	for (int i = 1; i < V; i++)
	{
		shortPath[i] = weight[start][i];
	}

	for (int i = 0; i < V - 1; i++)
	{
		int min = 11;
		int index = -1;
		for (int j = 1; j < V; j++)
		{
			if ((min > shortPath[j]) && !visited[j])
			{
				min = shortPath[j];
				index = j;
			}
		}
		if (index != -1)
		{
			visited[index] = true;
			for (int j = 1; j < V; j++)
			{
				if (!visited[j])
				{
					shortPath[j] = shortPath[j] > shortPath[index] + weight[index][j] ?
						shortPath[index] + weight[index][j] : shortPath[j];
				}
			}
		}
	}
}
