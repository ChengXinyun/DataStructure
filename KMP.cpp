// 字符串模式匹配算法
#include <iostream>

using namespace std;

// 暴力匹配算法
int index(string s1, string s2){
    int i, j = 0, k;
    int l1 = s1.length(), l2 = s2.length();
    while(j < l2){
        k = j;
        while(i < l1){
            if(s1[i] == s2[k]){
                i++;
                k++;
            } else {
                break;
            }
        }
        if(i == l1){
            return j;
        }
        j++;
        i = 0;
    }
    return -1;
}

int index_1(string s1, string s2){
    int i = 1, j = 1;
    while(i <= s1.length() && j <= s2.length()){
        if(s1[i] == s2[j]){
            i++;
            j++;
        } else {
            j = j - i + 2;
            i = 1;
        }
    }
    if(i > s1.length()){// 子串s1全部比较完了，也就是找到了。
        return j - s1.length();
    } else {
        return 0;
    }
}

// KMP算法
// 求 next 数组
void get_next(string s, int next[]){
    int i = 1, j = 0;
    next[1] = 0;
    while(i < s.length()){
        if(j == 0 || s[i] == s[j]){
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}
int index_KMP(string s, string t, int next[]){
    int i = 1, j = 1;
    while(i <= s.length() && j <= t.length()){
        if(j == 0 || s[i] == s[j]){
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if(j > t.length()){
        return j - t.length();
    } else {
        return 0;
    }
}


int main(){
    string s1 = "bc";
    string s2 = "abcde";
    cout << index(s1, s2) << endl;
    int next[100];
    get_next(s1, next);
    cout << index_KMP(s2, s1, next) << endl;
    return 0;
}