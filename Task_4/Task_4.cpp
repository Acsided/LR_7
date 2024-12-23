#include <iostream> 
 
void solve(int a, int b)// O(log a) 
{ 
    int k = a; 
    int c = (b + 1) >> 1; 
 
    while (a > b) a = (a >> 1) + ((a & 1) ? c : 0); 
 
    std::cout << "Число " << b << ((a == b || a == 0) ? " " : " не ") <<"является делителем числа " << k << std::endl; 
} 
 
int IntInput(){ 
    int x; 
    bool flag = true; 
    while (flag) { 
        flag = false; 
 
        std::cin.clear(); 
 
        std::cin >> x; 
 
        while (std::cin.peek() != '\n') { 
            if (std::cin.get() != ' ') flag = true; 
            std::cin.clear(); 
        }; 
 
        if (flag) std::cout << (char)-1 << ' ' << "Incorrect Input\n"; 
    }; 
    return x; 
} 
 
int main() 
{ 
    setlocale(LC_ALL, "Russian"); 
 
    while (true) 
    { 
        std::cout << "\nВведите 1, если хотите начать программу, введите 2, если хотите закончить программу." << std::endl; 
 
        int status = IntInput(); 
 
        if (status != 1 && status != 2) 
        { 
            std::cout << "Неверный формат ввода."; 
            continue; 
        } 
 
        if (status == 2) break; 
 
        while (true) 
        { 
            std::cout << "Введите число, которое вы хотите проверить" << std::endl; 
            int num = IntInput(); 
 
            solve(num, 7); 
            solve(num, 23); 
            solve(num, 197); 
            break; 
        } 
    } 
}