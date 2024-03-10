#include <iostream>
using namespace std;

void printAreaOfSquare(){

    double side;
    cout << "Enter the length of the square's side: ";
    cin >> side;

    cout << endl << "The area of the square is: " << side * side << endl;
}

int main() {
    
    printAreaOfSquare();
    return 0;
}

