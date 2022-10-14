#include<iostream>
#include<algorithm>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};
bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}
int findParent(int v,int *parent){
    if(parent[v]==v)
        return v;
    return findParent(parent[v],parent);
}
void kruskals(Edge *input,int n,int E){
    //Sorting in ascending order based on weight
    sort(input,input+E,compare);
    int *parent=new int[n];
    for(int i=0;i<n;i++)
        parent[i]=i;
    Edge *output = new Edge[n-1];
    int count=0,i=0;
    while(count!=n-1){
        Edge currentEdge=input[i];
        //Checking if we can add the currentEdge in MST or not
        int sourceParent=findParent(currentEdge.source,parent);
        int destParent=findParent(currentEdge.dest,parent);
        if(sourceParent!=destParent){
            output[count]=currentEdge;
            count++;
            parent[sourceParent]=destParent; //Union
        }
        i++;
    }
    int total=0;
    cout<<"\n-----MST IS-----"<<endl;
    for(int i=0;i<n-1;i++){
        if(output[i].source<output[i].dest)
            cout<<"("<<output[i].source<<","<<output[i].dest<<") Weight: "<<output[i].weight<<endl;
        else
            cout<<"("<<output[i].dest<<","<<output[i].source<<") Weight: "<<output[i].weight<<endl;
        total=total+output[i].weight;
    }
    cout<<"Total cost: "<<total<<endl;
}
int main(){
    int n,E,s,d,w;
    cout<<"Enter number of Nodes and Edges: ";
    cin>>n>>E;
    Edge *input = new Edge[E];
    for(int i=0;i<E;i++){
        cout<<"Enter source, destination and weight: ";
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    kruskals(input,n,E);
}
