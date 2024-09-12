#include <iostream>
#include <list>
using namespace std;

//number of vertices
#define N 8
//vertices
char vertices[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
//adjacency matrix
int adjacencyM[N][N]= {{0, 1, 0, 0, 0, 0, 0, 1},
                       {1, 0, 1, 0, 0, 0, 0, 0},
                       {0, 1, 0, 1, 0, 0, 0, 1},
                       {0, 0, 1, 0, 1, 0, 1, 0},
                       {0, 0, 0, 1, 0, 1, 0, 0},
                       {0, 0, 0, 0, 1, 0, 1, 0},
                       {0, 0, 0, 1, 0, 1, 0, 1},
                       {1, 0, 1, 0, 0, 0, 1, 0}};

//list mapping of vertices to mark vertex visited
int visited[N] {0};

class Hamiltonian{
public:
  //start (& end) vertex
  int start;
  //stack used as list to store the path of the cycle
  list<int> cycle;
  //varibale to mark if graph has the cycle
  bool hasCycle = false;

  //constructor
  Hamiltonian(int start){
    this->start = start;
  }

  //method to inititate the search of the Hamiltonian cycle
  void findCycle(){
    //add starting vertex to the list
    cycle.push_back(start);

    //start searching the path
    solve(start);
  }

  void solve(int vertex){
    //Base condition: if the vertex is the start vertex
    //and all nodes have been visited (start vertex twice)
    if(vertex == start && cycle.size() == N+1){
      hasCycle = true;

      //output the cycle
      displayCycle();

      //return to explore more hamiltonian cycles
      return;
    }

    //iterate through the neighbor vertices
    for(int i=0; i<N; i++){
      if(adjacencyM[vertex][i] == 1 && visited[i] == 0){
        int nbr =i;
        //visit and add vertex to the cycle
        visited[nbr] = 1;
        cycle.push_back(nbr);

        //Go to the neighbor vertex to find the cycle
        solve(nbr);

        //Backtrack
        visited[nbr] = 0;
        cycle.pop_back();
      }
    }
  }

  //Function to display hamiltonian cycle
  void displayCycle(){
    cout << "[";
    for(int v: cycle){
      cout << vertices[v] << " " ;
    }
    cout << "] \n";
  }
};

int main() {
  //Driver code
  Hamiltonian hamiltonian = Hamiltonian(0);
  hamiltonian.findCycle();

  //if the graph doesn't have any Hamiltonian Cycle
  if(!hamiltonian.hasCycle){
    cout << "No Hamiltonian Cycle";
  }
}
