#include<bits/stdc++.h>
using namespace std;

vector<int>asteroidCollision(vector<int>asteroids);
bool noConflictSituation(int a, int b);



int main()
{
    vector<int>asteroids = {10,2,-5};

    vector<int>remainingAsteroids = asteroidCollision(asteroids);

    for(auto i = remainingAsteroids.begin();i!=remainingAsteroids.end();i++)
    {
        cout<<*i<<' ';
    }
    cout<<endl;

    return 0;
}


vector<int>asteroidCollision(vector<int>asteroids)
{
    stack<int>remainingAsteroids;

    int length = asteroids.size();

    int i = 0;

    while(i<length)
    {
        if (remainingAsteroids.empty())
        {
            remainingAsteroids.push(asteroids[i]);
            i++;
        }
        else
        {
            if(noConflictSituation(remainingAsteroids.top(), asteroids[i]))
            {
                remainingAsteroids.push(asteroids[i]);
                i++;
            }
            else
            {
                int flag = 0;

                while(!remainingAsteroids.empty() && !noConflictSituation(remainingAsteroids.top(), asteroids[i]))
                {
                    int top = remainingAsteroids.top();
                    remainingAsteroids.pop();

                    if(abs(top) > abs(asteroids[i]))
                    {
                        flag = 1;
                        remainingAsteroids.push(top);
                        break;

                    }
                    else if(abs(top) == abs(asteroids[i]))
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    remainingAsteroids.push(asteroids[i]);
                }
                i++;
            }
        }
    }

    asteroids.clear();

    while(!remainingAsteroids.empty())
    {
        int top = remainingAsteroids.top();
        remainingAsteroids.pop();

        asteroids.push_back(top);
    }

    reverse(asteroids.begin(), asteroids.end());

    return asteroids;
}

bool noConflictSituation(int a, int b)
{
    return (a > 0 && b > 0) || (a < 0 && b < 0) || (a < 0 && b > 0);
}
