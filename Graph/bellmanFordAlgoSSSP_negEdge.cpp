#include <iostream>
#define inf 1e9
using namespace std;

class Edge{

    public:
    int src, dest, weight;
};

class Graph{

    public:
    int v, e;
    
    Edge *edge;

    Graph(int v, int e){
        this->v = v;
        this->e = e;
        
        edge = new Edge[e];
    } 

    void addEdge(int u, int v, int w, int count){
        edge[count].src = u;
        edge[count].dest = v;
        edge[count].weight = w;
    }

    void printGraph(){

        for(int i=0; i<e; i++){
            cout<<edge[i].src<<"----("<<edge[i].weight<<")--->"<<edge[i].dest<<endl;
        }
    }
    void BellmanFord(int src){

        int distance[v];
        for(int i=0; i<v; i++){

            if(i == src){
                distance[i] = 0;
            }else{
                distance[i] = inf;
            }
        }

        // Relaxation code
        for(int i=1; i<=v-1; i++){
            for(int j=0; j<e; j++){

                int src = edge[j].src;
                int dest = edge[j].dest;
                int wt = edge[j].weight;

                // Relaxation check
                if(distance[src] != inf and distance[src] + wt < distance[dest]){
                    distance[dest] = distance[src] + wt;
                }
            }
        }

        for(int j=0; j<e; j++){

            int src = edge[j].src;
            int dest = edge[j].dest;
            int wt = edge[j].weight;

            // Relaxation check
            if(distance[src] != inf and distance[src] + wt < distance[dest]){
                printf("Graph has neagtive cycle");
                return;
            }
        }

        for(int i=0; i<v; i++){
            printf("%d - %d\n",i,distance[i]);
            // cout<<i<<" - "<<distance[i]<<endl;
        }
    }

};

int main(){

    int v,e;
    cin>>v>>e;

    Graph g(v, e);

    for(int i=0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g.addEdge(u, v, w, i);
    }

    g.printGraph();
    g.BellmanFord(0);
    return 0;
}