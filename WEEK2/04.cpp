#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int search_max(std::vector<std::string> candy, int N);

int main()
{
    int N, num = 0;
    std::vector<std::string> candy;
    std::vector<int> MAX;
    bool TF = false;

    std::cin >> N;

    while (num < N)
    {
        std::string str;

        std::cin >> str;
        candy.push_back(str);

        num++;
    }

    int max = 0;

    if ((max = search_max(candy, N)) == N)
    {
        std::cout << max;

        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (candy[i][j - 1] != candy[i][j])
            {
                std::vector<std::string> candy_ = candy;

                char temp = candy_[i][j - 1];
                candy_[i][j - 1] = candy_[i][j];
                candy_[i][j] = temp;

                if ((max = search_max(candy_, N)) == N)
                {
                    TF = true;
                    MAX.push_back(max);
                    break;
                }
                MAX.push_back(max);
            }
            if (candy[j - 1][i] != candy[j][i])
            {
                std::vector<std::string> candy_ = candy;

                char temp = candy_[j - 1][i];
                candy_[j - 1][i] = candy_[j][i];
                candy_[j][i] = temp;

                if ((max = search_max(candy_, N)) == N)
                {
                    TF = true;
                    break;
                }
                MAX.push_back(max);
            }
            if (TF)
                break;
        }
    } 
    
    sort(MAX.begin(), MAX.end());
    std::cout << MAX[MAX.size()-1];

    return 0;
}

int search_max(std::vector<std::string> candy, int N)
{
    int max_;
    std::vector<int> max;

    for (int i = 0; i < N; i++)
    {
        max_ = 0;
        for (int j = 1; j < N; j++)
        {
            if (candy[i][j - 1] == candy[i][j])
                max_++;
            else{
                max.push_back(max_ + 1);
                max_ = 0; 
            }
                
            
            if (max_ == N - 1)
                return N;
        }
        max.push_back(max_ + 1);
        max_ = 0;
        for (int j = 1; j < N; j++)
        {
            if (candy[j - 1][i] == candy[j][i])
                max_++;
            else{
                max.push_back(max_ + 1);
                max_ = 0; 
            }
            if (max_ == N - 1)
                return N;
        }
        max.push_back(max_ + 1);
    }
    sort(max.begin(), max.end());
    return max[max.size() - 1];
}