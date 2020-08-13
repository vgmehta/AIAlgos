#include<bits/stdc++.h>
#include<iostream>

using namespace std;


const int MAX = INT_MAX;
const int MIN = INT_MIN;

int minimax(int d, int index, bool maxNode, int arr[], int alpha,  int beta, int h)

{
    cout<<endl;
    cout<<"Alpha:"<<alpha<<endl;
    cout<<"Beta:"<<beta<<endl;
    cout<<"Depth:"<<d<<endl;

    if (d == h)
        return arr[index];

    if (maxNode)
    {
        int best = MIN;
        for (int i=0;i<2;i++)
        {
            int val=minimax(d+1,index*2+i,false,arr,alpha,beta,h);
            best = max(best, val);
            alpha = max(alpha, best);
            if (beta <= alpha) //alpha cutoff
                {cout<<" Alpha Cutoff"<<endl;
                cout<<"Alpha:"<<alpha<<endl;
                cout<<"Beta:"<<beta<<endl;
                break;}
        }
        return best;
    }
    else
    {
        int best = MAX;
        for (int i=0;i<2;i++)
        {
            int val=minimax(d+1,index*2+i,true,arr,alpha,beta,h);
            best = min(best, val);
            beta = min(beta, best);
            if (beta <= alpha) //beta cutoff
                {cout<<" Beta Cutoff"<<endl;
                cout<<"Alpha:"<<alpha<<endl;
                cout<<"Beta:"<<beta<<endl;
                break;}
        }
        return best;
    }
}

int log2(int n)
{
  return (n==1)? 0 : 1 + log2(n/2);
}

int main()
{
    int arr[] = {10,5,7,11,12,8,9,8,5,12,11,12,9,8,7,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int h = log2(n);
    cout <<"The optimal value is : "<< minimax(0,0,true,arr,MIN,MAX,h);
    return 0;
}
