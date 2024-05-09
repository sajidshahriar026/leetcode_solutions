#include<bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n);

int main()
{

}

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
    int length = flowerbed.size();

    int placedFlowers = 0;

    if (length == 1)
    {
        if ((flowerbed[0] == 0))
        {
            placedFlowers++;
        }
    }
    else
    {
        for(int i = 0; i<length; i++)
        {
            if (i == 0)
            {
                if(flowerbed[i+1]==0 && flowerbed[i] == 0)
                {
                    flowerbed[i] = 1;
                    placedFlowers++;
                }

            }
            else if(i == length-1)
            {
                if(flowerbed[i-1] == 0 && flowerbed[i] == 0)
                {
                    flowerbed[i] = 1;
                    placedFlowers++;
                }
            }
            else
            {
                if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] == 0)
                {
                    flowerbed[i] = 1;
                    placedFlowers++;
                }
            }
        }


    }

    if(n <= placedFlowers)
    {
        return true;
    }
    else
    {
        return false;
    }


}
