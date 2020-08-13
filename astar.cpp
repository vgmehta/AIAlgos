#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node{

    int num;
    int h;
    int f;
    int g;
    Node* p;

};

bool comp(Node* a, Node* b){
    return (a->f)<(b->f);
}

Node* searchNode(vector<Node*> &nList, int nodeNum){
    for(int i=0;i<nList.size();i++){
        if(nList[i]->num == nodeNum){
            return nList[i];
        }
    }
    return NULL;
}

void addNode(vector <Node*> &nList, int n, int heu){
    Node* new_node = new Node;
    new_node->num = n;
    new_node->h = heu;
    new_node->g = 0;
    new_node->f = 0;
    nList.push_back(new_node);
}

void addEdge(vector<vector<int> >&adj, int v, int w, int weight){
    adj[v][w] = weight;
    adj[w][v] = weight;
}

void print(vector<Node*> &node_list, Node* g){
    stack <int> st;
    while(true){
        st.push(g->num);
        if(g->num == 0)
            break;
        g = g->p;
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
        if(!st.empty())
            cout<<"->";
    }
}

void propogate(vector<Node* > &nList,vector<vector<int> > adj,vector<Node *> &closed,Node *m){
    if(m == NULL){
        return;
    }
    for(int i=0;i<nList.size();i++){
        if(adj[m->num][i]!=0)
        {
            Node *temp = searchNode(nList,i);
            if(m->g + adj[m->num][i] < temp->g){
                temp->g = m->g + adj[m->num][i];
                temp->p = m;
                if(find(closed.begin(),closed.end(),temp)!= closed.end())
                {
                    propogate(nList,adj,closed,temp);
                }
            }
        }
    }

}

void astar(vector<vector<int> > adj, vector<Node*> &nList, Node* src, Node* goal, int V){
    vector<Node*> open;
    vector<Node*> closed;
    open.push_back(src);

    while(!open.empty()){
        Node* n = open.front();
        open.erase(open.begin());
        closed.push_back(n);

        cout<<"Node " << n->num << " is picked from open list"<<endl;
        if(goal->num == n->num){
            cout<<"-------------------------"<<endl;
            cout<<"-------------------------"<<endl;
            cout<<"Reached Goal State"<<endl;
            cout<<"Path: ";
            print(nList,n);
            cout<<"\nTotal cost "<<n->f<<endl;
            cout<<"-------------------------"<<endl;
            cout<<"-------------------------"<<endl;
            return;
        }
        for(int i=0;i<V;i++){
            int k = adj[n->num][i];
            if(k==0){
                continue;
            }
            Node* m = searchNode(nList,i);

            //Case 1: picked node is not in open and closed list
            if(find(open.begin(),open.end(),m) == open.end() && find(closed.begin(),closed.end(),m) == closed.end()){
                open.push_back(m);
                m->g = n->g + k;
                m->f = m->h + m->g;
                m->p = n;
            }
            //Case 2: picked node is already in open
            else if(find(open.begin(),open.end(),m) != open.end()){
                cout<<n->g;
                if(n->g + k < m->g){
                    m->g = n->g + k;
                    m->f = m->h + m->g;
                    m->p = n;
                }
            }
            //Case 3: picked node is in closed
            else{
                if(n->g + k < m->g){
                    m->g = n->g + k;
                    m->f = m->h + m->g;
                    m->p = n;
                    propogate(nList,adj,closed,m);
                }
            }
        }
        sort(open.begin(),open.end(),comp);
        cout<<"Open:"<<endl;
        for(int i=0;i<open.size();i++){
            cout<<open[i]->num<<" Cost:"<<open[i]->f<<" ";
        }
        cout<<"\nClosed:"<<endl;
        for(int i=0;i<closed.size();i++){
            cout<<closed[i]->num<<" Cost:"<<closed[i]->f<<" ";
        }
        cout<<endl;
    }
    cout<<"Node not found\n";
}

int main(){
    int V;
    fstream file;
    string f1 = "astarnode.txt";
    file.open(f1.c_str());
    vector<Node *> nList;
    string temp;
    if(file>>temp)
             V = atoi(temp.c_str());

    string word[2];
    int n1[2];
    bool flag1 = true;

        while (flag1)
    {
        for(int i=0;i<2;i++)
         {

             if(file>>word[i])
                n1[i] = atoi(word[i].c_str());
             else {
                    flag1 = false;
                    break;
             }
        }
         if(flag1){
             cout<<n1[0]<<" "<<n1[1]<<endl;
             addNode(nList,n1[0],n1[1]);
        }

    }
    file.close();

    vector< vector<int> > adj(10,vector<int>(10,0));

    string   f2;
    f2 = "astarinput.txt";
    file.open(f2.c_str());

    string words[3];
    int n[3];
    bool flag = true;

        while (flag)
    {
        for(int i=0;i<3;i++)
         {

             if(file>>words[i])
             n[i] = atoi(words[i].c_str());
             else {
                    flag = false;
                    break;
             }

         }
         if(flag){
             cout<<n[0]<<" "<<n[1]<<" "<<n[2]<<endl;
             addEdge(adj,n[0],n[1],n[2]);
        }

    }

    astar(adj,nList,nList[0],nList[V-1],V);

}





