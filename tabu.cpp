#include<iostream>
#include <bits/stdc++.h>

using namespace std;

string startState = " ";
string finalState = " ";
int tenure;
int tt[4] = {0,0,0,0};

void change_1_bit(string startState, string finalState,int tenure)
{
    srand(time(0));
    string currentState = "";
    currentState = startState;
    int ctr =1;
    cout<<"Count:"<<ctr<<" "<<currentState<<endl;
    while(currentState!=finalState){

        ctr++;
        int r = 0;
        int flag = 0;
        for(int i=0;i<4;i++){
            if(tt[i]!=0)
                flag++;
        }
        if(flag!=4){
            do{
                r = rand()%4;
            }while(tt[r]!=0);
            string temp = currentState;

            if(temp[r]=='0'){
                temp[r] = '1';
            }else{
                temp[r] = '0';
            }
            tt[r] = tenure;
            currentState = temp;
            cout<<"Count:"<<ctr<<" "<<currentState<<endl;
            for(int i=0;i<4;i++){
                if(r!=i && tt[i]!=0){
                    tt[i]-=1;
                }
                cout<<tt[i]<<" ";
            }
            cout<<endl;
        }else{
            break;
        }

    }
}

void change_2_bits_random(string startState, string finalState, int tenure)
{
    srand(time(0));
    string currentState = "";
    currentState = startState;
    int ctr =1;
    cout<<"Count:"<<ctr<<" "<<currentState<<endl;
    while(currentState!=finalState){
        ctr++;
        int flag = 0;
        for(int i=0;i<4;i++){
            if(tt[i]!=0)
                flag++;
        }
        if((flag<3) && (ctr<150)){
            int r1, r2;
            do{
                r1 = rand()%4;
                r2 = rand()%4;
            }while(((tt[r2]!=0) || (tt[r1] != 0)) || (r1==r2));
            tt[r1] = tenure;
            tt[r2] = tenure;
            string temp = currentState;

            if(temp[r1]=='0'){
                temp[r1] = '1';
            }else{
                temp[r1] = '0';
            }
            if(temp[r2]=='0'){
                temp[r2] = '1';
            }else{
                temp[r2] = '0';
            }
            currentState = temp;
            cout<<"Count:"<<ctr<<" "<<currentState<<endl;
            for(int i=0;i<4;i++){
                if(r1!=i && r2!=i && tt[i]!=0){
                    tt[i]-=1;
                }
                cout<<tt[i]<<" ";
            }
            cout<<endl;
           }else{
           cout<<"Aspiration criteria applied"<<endl;
           for(int i=0;i<4;i++){
                tt[i] = 0;
           }
           change_1_bit(currentState, finalState, tenure);
           break;
        }
    }
}

void tabuSearch(string startState, string finalState, int tenure)
{
    bool state = false;
    string currentState = startState;
    if(startState == finalState){
        cout<<finalState<<endl;
    }else{
        change_2_bits_random(startState, finalState, tenure);
    }
}

int main()
{
    cout<<"Enter initial state:"<<endl;
    cin>>startState;
    cout<<"Enter final state:"<<endl;
    cin>>finalState;
    cout<<"Enter tenure"<<endl;
    cin>>tenure;
    tabuSearch(startState,finalState,tenure);

    return 0;
}
