#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> BinaryInsert(vector<int> v, int leftMost, int rightMost, int x)
{
    if (rightMost >= leftMost)
    {
        //cout << leftMost << " " << rightMost << endl;
        int mid = ((rightMost) + leftMost) / 2;
        vector<int>::iterator it = v.begin() + mid + 1;
        if (v[mid] == x)
        {
            v.insert(it, x);
            return v;
        }
        if (v[0] >= x)
        {
            v.insert(v.begin(), x);
            return v;
        }
        else if (v[v.size() - 1] <= x)
        {
            // cout << rightMost << " " << x << endl;
            v.push_back(x);
            return v;
        }
        if (x < v[mid])
        {
            //cout << v[leftMost] << " " << v[rightMost] << " " << mid << endl;
            if (rightMost == leftMost)
            {
                v.insert(it - 1, x);
                return v;
            }
            return BinaryInsert(v, leftMost, mid - 1, x);
        }
        else if (x > v[mid])
        {
            //cout << v[leftMost] << " " << v[rightMost] << " " << mid << endl;
            if (rightMost == leftMost)
            {
                v.insert(it, x);
                return v;
            }
            return BinaryInsert(v, mid + 1, rightMost, x);
        }
    }
}

int main()
{
    vector<int> test;
    test.push_back(75);
    test.push_back(5);
    test.push_back(67);
    test.push_back(102);
    test.push_back(43);
    test.push_back(15);
    test.push_back(53);
    cout << "Please enter a number you want to enter into the vector" << endl;
    int x;
    cin >> x;
    sort(test.begin(), test.end());
    test = BinaryInsert(test, 0, test.size() - 1, x);
    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }
    cout << endl;
}