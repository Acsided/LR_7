#include <iostream>
#include "Functions.cpp"

int main()
{
  std::cout << "Введите двоичное представление числа, первый бит - знаковый 1 - число отрицательное, 0 - число положительное\n";
  char* arr = new char[10000000];
  int n = 1;
  std::cin >> arr[0];
  while(std::cin.peek() != '\n'){
    if(std::cin.peek() != '0' && std::cin.peek() != '1'){
      std::cout << "Incorrect input. Program crashed\n";
      delete[] arr;
      exit(-1);
    }
    arr[n] = arr[0] == '0' ? std::cin.get() : (std::cin.get() == '0' ? '1' : '0');
    n++;
  }
  arr[n] = '\0';
  OutArr(arr);
  delete[] arr;
  return 0;
}