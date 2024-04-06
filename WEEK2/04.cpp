#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int search_max(const std::vector<std::string> *candy, int N);

int main()
{
    int N, num = 0;
    std::vector<std::string> candy;

    std::cin >> N;

    while (num < N)
    {
        std::string str;

        std::cin >> str;
        candy.push_back(str);

        num++;
    }

    int max = 0;

    

        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j < N; j++)
            {
                // 행에서 swap
                if (candy[i][j - 1] != candy[i][j])
                {
                    std::vector<std::string> candy_ = candy;
                    
                    char temp = candy_[i][j - 1];
                    candy_[i][j - 1] = candy_[i][j];
                    candy_[i][j] = temp;

                    if((max = search_max(&candy_, N))==N)
                        break;
                }
                if(candy[j-1][i] != candy[j][i])
                {
                    std::vector<std::string> candy_ = candy;
                    
                    char temp = candy_[i][j - 1];
                    candy_[i][j - 1] = candy_[i][j];
                    candy_[i][j] = temp;

                    if((max = search_max(&candy_, N))==N)
                        break;
                }
            }
        }
        std::cout<<max;

        return 0;
    
}

int search_max(const std::vector<std::string> *candy, int N){
    int max_;
    std::vector<int> max;
    for(int i=0;i<N;i++){
        for(int j=1;j<N;j++){
            max_=0;
            if(&candy[i][j-1]==&candy[i][j])
                max_++;
            max.push_back(max_);
            max_=0;
            if(&candy[j-1][i]==&candy[j][i])
                max_++;
            max.push_back(max_);
        }
    }
    sort(max.begin(),max.end());
    return max[max.size()-1];
}