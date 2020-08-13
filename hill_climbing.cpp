#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int score(string state1,string state2)
{
    int ctr = 0;
    for(int i=0;i<4;i++){
        if(state1[i]^state2[i]){
            ctr++;
        }
    }
    return ctr;
}

void change_4_bits_random(string startState, string finalState)
{
    srand(time(0));
    string currentState = "";
    currentState = startState;
    int ctr =0;
    cout<<"Count:"<<ctr<<" "<<currentState<<endl;
    while(currentState!=finalState){
            ctr++;
        if(currentState!=finalState){
            /*int r1 = rand()%4;
            int r2 = rand()%4;
            int r3 = rand()%4;
            while(r1==r2 && r2==r3){
                r2 = rand()%4;
            }
            while(r1==r3 && r2==r3){
                r3 = rand()%4;
            }
            /*if(r1!=3){
                r2 = r1+1;
            }else{
                r2 = 0;
            }*/
            string temp = currentState;

            for(int i=0;i<4;i++){
                if(currentState[i] == '0'){
                    temp[i] = '1';
                }else{
                    temp[i] = '0';
                }
            }
            /*cout<<"score(temp,finalState)"<<score(temp,finalState)<<endl;
            cout<<"score(currentState,finalState)"<<score(currentState,finalState)<<endl;*/
            if(score(temp,finalState)<=score(currentState,finalState))
            {
                currentState = temp;
            }
            cout<<"Count:"<<ctr<<" "<<temp<<endl;

        }else{
            break;
        }
    }
}

void change_3_bits_random(string startState, string finalState)
{
    srand(time(0));
    string currentState = "";
    currentState = startState;
    int ctr =0;
    cout<<"Count:"<<ctr<<" "<<currentState<<endl;
    while(currentState!=finalState){
            ctr++;
        if(currentState!=finalState){
            int r1 = rand()%4;
            int r2 = rand()%4;
            int r3 = rand()%4;
            while(r1==r2 && r2==r3){
                r2 = rand()%4;
            }
            while(r1==r3 && r2==r3){
                r3 = rand()%4;
            }
            /*if(r1!=3){
                r2 = r1+1;
            }else{
                r2 = 0;
            }*/
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
            if(temp[r3]=='0'){
                temp[r3] = '1';
            }else{
                temp[r3] = '0';
            }
            /*cout<<"score(temp,finalState)"<<score(temp,finalState)<<endl;
            cout<<"score(currentState,finalState)"<<score(currentState,finalState)<<endl;*/
            if(score(temp,finalState)<=score(currentState,finalState))
            {
                currentState = temp;
            }
            cout<<"Count:"<<ctr<<" "<<temp<<endl;

        }else{
            break;
        }
    }
}

void change_2_bits(string startState, string finalState)
{
    srand(time(0));
    string currentState = "";
    currentState = startState;
    int ctr =0;
    cout<<"Count:"<<ctr<<" "<<currentState<<endl;
    while(currentState!=finalState){
            ctr++;
        if(currentState!=finalState){
            int r1 = rand()%4;
            int r2;/*= rand()%4;
            while(r1!=r2){
                r2 = rand()%4;
            }*/
            if(r1!=3){
                r2 = r1+1;
            }else{
                r2 = 0;
            }
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
            /*cout<<"score(temp,finalState)"<<score(temp,finalState)<<endl;
            cout<<"score(currentState,finalState)"<<score(currentState,finalState)<<endl;*/
            if(score(temp,finalState)<=score(currentState,finalState))
            {
                currentState = temp;
            }
            cout<<"Count:"<<ctr<<" "<<temp<<endl;

        }else{
            break;
        }
    }
}

void change_2_bits_random(string startState, string finalState)
{
    srand(time(0));
    string currentState = "";
    currentState = startState;
    int ctr =0;
    cout<<"Count:"<<ctr<<" "<<currentState<<endl;
    while(currentState!=finalState){
            ctr++;
        if(currentState!=finalState){
            int r1 = rand()%4;
            int r2 = rand()%4;
            while(r1==r2){
                r2 = rand()%4;
            }
            /*if(r1!=3){
                r2 = r1+1;
            }else{
                r2 = 0;
            }*/
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
            /*cout<<"score(temp,finalState)"<<score(temp,finalState)<<endl;
            cout<<"score(currentState,finalState)"<<score(currentState,finalState)<<endl;*/
            if(score(temp,finalState)<=score(currentState,finalState))
            {
                currentState = temp;
            }
            cout<<"Count:"<<ctr<<" "<<temp<<endl;

        }else{
            break;
        }
    }
}

void change_1_bit(string startState, string finalState)
{
    srand(time(0));
    string currentState = "";
    currentState = startState;
    int ctr =0;
    cout<<"Count:"<<ctr<<" "<<currentState<<endl;
    while(currentState!=finalState){
            ctr++;
        if(currentState!=finalState){
            int r = rand()%4;
            string temp = currentState;

            if(temp[r]=='0'){
                temp[r] = '1';
            }else{
                temp[r] = '0';
            }
            /*if(score(temp,finalState)==0){
                cout<<temp<<" ";
                break;
            }
            else */if(score(temp,finalState)<=score(currentState,finalState))
            {
                currentState = temp;
            }
            cout<<"Count:"<<ctr<<" "<<temp<<endl;
        }else{
            break;
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    string startState,finalState;
    cin>>startState>>finalState;
    cout<<"Change 1 bit:"<<endl;
    change_1_bit(startState, finalState);
    cout<<endl;
    cout<<"Change 2 bits consecutively:"<<endl;
    change_2_bits(startState, finalState);
    cout<<endl;
    cout<<"Change 2 bits randomly:"<<endl;
    change_2_bits_random(startState, finalState);
    cout<<endl;
    cout<<"Change 3 bits randomly:"<<endl;
    change_3_bits_random(startState,finalState);
    cout<<endl;
    cout<<"Change 4 bits:"<<endl;
    change_4_bits_random(startState,finalState);
    return 0;
}
