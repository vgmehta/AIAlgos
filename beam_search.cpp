#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int beamWidth = 2;
string startState = "";
string finalState = "";
vector<string> children;
string beam[2];
int score(string state1,string finalState)
{
    int ctr = 0;
    for(int i=0;i<4;i++){
        if(state1[i]^finalState[i]){
            ctr++;
        }
    }
    return ctr;
}

void generateChildren(string state)
{
    for(int i=0;i<4;i++){
        string temp = state;
        //cout<<temp<<endl;
        if(temp[i]=='0'){
            temp[i] = '1';
        }else{
            temp[i] = '0';
        }
        children.push_back(temp);
        cout<<temp<<" ";
    }
    cout<<endl;
}

bool scoreCompare(string ch1, string ch2)
{
    if(score(ch1,finalState)<score(ch2,finalState)){
        return true;
    }else{
        return false;
    }
}

void beamSearch(string startState, string finalState)
{
    int x = 0;
    bool state = true;
    if(startState == finalState){
        cout<<finalState<<endl;
    }else{
        while(state){
            if(x == 0){
                generateChildren(startState);
                x=1;
            }
            else{
                for(int i=0;i<beamWidth;i++){
                    generateChildren(beam[i]);
                }
            }
            sort(children.begin(),children.end(),scoreCompare);
            for(int i=0;i<beamWidth;i++){
                beam[i] = children[i];
                cout<<beam[i]<<"\t";
                if(beam[i] == finalState){
                    state = false;
                    break;
                }
            }
            cout<<endl;
            children.clear();
        }
    }
}

int main()
{
    cout<<"Enter initial state:"<<endl;
    cin>>startState;
    cout<<"Enter final state:"<<endl;
    cin>>finalState;
    beamSearch(startState,finalState);

    return 0;
}
