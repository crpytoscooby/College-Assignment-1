#include<iostream>
using namespace std;

class Prims
{
	public:
	int V;
	void displayGraph(int[20][20]);
	int minKey(int[20], int[20]);
	void findMST(int[20][20]);
	int printMST(int[20], int[20][20]);	
};

void Prims::displayGraph(int graph[20][20])
{
	cout<<"\nAdjecency Matrix:\n";
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{
			cout<<graph[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int Prims::minKey(int key[20], int visitedArray[20])
{
	int min = 9999, minIndex;
	for(int v = 0; v < V; v++)
	{
		if(visitedArray[v] == 0 && key[v] < min)
		{
			min = key[v];
			minIndex = v;
		}
	}
	return minIndex;
}

void Prims::findMST(int graph[20][20])
{
	int parent[20];
	int key[20];
	int visitedArray[20];
	
	for(int i = 0; i < V; i++)
	{
		key[i] = 9999;
		visitedArray[i] = 0;
	}
	
	key[0] = 0;
	parent[0] = -1;
	
	for(int i = 0; i < V-1; i++)
	{
		int u = minKey(key, visitedArray);
		visitedArray[u] = 1;
		for(int v = 0; v < V; v++)
		{
			if(graph[u][v] != 0 && visitedArray[v] == 0 && graph[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}
	printMST(parent, graph);
}

int Prims::printMST(int parent[20], int graph[20][20])
{
	int minCost = 0;
	cout<<"Edge\tCost\n";
	for(int i = 1; i < V; i++)
	{
		cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<endl;
		minCost += graph[i][parent[i]];
	}
	cout<<"Minimum cost of MST by Prim's Algorithm: "<<minCost;
}

class Kruskals
{
	public:
	int V;
	void displayGraph(int[20][20]);
	int parent(int, int[20]);
	void updateParent(int, int, int[20]);
	void findMST(int[20][20]);
};

void Kruskals::displayGraph(int graph[20][20])
{
	cout<<"\nAdjecency Matrix:\n";
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{
			cout<<graph[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int Kruskals::parent(int v, int p[20])
{
	if(v == p[v])
		return v;
	return parent(p[v], p);
}

void Kruskals::updateParent(int v2, int v1, int p[20])
{
	while(true)
	{
		if(p[v2] == v2)
		{
			p[v2] = v1;
			break;
		}
		else
		{
			v2 = p[v2];
		}
	}
}

void Kruskals::findMST(int graph[20][20])
{
	int i, j;
	int r[20][20], p[20];
	int v1, v2, cost, min, count=1;
	int minCost = 0;
	
	for(int i = 0; i < V; i++)
	{
		p[i] = i;
	}
	
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{
			if(graph[i][j] == 0)
			{
				r[i][j] = 9999;
			}
			else
			{
				r[i][j] = graph[i][j];
			}
		}
	}
	cout<<"Edge\tWeight\n";
	while(count < V)
	{
		min = 9999;
		for(int i = 0; i < V; i++)
		{
			for(int j = 0; j < V; j++)
			{
				if(min>r[i][j])
				{	
					min = r[i][j];
					v1 = i;
					v2 = j;
				}
			}
		}
		if(parent(v1, p) != parent(v2, p))
		{
			cout<<v1<<" - "<<v2<<"\t"<<min<<endl;
			minCost += min;
			updateParent(v2, v1, p);
			r[v1][v2]=9999;
			r[v2][v1]=9999;
			count++;
		}
		else
		{
			r[v1][v2]=9999;
			r[v2][v1]=9999;
		}
	}
	cout<<"\nMinimum cost of MST by Kruskal's Algorithm is "<<minCost<<"\n";
}



int main()
{
	Prims P;
    Kruskals K;
    int V, v1, v2, w, e;
    int graph[20][20];
    int choice;
    
    
    
	cout<<"Enter number of vertices: ";
    cin>>V;
	P.V = V;
	K.V = V;
    cout<<"Enter number of edges: ";
    cin>>e;
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            graph[i][j] = 0;     //Initialize cost matrix
        }
    }
    for(int i=0; i<e; i++)
    {
        cout<<"Enter Source, Destination and Weight respectively: ";
        cin>>v1>>v2>>w;
          
        graph[v1][v2] = w;
        graph[v2][v1] = w;
    }
    
    
    cout<<"\nCalculate Minimum Spanning Tree\n";
    do
    {
    	cout<<endl;
    	cout<<"1) Prims Algorithm\n";
    	cout<<"2) Kruskals Algorithm\n";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			P.displayGraph(graph);
    			cout<<"\nUsing Prim's Algorithm: "<<endl;
    			P.findMST(graph); 
    			cout<<endl;
    			break;
    		case 2:
				cout<<endl;
    			K.displayGraph(graph);
    			cout<<"\nUsing Kruskal's Algorithm: "<<endl;
    			K.findMST(graph);
    			break;
    		default:
    			cout<<"Invalid Input\n";
    			break;  			
		}
		cout<<"Press 1 to continue or 0 to exit\n";
		cin>>choice;
	}while(choice != 0);
	return 0;
}

/*
OUTPUT

Test Case 1:
Enter number of vertices: 6
Enter number of edges: 9
Enter source, destination and cost respectively: 0 1 2
Enter source, destination and cost respectively: 0 3 1
Enter source, destination and cost respectively: 0 4 4
Enter source, destination and cost respectively: 1 2 3
Enter source, destination and cost respectively: 1 3 3
Enter source, destination and cost respectively: 1 5 7
Enter source, destination and cost respectively: 2 5 8
Enter source, destination and cost respectively: 2 3 5
Enter source, destination and cost respectively: 3 4 9

Calculate Minimum Spanning Tree

1) Prims Algorithm
2) Kruskals Algorithm
1

Adjecency Matrix:
0       2       0       1       4       0
2       0       3       3       0       7
0       3       0       5       0       8
1       3       5       0       9       0
4       0       0       9       0       0
0       7       8       0       0       0

Using Prim's Algorithm:
Edge    Cost
0 - 1   2
1 - 2   3
0 - 3   1
0 - 4   4
1 - 5   7
Minimum cost of MST by Prim's Algorithm: 17
Press 1 to continue or 0 to exit
1


1) Prims Algorithm
2) Kruskals Algorithm
2


Adjecency Matrix:
0       2       0       1       4       0
2       0       3       3       0       7
0       3       0       5       0       8
1       3       5       0       9       0
4       0       0       9       0       0
0       7       8       0       0       0

Using Kruskal's Algorithm: 
Edge    Weight
0 - 3   1
0 - 1   2
1 - 2   3
0 - 4   4
1 - 5   7

Minimum cost of MST by Kruskal's Algorithm is 17

Press 1 to continue or 0 to exit
0



Test Case 2:
Enter number of vertices: 8
Enter number of edges: 13
Enter Source, Destination and Weight respectively: 0 1 1
Enter Source, Destination and Weight respectively: 0 7 3
Enter Source, Destination and Weight respectively: 1 7 4
Enter Source, Destination and Weight respectively: 1 6 5
Enter Source, Destination and Weight respectively: 1 2 2
Enter Source, Destination and Weight respectively: 2 6 6
Enter Source, Destination and Weight respectively: 2 3 4
Enter Source, Destination and Weight respectively: 3 6 7
Enter Source, Destination and Weight respectively: 3 5 6
Enter Source, Destination and Weight respectively: 3 4 7
Enter Source, Destination and Weight respectively: 4 5 8
Enter Source, Destination and Weight respectively: 5 6 1
Enter Source, Destination and Weight respectively: 6 7 8

Calculate Minimum Spanning Tree

1) Prims Algorithm
2) Kruskals Algorithm
1

Adjecency Matrix:
0       1       0       0       0       0       0       3
1       0       2       0       0       0       5       4
0       2       0       4       0       0       6       0
0       0       4       0       7       6       7       0
0       0       0       7       0       8       0       0
0       0       0       6       8       0       1       0
0       5       6       7       0       1       0       8
3       4       0       0       0       0       8       0

Using Prim's Algorithm:
Edge    Cost
0 - 1   1
1 - 2   2
2 - 3   4
3 - 4   7
6 - 5   1
1 - 6   5
0 - 7   3
Minimum cost of MST by Prim's Algorithm: 23
Press 1 to continue or 0 to exit
1

1) Prims Algorithm
2) Kruskals Algorithm
2

Adjecency Matrix:
0       1       0       0       0       0       0       3
1       0       2       0       0       0       5       4
0       2       0       4       0       0       6       0
0       0       4       0       7       6       7       0
0       0       0       7       0       8       0       0
0       0       0       6       8       0       1       0
0       5       6       7       0       1       0       8
3       4       0       0       0       0       8       0

Using Kruskal's Algorithm: 
Edge    Weight
0 - 1   1
5 - 6   1
1 - 2   2
0 - 7   3
2 - 3   4
1 - 6   5
3 - 4   7

Minimum cost of MST by Kruskal's Algorithm is 23
Press 1 to continue or 0 to exit
0



Test Case 3:
Enter number of vertices: 7
Enter number of edges: 9
Enter Source, Destination and Weight respectively: 0 1 28
Enter Source, Destination and Weight respectively: 0 5 10
Enter Source, Destination and Weight respectively: 1 2 16
Enter Source, Destination and Weight respectively: 1 6 14
Enter Source, Destination and Weight respectively: 2 3 12
Enter Source, Destination and Weight respectively: 3 6 18
Enter Source, Destination and Weight respectively: 3 4 22
Enter Source, Destination and Weight respectively: 4 6 24
Enter Source, Destination and Weight respectively: 4 5 25

Calculate Minimum Spanning Tree

1) Prims Algorithm
2) Kruskals Algorithm
1

Adjecency Matrix:
0       28      0       0       0       10      0
28      0       16      0       0       0       14
0       16      0       12      0       0       0
0       0       12      0       22      0       18
0       0       0       22      0       25      24
10      0       0       0       25      0       0
0       14      0       18      24      0       0

Using Prim's Algorithm:
Edge    Cost
2 - 1   16
3 - 2   12
4 - 3   22
5 - 4   25
0 - 5   10
1 - 6   14
Minimum cost of MST by Prim's Algorithm: 99
Press 1 to continue or 0 to exit
1

1) Prims Algorithm
2) Kruskals Algorithm
2


Adjecency Matrix:
0       28      0       0       0       10      0
28      0       16      0       0       0       14
0       16      0       12      0       0       0
0       0       12      0       22      0       18
0       0       0       22      0       25      24
10      0       0       0       25      0       0
0       14      0       18      24      0       0

Using Kruskal's Algorithm: 
Edge    Weight
0 - 5   10
2 - 3   12
1 - 6   14
1 - 2   16
3 - 4   22
4 - 5   25

Minimum cost of MST by Kruskal's Algorithm is 99
Press 1 to continue or 0 to exit
0

*/





















////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///*// #include<iostream>
//// #include<vector>
//#include<bits/stdc++.h>
//using namespace std;
//
//void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight)
//{
//    adj[u].push_back(make_pair(v, weight));
//    adj[v].push_back(make_pair(u, weight));
//}
//
//void printGraph(vector<pair<int, int>> adj[], int V)
//{
//    for(int i = 0; i < V; i++)
//    {
//        cout << "Node " << i << " makes an edge with \n"; 
//        for(auto j = adj[i].begin(); j!=adj[i].end(); j++)
//        {
//            int v = j->first;
//            int w = j->second;
//            cout << "\tNode " << v << " with edge weight = "<< w << "\n";
//        }
//        cout<<"\n";
//    }
//}
//
//void selectMinVertex(vector<pair<int, int>> adj[], vector<int> visitedArray)
//{
//    cout<<endl;
//}
//
//void findMST(vector<pair<int, int>> adj[], int V)
//{
//    int parent[V];
//    vector<int> value(V, INT_MAX);
//    vector<int> visitedArray(V, 0);
//
//    parent[0] = -1;
//    value[0] = 0;
//
//    for(int i = 0; i < V-1; i++)
//    {
//        int minValue = selectMinVertex(adj, visitedArray);
//        visitedArray[minValue] = 1;
//        for(auto j = adj[i].begin(); j != adj[i].end(); j++)
//        {
//            
//        }
//    }
//}
//
//int main()
//{
//    int V = 5; 
//    vector<pair<int, int>> adj[V];
//    addEdge(adj, 0, 1, 10); 
//    addEdge(adj, 0, 4, 20); 
//    addEdge(adj, 1, 2, 30); 
//    addEdge(adj, 1, 3, 40); 
//    addEdge(adj, 1, 4, 50); 
//    addEdge(adj, 2, 3, 60); 
//    addEdge(adj, 3, 4, 70); 
//    printGraph(adj, V); 
//    return 0; 
//}
//*/
