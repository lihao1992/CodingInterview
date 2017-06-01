/*数组中最小的K个数（最大的k个数）*/
// 寻找数组中最小的k个数，那么我们能想到的第一个方法是，基于快排的方法
// 第二种方法就是先创建一个大小为k的容器，从n个数中往里读数，如果容器中的数字个数小于k，那么直接将数字读入；
// 如果容器中已经有k个数了，那么就要比较了，比较新来的数和容器中已有的k个数中最大的那个数的大小，容器中最大的数
// 小于新来的，那么容器不变，抛弃掉新来的数；如果容器中最大的数 大于 新来的数，那么就要删除容器中的这个数，
// 将新来的数插入到容器中。
// 利用STL中的set/multiset来实现容器（最大堆）
#include<iostream>
#include<vector>
#include<set>

using namespace std;

// 这里typedef的用途就是将复杂的声明 简化，如将生命一个multiset型的容器，直接改成声明一个intSet 型的容器
// 当有大量使用时，这种方式比较省事
typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIt;


// 为什么加const
void minK(const vector<int>& data, intSet& result, int k){

    result.clear();

    // 检查边界条件
    if(k<1 || data.size() < k)
        return ;
    
    // 为什么定义了一个const_iterator ?
    vector<int>::const_iterator iter = data.begin();

    for(; iter != data.end(); ++iter){

        // 如果容器内还不满k个数字，那么新来的数字直接加入进容器内
        if(result.size() < k)
            result.insert(*iter);
        
        else{

            setIt iterGreatest = result.begin();

            if(*iter < *(result.begin())){

                result.erase(iterGreatest);
                result.insert(*iter);
            }
        }
    }
}

int main(){

    vector<int> data = {4,5,1,6,2,7,3,8};
    multiset<int, greater<int>> result;
    int k = 6;

    minK(data, result, k);

    //multiset<int, greater<int>>::iterator it = result.begin();
    //intSet::iterator it = result.begin();
    setIt it = result.begin();
    for(; it != result.end(); ++it)
        cout << *it << endl; 

    return 0;
}