#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::vector;

int main () {
    
    vector<int> vector1, vector2;
    
    vector1.push_back(10);
    vector1.push_back(20);
    
    cout << "Vector1: " << vector1.at(0) << " " << vector1.at(1) << ", Size: " << vector1.size() << endl;
    
    vector2.push_back(100);
    vector2.push_back(200);
    
    cout << "Vector2: " << vector2.at(0) << " " << vector2.at(1) << ", Size: " << vector2.size() << endl;
    
    vector<vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    cout << vector_2d.at(0).at(0) << endl;
    
    vector1.at(0) = 1000;
    
    cout << vector_2d.at(0).at(0) << endl;
    
}
