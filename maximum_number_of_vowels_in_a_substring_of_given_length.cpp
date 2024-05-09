#include<bits/stdc++.h>
using namespace std;

int maxVowels(string s, int k);


int main()
{
    string s = "aeiou";
    int k = 2;

    cout<<maxVowels(s, k)<<endl;

    return 0;
}


int maxVowels(string s, int k)
{
    int length = s.length();

    int cnt = 0;
    int maxCount;

    for(int i = 0;i<k;i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            cnt++;
        }
    }
    maxCount = cnt;

    int left = 0;
    int right = k;

    while(right<length)
    {
        if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u')
        {
            cnt--;
        }
        if(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u')
        {
            cnt++;
        }

        if(maxCount < cnt)
        {
            maxCount = cnt;
        }

        left++;
        right++;
    }

    return maxCount;
}
