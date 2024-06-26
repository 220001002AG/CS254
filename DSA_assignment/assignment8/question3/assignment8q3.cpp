
#include <bits/stdc++.h>
using namespace std;

int parent[100005];

vector<int> present;

int edg;

struct edge {
	int src, dest, weight;
} edges[100005];

bool cmp(edge x, edge y)
{
	return x.weight < y.weight;
}


void initialise(int n)
{

	for (int i = 1; i <= n; i++)
		parent[i] = i;
}


int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

int union1(int i, int sum)
{
	int x, y;
	x = find(edges[i].src);
	y = find(edges[i].dest);
	if (x != y) {

		parent[x] = y;

	
		present.push_back(i);

		sum += edges[i].weight;
	}
	return sum;
}

int union2(int i, int sum)
{
	int x, y;
	x = find(edges[i].src);
	y = find(edges[i].dest);
	if (x != y) {
	
		parent[x] = y;


		sum += edges[i].weight;
		edg++;
	}
	return sum;
}

int main()
{
	
	int V, E;
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }
	V;inputFile>>V;
	E;inputFile>>E;


	
	initialise(V);




	vector<int> source(E,-1);
	vector<int> destination(E,-1) ;
	vector<int> weights(E,-1);

    for(int i=0;i<E;i++){
        inputFile>>source[i]>>destination[i]>>weights[i];
    }                        
	for (int i = 0; i < E; i++) {
		edges[i].src = source[i];
		edges[i].dest = destination[i];
		edges[i].weight = weights[i];
	}


	sort(edges, edges + E, cmp);

	int sum = 0;
	for (int i = 0; i < E; i++) {
		sum = union1(i, sum);
	}

	cout << "MST: " << sum << "\n";

	
	int sec_best_mst = INT_MAX;

	// setting the sum to zero again.
	sum = 0;
	int j;
	for (j = 0; j < present.size(); j++) {
		initialise(V);
		edg = 0;
		for (int i = 0; i < E; i++) {

			
			if (i == present[j])
				continue;
			sum = union2(i, sum);
		}
		
		if (edg != V - 1) {
			sum = 0;
			continue;
		}

		if (sec_best_mst > sum)
			sec_best_mst = sum;
		sum = 0;
	}
    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

	outputFile<< "Second Best MST: "
		<< sec_best_mst << "\n";
	return 0;
}
