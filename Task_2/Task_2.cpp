#include <iostream>
#include "Functions.cpp"

int main()
{
  std::cout << "Введите последовательно 2 числа. После ввода каждого числа вводите Enter. Числа должны быть в десятичной системе счисления\n";
  std::pair<char*, int> input1 = InputLargeNum();
  std::pair<char*, int> input2 = InputLargeNum();


  char* arr1 = input1.first;
  int n1 = input1.second;

  char* arr2 = input2.first;
  int n2 = input2.second;


  std::pair<int*, int> repr1 = BinRepr(arr1, n1);
  std::pair<int*, int> repr2 = BinRepr(arr2, n2);

  int* bin1 = repr1.first;
  int bn1 = repr1.second;

  int* bin2 = repr2.first;
  int bn2 = repr2.second;

  int bn = MakeEqual(bin1, bin2, bn1, bn2);

  if(bin1[0] == 1) bn = ToDopCodeConvert(bin1, bn);
  if(bin2[0] == 1) bn = ToDopCodeConvert(bin2, bn);

  int* outArr = MakeSum(bin1, bin2, bn);

  for(int i = 0; i < bn; i++) std::cout << outArr[i];

  delete[] arr1;
  delete[] arr2;
  delete[] bin1;
  delete[] bin2;
  delete[] outArr;
  return 0;
}