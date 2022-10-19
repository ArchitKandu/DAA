#include<iostream>
#include<algorithm>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};
int main(){
    int n,E;
    cout<<"Enter number of vertices and edges: ";
    cin>>n>>E;
    Edge *input=new Edge[E];
    for(int i=0;i<E;i++){
        int s,d,w;
        cout<<"Enter source, destination and cost: ";
        cin>>s>>d>>w;
        
    }
}