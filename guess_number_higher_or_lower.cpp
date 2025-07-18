#include<bits/stdc++.h>
using namespace std;


//predefined api
int guess(int num);
int guessNumber(int n);

int pick;

int main()
{
    int n;
    cin>>n>>pick;

    cout<<guessNumber(n);


    return 0;
}

int guess(int num)
{
    if (num == pick)
    {
        return 0;
    }

    return num > pick ? -1 : 1;
}

int guessNumber(int n)
{
    int low = 1;
    int high = n;

    int c = 1;
    while(high >= low)
    {
        int mid = low + ((high - low) / 2);
        cout<< c << ": "<< mid<<endl;
        if(guess(mid) == 0)
        {
            return mid;
        }
        else if(guess(mid) == 1)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        c++;

    }

    return -1;
}



