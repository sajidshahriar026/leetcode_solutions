#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> &v, int target);
double squareRoot(int x);
int lowerBound(vector<int> &v, int target);
int higherBound(vector<int>&v, int target);
int findMinInARotatedArray(vector<int> &v);
int findPeak(vector<int> &v);

//Think of binary search problems as a prefix of truths and suffix of false or vice-versa - int findMinInARotatedArray(vector<int> &v), int findPeak(vector<int> &v)
//Also can be used to find target value - int binarySearch(vector<int> &v, int target), int lowerBound(vector<int> &v, int target),
//Also can be used to find real values - double squareRoot(int x)

int main()
{
    vector<int>v({1,85, 99,111, 125, 130, 155, 255});

    int index = binarySearch(v, 112);

    cout<<index<<endl;

    cout<<squareRoot(2)<<endl;

    cout<<lowerBound(v,111)<<endl;
    cout<<higherBound(v,111)<<endl;

    vector<int>v2({99,111, 125, 130, 155, 255, 1,85});

    cout<<findMinInARotatedArray(v2)<<endl;


    vector<int>v3({2,3,4,6,9,11,12,8,6,4,1});
    vector<int>v4({12,8,6,4,1});
    cout<<findPeak(v3)<<endl;
    cout<<findPeak(v4)<<endl;

    return 0;
}


int binarySearch(vector<int> &v, int target)
{
    int high = v.size() - 1;
    int low = 0;


    while(high >= low)
    {
        int mid = low + (high - low) / 2;

        if(v[mid] == target)
        {
            return mid;
        }
        else if(v[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

double squareRoot(int x)
{
    double low = 0;
    double high = (double)x;
    double epsilon = 1e-06;

    while(high-low > epsilon)
    {
        double mid = low + (high - low) /2;
//        cout<<"mid: "<<mid<<' '<<"result: "<<mid * mid<<" high: "<<high<<' '<<"low: "<<low<<endl;
        if(mid * mid < (double)x)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return low + (high-low)/2;
}


int lowerBound(vector<int> &v, int target)
{
    int low = 0;
    int high = v.size() - 1;
    int answer = -1;

    while(high >= low)
    {
        int mid = low + (high - low)/2;
//        cout<<"mid: "<<mid<<" high: "<<high<<" low: "<<low<<endl;
        if(v[mid] >= target)
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return answer;
}

int findMinInARotatedArray(vector<int>&v)
{
    int high = v.size() - 1;
    int lastElement = v[high];
    int low = 0;
    int ans = -1;

    while(high >= low)
    {
        int mid = low + (high - low) / 2;

        if(v[mid] < lastElement)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(v[mid] > lastElement)
        {
            low = mid + 1;
        }
    }
    return ans;
}

int findPeak(vector<int>&v)
{
    int high = v.size() - 1;
    int low = 0;

    int ans = -1;

    while(high >= low)
    {
        int mid = low + (high - low) / 2;

//        cout<<"mid: "<<mid<<" high: "<<high<<" low: "<<low<<" ans: "<<ans<<endl;



        if(mid == 0 || v[mid] > v[mid - 1])
        {
            ans = mid;
            low = mid + 1;
        }
        else if(v[mid] < v[mid - 1])
        {
            high = mid - 1;
        }
    }
    return ans;
}

int higherBound(vector<int> &v, int target)
{
    int high = v.size() - 1;
    int low = 0;
    int ans = -1;


    while(high >= low)
    {
        int mid = low + (high - low)/2;

        if(v[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(v[mid]<= target)
        {
            low = mid + 1;
        }
    }
    return ans;
}
