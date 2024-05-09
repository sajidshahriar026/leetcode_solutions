#include<bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2);

int main()
{
    string str1 = "LEET";
    string str2 = "CODE";

    string result = gcdOfStrings(str1, str2);
    cout<<result;

    return 0;
}


string gcdOfStrings(string str1, string str2)
{
    int l1 = str1.length();
    int l2 = str2.length();

    string subString = (l1 <= l2) ? str1 : str2;

    int length = subString.length();

    while(length > 0)
    {
        if(!(l1 % length) && !(l2 % length))
        {
            int d1 = l1 / length;
            int d2 = l2 / length;

            string conString1, conString2;

            for(int i= 0;i<d1;i++)
            {
                conString1 += subString;
            }

            for(int i=0;i<d2;i++)
            {
                conString2 += subString;
            }

            if(str1 == conString1 && str2 == conString2)
            {
                return subString;
            }
            else
            {
                length--;
                subString = subString.substr(0,length);
            }

        }
        else
        {
            length--;
            subString = subString.substr(0,length);
        }

    }
    return "";
}
