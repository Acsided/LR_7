#include <iostream>

bool IsEven(char a){
  return (a == '0' || a == '2' || a == '4' || a == '6' || a == '8');
}

bool IsNumb(char a){
  return !(a < 48 || a > 58);
}

std::pair<int*, int> BinRepr(char* arr, int n){
  int* bin = new int[10000000];
  int bn = 1;
  bool flag = true;

  if(arr[0] == '-') bin[0] = 1; else bin[0] = 0;
  int buff = 0;
  while(flag){
    if(IsEven(arr[n - 1])) bin[bn] = 0; else bin[bn] = 1;
    bn++;
    buff = 0;
    flag = false;
    for(int i = bin[0] == 0 ? 0 : 1; i < n; i++){
      int numb = (int)arr[i] - 48;
      arr[i] = char(((numb + buff) / 2) + 48);
      if((numb + buff) % 2 == 1) buff = 10; else buff = 0;
      if(arr[i] != '0') flag = true;
    }
  }

  for(int i = 1; i < (bn - 1) / 2 + 1; i++){
    int buf = bin[i];
    bin[i] = bin[bn - i];
    bin[bn - i] = buf;
  }

  return {bin, bn};
}

std::pair<char*, int> InputLargeNum(){
  char* arr = new char[10000000];
  int n = 1;
  std::cin >> arr[0];

  if(!IsNumb(arr[0]) && arr[0] != '+' && arr[0] != '-'){
    std::cout << "Incorrect input. Program crashed\n";
    delete[] arr;
    exit(-1);
  }

  while(std::cin.peek() != '\n'){
    char lettar = std::cin.peek();
    if(lettar < 48 || lettar > 58){
      std::cout << "Incorrect input. Program crashed\n";
      delete[] arr;
      exit(-1);
    }
    arr[n] = std::cin.get();
    n++;
  }
  arr[n] = '\0';
  return {arr, n};
}

int ToDopCodeConvert(int* arr, int n){
  for(int i = 1; i < n; i++) if(arr[i] == 1) arr[i] = 0; else arr[i] = 1;
  int ind = n;
  while(arr[ind] == 1 && ind > 0){
      arr[ind] = 0;
      ind--;
  };
  arr[ind] = 1;
  return n;
}

int MakeEqual(int* arr1, int* arr2, int n1, int n2){
  int* arr = n1 > n2 ? arr2 : arr1;
  int n = std::max(n1, n2);
  int m = std::min(n1, n2);
  if(n != m){
    for(int i = m - 1; i >= 1; i--) arr[i + (n - m)] = arr[i];
    for(int i = 1; i < n - m + 1; i++) arr[i] = 0;
  }
  return n;
}

int* MakeSum(int* arr1, int* arr2, int n){
  int* arr = new int[1000000];
  int buf = 0;
  for(int i = n - 1; i > -1; i--){
    arr[i] = (buf + arr1[i] + arr2[i]) % 2;
    if(buf + arr1[i] + arr2[i] > 1) buf = 1; else buf = 0;
  }
  if(arr[0] == 1 && (arr1[0] == 1 || arr2[0] == 1)){
    for(int i = 1; i < n; i++) if(arr[i] == 1) arr[i] = 0; else arr[i] = 1;
    if(buf != 0){
      int ind = n - 1;
      while(arr[ind] == 1 && ind > 0) ind--;
      arr[ind] = 1;
    }

    int ind = n;
    while(arr[ind] == 1 && ind > 0){
      arr[ind] = 0;
      ind--;
    };
    arr[ind] = 1;
  }

  return arr;
}