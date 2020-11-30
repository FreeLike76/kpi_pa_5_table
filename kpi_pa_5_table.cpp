#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


#define diceEdge 6
#define diceNum 5

using namespace std;

int eval(vector<int> sequence);

int main()
{
    vector<int> table(7, 0);
    for (int it1 = 1; it1 <= diceEdge; it1++)
    {
        for (int it2 = 1; it2 <= diceEdge; it2++)
        {
            for (int it3 = 1; it3 <= diceEdge; it3++)
            {
                for (int it4 = 1; it4 <= diceEdge; it4++)
                {
                    for (int it5 = 1; it5 <= diceEdge; it5++)
                    {
                        vector<int> thisSequence({ it1,it2,it3,it4,it5 });
                        table[eval(thisSequence)] += 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < table.size(); i++)
    {
        cout << i << " : " << table[i] << endl;
    }
}

int eval(vector<int> sequence) {
    set<int> uniqueSet(sequence.begin(), sequence.end());
    switch (uniqueSet.size())
    {
    case 1: 
    {
        return 6;
    }
    case 2: 
    {
        vector<int> present(uniqueSet.begin(), uniqueSet.end());
        vector <int> count(2, 0);
        for (int i = 0; i < present.size(); i++)
        {
            for (int j = 0; j < sequence.size(); j++)
            {
                if (present[i] == sequence[j]) 
                {
                    count[i]++;
                }
            }
        }
        if (count[0] == 4 || count[1] == 4) 
        {
            return 5;
        }
        else 
        {
            return 4;
        }
    }
    case 3: 
    {
        vector<int> present(uniqueSet.begin(), uniqueSet.end());
        vector <int> count(3, 0);
        for (int i = 0; i < present.size(); i++)
        {
            for (int j = 0; j < sequence.size(); j++)
            {
                if (present[i] == sequence[j]) 
                {
                    count[i]++;
                }
            }
        }
        if (count[0] == 2 || count[1] == 2 || count[2] == 2) 
        {
            return 2;
        }
        else 
        {
            return 3;
        }
    }
    case 4:
    {
        return 1;
    }
    default:
        break;
    }
    return 0;
}