

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, const char * argv[]) {
    
    cout<< "Hello, welcome to Maged's Carpet Cleaning Service" << endl;
    
    cout << "\nHow many small rooms would you like cleaned? ";
    int smallRooms {0};
    cin >> smallRooms;
    
    cout << "How many large rooms would you like cleaned? ";
    int largeRooms {0};
    cin >> largeRooms;
    
    cout << "\nEstimate for carpet cleaning service";
    cout << "\nNumber of small rooms: " << smallRooms;
    cout << "\nNumber of large rooms: " << largeRooms;
    
    const double smallCost {25};
    cout << "\nPrice per small room: $" <<smallCost;
    
    const double largeCost {35};
    double roomsCost = (smallCost * smallRooms) + (largeCost * largeRooms);
    double tax = roomsCost * 0.06;
    
    cout << "\nCost: $" << roomsCost;
    cout << "\nTax: $" << tax;
    
    cout << "\n===============================================";
    cout << "\nTotal cost: " << roomsCost + tax;
    const int days = 30;
    cout << "\nThis cost is valid for " << days << " days" << endl;
    
    return 0;
}
