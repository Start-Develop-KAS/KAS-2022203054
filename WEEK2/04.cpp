#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int search_max(const std::vector<std::vector<std::string>> *candy, int N);

int main()
{
    int N, num = 0;
    std::vector<std::vector<std::string>> candy;

    std::cin >> N;

    while (num < N)
    {
        std::string str;
        std::vector<std::string> vec;

        std::cin >> str;
        vec.push_back(str);
        candy.push_back(vec);

        num++;
    }

    int max = 0;

    

        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j < N; j++)
            {
                // 행에서 swap
                if (candy[i][0][j - 1] != candy[i][1][j])
                {
                    std::vector<std::vector<std::string>> candy_ = candy;
                    
                    char temp = candy_[i][0][j - 1];
                    candy_[i][0][j - 1] = candy_[i][0][j];
                    candy_[i][0][j] = temp;

                    if((max = search_max(&candy_, N))==N)
                        break;
                }
                if(candy[j-1][0][i] != candy[j][1][i])
                {
                    std::vector<std::vector<std::string>> candy_ = candy;
                    
                    char temp = candy_[i][0][j - 1];
                    candy_[i][0][j - 1] = candy_[i][0][j];
                    candy_[i][0][j] = temp;

                    if((max = search_max(&candy_, N))==N)
                        break;
                }
            }
        }
        std::cout<<max;

        return 0;
    
}

int search_max(const std::vector<std::vector<std::string>> *candy, int N){
    int max_;
    std::vector<int> max;
    for(int i=0;i<N;i++){
        for(int j=1;j<N;j++){
            max_=0;
            if(candy[i][0][j-1]==candy[i][0][j])
                max_++;
            max.push_back(max_);
            max_=0;
            if(candy[j-1][0][i]==candy[j][0][i])
                max_++;
            max.push_back(max_);
        }
    }
    sort(max.begin(),max.end());
    return max[max.size()-1];
}