#include<bits/stdc++.h>
using namespace std;

class RecentCounter
{
private:
    vector<int>requests;

public:
    int ping(int t)
    {
        requests.push_back(t);

        int length = requests.size();

        int i = length-1;

        int numberOfRequest = 0;
        while(i>=0 && (requests[i] >= (t-3000) && requests[i] <= t))
        {
            numberOfRequest++;
            i--;
        }

        return numberOfRequest;
    }

};


int main()
{
    RecentCounter *obj = new RecentCounter();

    cout<<obj->ping(1)<<endl;
    cout<<obj->ping(100)<<endl;
    cout<<obj->ping(3000)<<endl;
    cout<<obj->ping(3002)<<endl;
}
