#include<bits/stdc++.h>
using namespace std;

string decodeString(string s);


int main()
{
    string s = "2[abc]3[cd]ef";
    cout<<decodeString(s)<<endl;

    return 0;
}


string decodeString(string s)
{
    stack<char> sc;


    int length = s.length();

    int i = 0;

    while(i<length)
    {
        if(s[i] != ']')
        {
            sc.push(s[i]);
            i++;
        }
        else
        {
            string word;
            while(!sc.empty() && sc.top() != '[')
            {
                char c = sc.top();
                sc.pop();
                word += c;
            }
            sc.pop();

            reverse(word.begin(),word.end());

//            cout<<"Word: "<<word<<' ';

            string n;
            while(!sc.empty() && (sc.top() >= '0' && sc.top() <= '9'))
            {
               char c = sc.top();
               sc.pop();
               n += c;
            }

            reverse(n.begin(),n.end());

            stringstream ss;

            ss << n;
            int number = 0;
            ss >> number;

//            cout<<"Number: "<<number<<' '<<endl;

            string finalWord;
            for(int j=0;j<number;j++)
            {
                finalWord += word;
            }

            for(auto j = finalWord.begin();j!=finalWord.end();j++)
            {
                sc.push(*j);
            }

            i++;
        }
    }

    string decodedString;

    while(!sc.empty())
    {
        decodedString += sc.top();
        sc.pop();
    }

    reverse(decodedString.begin(), decodedString.end());

    return decodedString;
}
