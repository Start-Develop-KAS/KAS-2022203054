#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> ice;

bool DFS(int M, int N, vector<vector<bool>> &TF)
{
    if (M < 0 || M > ice.size())
        return false;
    vector<int> vec;
    vec = ice[M];

    if (N < 0 || N >= vec.size())
        return false;

    if (vec[N] == 0 && TF[M][N] == false)
    {
        TF[M][N] = true;
        DFS(M + 1, N, TF);
        DFS(M - 1, N, TF);
        DFS(M, N + 1, TF);
        DFS(M, N - 1, TF);
        
        return true;
    }

    return false;
}

int main()
{
    int N, M;
    string num;
    int cnt = 1;
    int icecream = 0;
    int rst = 0;

    queue<int> que;

    cin >> N >> M;

    vector<vector<bool>> TF(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        vector<int> vec;

        cin >> num;
        for (int j = 0; j < M; j++)
        {
            int numi=int(num[j])-'0';
            vec.push_back(numi);
        }

        ice.push_back(vec);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (DFS(i, j, TF))
                rst += 1;
        }
    }

    cout << rst;

    return 0;
}