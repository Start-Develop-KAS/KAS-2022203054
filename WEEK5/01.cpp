#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    string A_s, B_s;
    deque<char> A, B;
    int rst = 0, sub = 0, same = -1;
    bool sameiszero = false;

    cin >> A_s >> B_s;

    for (int i = 0; i < A_s.size(); i++)
    {
        A.push_back(A_s[i]);
    }
    for (int i = 0; i < B_s.size(); i++)
    {
        B.push_back(B_s[i]);
    }

    if (A.size() == B.size())
    {
        while (A.size() > 0)
        {
            if (A.front() != B.front())
                rst++;
            A.pop_front();
            B.pop_front();
        }
    }

    else
    {
        int i = 0;
        int samei = 0;
        sub = B.size() - A.size();

        for (i = 0; i <= sub; i++)
        {
            int num = 0;

            for (int j = 0; j < A.size(); j++)
            {
                if (A[j] == B[i + j])
                    num++;
            }
            if (num > same)
            {
                same = num;
                samei = i;
            }
        }

        for (int j = samei - 1; j >= 0; j--)
        {
            A.push_front(B[j]);
        }
        if (sub - samei > 0)
            for (int j = A.size(); j < B.size(); j++)
                A.push_back(B[j]);
                
        while (A.size() > 0)
        {
            if (A.front() != B.front())
                rst++;
            A.pop_front();
            B.pop_front();
        }
    }

    cout << rst;

    return 0;
}