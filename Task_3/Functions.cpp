#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string Minus(const std::string &num1, const std::string &num2, const int base) {
    std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    bool isNegativeResult = false;
    std::string n1 = num1;
    std::string n2 = num2;

    int maxLen = std::max(n1.size(), n2.size());
    n1 = std::string(maxLen - n1.size(), '0') + n1;
    n2 = std::string(maxLen - n2.size(), '0') + n2;

    if (n1 < n2) {
        std::swap(n1, n2);
        isNegativeResult = true;
    }

    std::string result;
    int borrow = 0;

    for (int i = maxLen - 1; i >= 0; --i) {
        int digit1 = std::find(digits.begin(), digits.end(), n1[i]) - digits.begin();
        int digit2 = std::find(digits.begin(), digits.end(), n2[i]) - digits.begin();
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += digits[diff];
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());

    if (isNegativeResult) {
        result.insert(result.begin(), '-');
    }

    return result;
}

std::string Plus(const std::string &num1, const std::string &num2, const int base) {
    std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    bool isNegativeResult = false;
    std::string n1 = num1;
    std::string n2 = num2;

    int maxLen = std::max(n1.size(), n2.size());
    n1 = std::string(maxLen - n1.size(), '0') + n1;
    n2 = std::string(maxLen - n2.size(), '0') + n2;

    std::string result;
    int carry = 0;

    for (int i = maxLen - 1; i >= 0; --i) {
        int digit1 = std::find(digits.begin(), digits.end(), n1[i]) - digits.begin();
        int digit2 = std::find(digits.begin(), digits.end(), n2[i]) - digits.begin();
        int sum = digit1 + digit2 + carry;
        carry = sum / base;
        sum %= base;
        result += digits[sum];
    }

    if (carry > 0) {
        result += digits[carry];
    }

    std::reverse(result.begin(), result.end());

    if (isNegativeResult) {
        result.insert(result.begin(), '-');
    }

    return result;
}

bool CheckNum(std::string& str, int base){
  int ind = 0;
  if(str[ind] == '+' || str[ind] == '-') ind++;
  while(ind < str.length()){
    if(!isdigit(str[ind]) && (str[ind] < 'A' || str[ind] > 'Z' - (26 - base + 10))) return false;
    ind++;
  }
  return true;
}