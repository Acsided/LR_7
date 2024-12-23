#include <iostream> 
#include <cmath> 
#include <string> 
#include "Functions.cpp" 
 

int main() { 
    setlocale(LC_ALL, "Russian"); 
 
    const int numBarrels = 240; 
    const int numSlaves = 5; 
 
    int* slaveStatus = new int[numSlaves]{0};
    std::string* barrelCodes = CreateBarrelCodes(numBarrels, numSlaves); 
 
    for (int i = 0; i < numBarrels; i++) { // O(numBarrels * numSlaves) 
        barrelCodes[i] = toTrenary(i, numSlaves); // O(numSlaves) 
    } 
 
    std::cout << "Сначала выберите номер отравленной бочки (от 0 до " << numBarrels - 1 << "): "; 
 
    int poisonedBarrel = IntInput();  
 
    if (poisonedBarrel < 0 || poisonedBarrel >= numBarrels) { 
        std::cout << "Некорректный номер бочки. Завершение программы." << std::endl; 
 
        delete[] slaveStatus; 
        delete[] barrelCodes; 
 
        return 1; 
    } 
 
    std::cout << "Отравленная бочка: " << poisonedBarrel << " (код: " << barrelCodes[poisonedBarrel] << ")" << std::endl; 
 
    std::cout << "\nРабам назначены следующие действия:" << std::endl; 
    for (int slave = 0; slave < numSlaves; slave++) { // O(numSlaves * numBarrels) 
        std::cout << "Раб " << slave + 1 << " пробует бочки: "; 
        for (int barrel = 0; barrel < numBarrels; barrel++) { // O(numBarrels) 
            if (barrelCodes[barrel][slave] == '1' || barrelCodes[barrel][slave] == '2') { 
                std::cout << barrel << " "; 
            } 
        } 
        std::cout << std::endl; 
    } 
 
    std::string poisonedCode = barrelCodes[poisonedBarrel]; 
    for (int i = 0; i < numSlaves; i++) { // O(numSlaves) 
        if (poisonedCode[i] == '1') { 
            slaveStatus[i] = 1; 
        } else if (poisonedCode[i] == '2') { 
            slaveStatus[i] = 2; 
        } 
    } 
 
 
    std::cout << "\nЧерез 24 часа:\n"; 
    for (int i = 0; i < numSlaves; i++) { // O(numSlaves) 
        std::cout << "Раб " << i + 1 << ": " << (slaveStatus[i] == 1 ? "умер" : "жив") << std::endl; 
    } 
 
    std::cout << "\nЧерез 48 часов:\n"; 
    for (int i = 0; i < numSlaves; i++) { // O(numSlaves) 
        std::cout << "Раб " << i + 1 << ": " << (slaveStatus[i] == 2 ? "умер" : (slaveStatus[i] == 1 ? "умер ранее" : "жив")) << std::endl; 
    } 
 
    int foundBarrel = 0; 
    for (int i = 0; i < numSlaves; i++) { // O(numSlaves) 
        foundBarrel += slaveStatus[i] * pow(3, numSlaves - 1 - i); 
    } 
     
 
    std::cout << "\nОтравленная бочка: " << foundBarrel << "." << std::endl; 
    if (foundBarrel == poisonedBarrel) { 
        std::cout << "Бочка определена верно" << std::endl; 
    } else { 
        std::cout << "Ошибка" << std::endl; 
    } 
 
    delete[] slaveStatus; 
    delete[] barrelCodes; 
 
    return 0; 
}