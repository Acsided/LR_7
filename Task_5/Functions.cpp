 #include <iostream> 
#include <cmath> 
#include <string> 

 std::string toTrenary(int number, int digits) { // O(digits) 
    std::string ternary = ""; 
    for (int i = 0; i < digits; i++) { 
        ternary = std::to_string(number % 3) + ternary;
        number /= 3; 
    } 
    return ternary; 
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

std::string* CreateBarrelCodes(int numBarrels, int numSlaves){
    std::string* barrelCodes = new std::string[numBarrels]; 
    for (int i = 0; i < numBarrels; i++) { // O(numBarrels * numSlaves) 
        barrelCodes[i] = toTrenary(i, numSlaves); // O(numSlaves) 
    } 
    return barrelCodes;
}