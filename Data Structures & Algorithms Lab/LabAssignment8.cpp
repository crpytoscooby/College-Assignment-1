#include<iostream>
using namespace std;

# define V 6

// this structure is used to convert places
struct Graph
{
	string place;
	int vertex;
};

// class for DijkstrasAlgorithm
class DijkstrasAlgorithm
{		
	public:
		int visitedArray[V];	// checks if the current node is visited or not, if value is 1 i.e. the node is visited else not
		float distance[V];		// stores the distance from sourse node to current node
		int parent[V];			// stores the vertex no. of the parent node
		
	DijkstrasAlgorithm()	// default constructor
	{
		for(int i = 0; i < V; i++)
		{
			visitedArray[i] = 0;	// initializing all the vextex as 0 i.e. no node is not visited
			parent[i] = 0;			// initializing all the vextex as 0
			distance[i] = 9999;		// initializing all the distance from source vertex to 9999
		}
	}
	
	void findPath(float[V][V]);	
	int minDistance(float[V], int[V]);
	void printSPA(float[V][V], float[V], int[V], struct Graph[]);
	int searchVertex(struct Graph[], string, int);
};	

// this function is used to find the current index of the node
int DijkstrasAlgorithm::searchVertex(struct Graph g[], string p, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(g[i].place == p)
			return i;
	}
	return -1;
}

// this function is used to find the shortest root from source to destination
void DijkstrasAlgorithm::findPath(float graph[V][V])
{	
	parent[0] = -1;
	distance[0] = 0;

	for(int i = 0; i < V-1; i++)
	{
		int u = minDistance(distance, visitedArray);
		visitedArray[u] = 1;
		for(int v = 0; v < V; v++)
		{
			if(graph[u][v] != 0 && visitedArray[v] == 0 && distance[u] != 9999 && graph[u][v] + distance[u] < distance[v])
			{
				parent[v] = u;
				distance[v] = graph[u][v] + distance[u];
			}
		}
	}
}

// this function is used to find the next minimum distance from current vertex
int DijkstrasAlgorithm::minDistance(float distance[V], int visitedArray[V])
{
	float min = 9999;
	int minIndex = 0;
	for(int i = 0; i < V; i++)
	{
		if(min >= distance[i] && visitedArray[i] == 0)
		{
			min = distance[i];
			minIndex = i;
		}
	}
	return minIndex;
}

// this function is used to print the shortest distance from all the nodes to source vertex to all other vertex
void DijkstrasAlgorithm::printSPA(float graph[V][V], float distance[V], int parent[V], struct Graph g[V])
{
	cout<<"Destination"<<"\t\t"<<"Distance"<<"\t\t"<<"Path\n";
	for(int i = 0; i < V; i++)
	{
		cout<<g[i].place<<"\t\t\t"<<distance[i]<<" km\t\t\t";
		int temp = i;
		cout<<g[i].place;
		while(parent[temp] != -1)
		{
			cout<<" <- "<<g[parent[temp]].place;
			temp = parent[temp];
		}
		cout<<endl;
	}
}

int main()
{
	DijkstrasAlgorithm DA;
	
	cout<<"ABC Tours and Travels, Pune\n\n";
	int n, e;
	cout<<"Enter Number of Places to visit: ";
	cin>>n;
	cout<<"Enter Number of Routes: ";
	cin>>e;
	
	Graph g[n];
	for(int i = 0; i < n; i++)	// this for loop is used to store the adjacent index no. of the vertex
	{
		cout<<"Enter Place: ";
		cin>>g[i].place;
		g[i].vertex = i;
	}
	
	float graph[V][V];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			graph[i][j] = 0;
		}
	}
	cout<<endl<<endl;
	
	for(int i = 0; i < e; i++)
	{
		string s1, s2;
		float d;
		cout<<"Enter Source, Destination and Distance respectively: ";
		cin>>s1;
		int v1 = DA.searchVertex(g, s1, n);
		cin>>s2;
		int v2 = DA.searchVertex(g, s2, n);
        cin>>d;
        graph[v1][v2] = d;
        graph[v2][v1] = d;
	}	
	DA.findPath(graph);
	cout<<endl<<endl;
	DA.printSPA(graph, DA.distance, DA.parent, g);
	return 0;
}



/*
Test Case 1:
ABC Tours and Travels, Pune

Enter Number of Places to visit: 6
Enter Number of Routes: 9
Enter Place: Aundh
Enter Place: Baner
Enter Place: Bavdhan
Enter Place: Katraj
Enter Place: Pashan
Enter Place: Parvati


Enter Source, Destination and Distance respectively: Aundh Baner 3.7
Enter Source, Destination and Distance respectively: Aundh Bavdhan 10.3
Enter Source, Destination and Distance respectively: Baner Bavdhan 7.2
Enter Source, Destination and Distance respectively: Baner Katraj 21.8
Enter Source, Destination and Distance respectively: Bavdhan Katraj 14.8
Enter Source, Destination and Distance respectively: Bavdhan Pashan 6.0
Enter Source, Destination and Distance respectively: Katraj Pashan 19.8
Enter Source, Destination and Distance respectively: Katraj Parvati 7
Enter Source, Destination and Distance respectively: Pashan Parvati 12.9


Destination             Distance                Path
Aundh                   0 km                    Aundh
Baner                   3.7 km                  Baner <- Aundh
Bavdhan                 10.3 km                 Bavdhan <- Aundh
Katraj                  25.1 km                 Katraj <- Bavdhan <- Aundh
Pashan                  16.3 km                 Pashan <- Bavdhan <- Aundh
Parvati                 29.2 km                 Parvati <- Pashan <- Bavdhan <- Aundh


Test Case 2: (from PPT)
ABC Tours and Travels, Pune

Enter Number of Places to visit: 5
Enter Number of Routes: 7
Enter Place: A
Enter Place: B
Enter Place: C
Enter Place: D
Enter Place: E


Enter Source, Destination and Distance respectively: A B 6
Enter Source, Destination and Distance respectively: A D 1
Enter Source, Destination and Distance respectively: B C 5
Enter Source, Destination and Distance respectively: B D 2
Enter Source, Destination and Distance respectively: B E 2
Enter Source, Destination and Distance respectively: C E 5
Enter Source, Destination and Distance respectively: D E 1


Destination             Distance                Path
A                       0 km                    A
B                       3 km                    B <- D <- A
C                       7 km                    C <- E <- D <- A
D                       1 km                    D <- A
E                       2 km                    E <- D <- A


Test Case 3:
ABC Tours and Travels, Pune

Enter Number of Places to visit: 9
Enter Number of Routes: 14
Enter Place: 0
Enter Place: 1
Enter Place: 2
Enter Place: 3
Enter Place: 4
Enter Place: 5
Enter Place: 6
Enter Place: 7
Enter Place: 8


Enter Source, Destination and Distance respectively: 0 1 4
Enter Source, Destination and Distance respectively: 0 7 8
Enter Source, Destination and Distance respectively: 1 2 8
Enter Source, Destination and Distance respectively: 1 7 11
Enter Source, Destination and Distance respectively: 2 3 7
Enter Source, Destination and Distance respectively: 2 5 4
Enter Source, Destination and Distance respectively: 2 8 2
Enter Source, Destination and Distance respectively: 3 4 9
Enter Source, Destination and Distance respectively: 3 5 14
Enter Source, Destination and Distance respectively: 4 5 10
Enter Source, Destination and Distance respectively: 5 6 2
Enter Source, Destination and Distance respectively: 6 7 1
Enter Source, Destination and Distance respectively: 6 8 6
Enter Source, Destination and Distance respectively: 7 8 7


Destination             Distance                Path
0                       0 km                    0
1                       4 km                    1 <- 0
2                       12 km                   2 <- 1 <- 0
3                       19 km                   3 <- 2 <- 1 <- 0
4                       21 km                   4 <- 5 <- 6 <- 7 <- 0
5                       11 km                   5 <- 6 <- 7 <- 0
6                       9 km                    6 <- 7 <- 0
7                       8 km                    7 <- 0
8                       14 km                   8 <- 2 <- 1 <- 0
*/

/*
Real World Test Case
Aundh Baner 3.7
Aundh Bavdhan 10.3
Baner Bavdhan 7.2
Baner Katraj 21.8
Bavdhan Katraj 14.8
Bavdhan Pashan 6.0
Katraj Pashan 19.8
Katraj Parvati 7
Pashan Parvati 12.9

Aundh
Baner
Bavdhan
Katraj
Pashan
Parvati


Test Case 1
a b 4
a c 2
b c 1
b d 5
c d 8
c e 10
d e 2
d z 6
e z 5

Test Case 2
a b 7
a c 2
b c 6
b e 5
c d 4
d e 2

Test Case 3
A B 6
A D 1
B C 5
B D 2
B E 2
C E 5
D E 1

Temp Test Case
9
14
0
1
2
3
4
5
6
7
8
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

*/

