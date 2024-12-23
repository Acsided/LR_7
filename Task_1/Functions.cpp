#pragma once 
#include <iostream>

void OutArr(char* arr){
  int ind = 0;
  std::cout << std::endl;
  while(arr[ind] != '\0'){
    std::cout << arr[ind];
    ind++;
  }
  std::cout << std::endl;
}