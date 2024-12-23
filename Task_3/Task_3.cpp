#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include "Functions.cpp"

int main() {
    int base;
    std::string num1, num2, op;

    std::cout << "Введите систему счисления, от 2 до 36: ";
    std::cin >> base;
    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите оператор(+ или -): ";
    std::cin >> op;
    std::cout << "Введите второе число: ";
    std::cin >> num2;

    if(num1[0] == '+') num1[0] = '0';
    if(num2[0] == '+') num2[0] = '0';

    if(base < 2 || base > 36){
      std::cout << "Некорректное основание системы счисления\n";
      return 0;
    }

    if(!CheckNum(num1, base)){
      std::cout << "Некорректный ввод в строке 1\n";
      return 0;
    }

    if(!CheckNum(num2, base)){
      std::cout << "Некорректный ввод в строке 2\n";
      return 0;
    }

    std::string result;

    if(op == "+"){
      if (num1[0] != '-' && num2[0] != '-') {
        result = Plus(num1, num2, base);
      };
      if (num1[0] == '-' && num1[0] != num2[0]) {
        num1[0] = '0';
        result =   Minus(num2, num1, base);
      };
      if (num2[0] == '-' && num1[0] != num2[0]) {
        num2[0] = '0';
        result =  Minus(num1, num2, base);
      };
      if (num1[0] == '-' && num2[0] == '-') {
        num1[0] = '0';
        num2[0] = '0';
        result = Plus(num1, num2, base);
        result = '-' + result;
      };
    }

    if(op == "-"){
      if(num1[0] == '-'){
        if(num2[0] != '-'){
          num1[0] = '0';
          result = Plus(num1, num2, base);
          result = '-' + result;
        } else {
          num1[0] = '0';
          num2[0] = '0';
          result = Plus(num2, num1, base);
        }
      }
      if(num1[0] != '-'){
        if(num2[0] == '-'){
          num2[0] = '0';
          result = Plus(num1, num2, base);
        } else result = Minus(num1, num2, base);
      }
    }

    if(op != "-" && op != "+"){
      std::cout << "Uncorrect oper\n";
      exit(1);
    }

    int ind = 0;
    if(result[ind] == '-') ind++;
    while(result[ind] == '0' && ind != result.length() - 1){
      result[ind] = '\0';
      ind++;
    };

    std::cout << "The result is: ";
    if(result[0] == '-') std::cout << '-';
    for(int i = ind; i < result.length(); i++) std::cout << result[i];

    return 0;
}