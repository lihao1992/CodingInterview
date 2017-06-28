/*判断字符串是否是回文串*/

#include <iostream>
#include <string>

using namespace std;


// Solution 1. 设首尾双指针，双向向中间遍历，比较，判断两边元素是否相等（回文）
bool isPalindrome(string str, int n){

    if(str.size() == 0)
        return false;
    
    int start = 0;
    int end = n-1;

    while(start < end){

        if(str[start] != str[end]){
            cout << "is not Palindrome." << endl;
            return false;
        }
        
        ++start;
        --end;
    }
    cout << "Yes" << endl;
    return true;
}



// Solution2. 从中间开始，向两边遍历，查看字符是否相等。
bool isPalindrome_2(string str){

    int n = str.size();
    if(n == 0)
        return false;
    
    int mid =( (n >> 1)-1 ) >= 0? (n >> 1)-1 : 0;

    int left = mid;
    int right = n-1-mid;

    while(left >= 0){

        if(str[left] != str[right]){
            cout << "is not Palindrome." << endl;
            return false;
        }

        --left;
        ++right;
    }

    cout << "Yes" << endl;
    return true;
}


int main(){

    string s1 = "aba";
    string s2 = "abba";
    string s3 = "abc";

    isPalindrome(s1, 3);
    isPalindrome(s2, 4);
    isPalindrome(s3, 3);

    isPalindrome_2(s1);
    isPalindrome_2(s2);
    isPalindrome_2(s3);

    return 0;
}

// 判断一条单向链表是不是“回文”
// 分析：对于单链表结构，可以用两个指针从两端或者中间遍历并判断对应字符是否相等。
// 但这里的关键就是如何朝两个方向遍历。由于单链表是单向的，所以要向两个方向遍历的话，
// 可以采取经典的快慢指针的方法，即先位到链表的中间位置，再将链表的后半逆置，
// 最后用两个指针同时从链表头部和中间开始同时遍历并比较即可。