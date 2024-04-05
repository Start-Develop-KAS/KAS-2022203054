#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

#define Ascii 48

bool cal(std::string, std::vector<int>);

std::vector<std::vector<int>> rst;

int main(){
    std::ios::sync_with_stdio(false);

    int T;
    int num=0;
    
    std::vector<bool> TF;

    std::cin>>T;

    while(num<T){
        std::string p, arr;
        int n,a=0;
        std::vector<int> vec;
        std::stack<int> stk;

        std::cin>>p;
        std::cin>>n;
        std::cin>>arr;

        for(int i=1;i<arr.size();i++){
            if(arr[i]==']')
                break;
            while(arr[i]!=','){
                stk.push(int(arr[i])-Ascii);
                i++;
            }
            for(int j=0;j<stk.size();j++){
                a+=(stk.top()*pow(10,j));
                stk.pop();
            }
            vec.push_back(a);
        }

        TF.push_back(cal(p, vec));

        num++;
    }

    for(int i=0;i<T;i++){
        if(TF[i]){
            std::string rt;
            rt.push_back('[');
            for(int j=0;j<rst[i].size();j++){
                rt.push_back(char(rst[i][j]+Ascii));
                rt.push_back(',');
            }
            rt.pop_back();
            rt.push_back(']');

            std::cout<<rt<<"\n";
        }
        else
            std::cout<<"error"<<"\n";
    }
    
}

bool cal(std::string p, std::vector<int> vec){
    int a=0;

    for(int i=0;i<p.size();i++){
        switch (p[i])
        {
        case 'R':
            reverse(vec.begin(), vec.end());
            a++;
            break;
        case 'D':
            if(vec.empty())
                break;
            reverse(vec.begin(), vec.end());
            vec.pop_back();
            reverse(vec.begin(), vec.end());
            a++;
            break;
        }
    }
    rst.push_back(vec);

    if(a<p.size())
        return false;

    return true;
}