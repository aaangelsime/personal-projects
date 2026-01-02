#include <iostream>

using namespace std; 

//Function f = (w*x)' * (y'+z')'
void wAndx (char w, char x, char& wx);
void yAndz (char y, char z, char& yz);

int main() {
    
    char w = '0', x = '0', y = '0', z = '0';
    char wx = '0', yz = '0';
    char vValue = '0';

    cout << "Enter w x y z" << endl;
    cin >> w >> x >> y >> z;

    wAndx (w, x, wx);
    yAndz (y, z, yz);

    if (wx == '0' && yz == '0'){
        vValue = '0';
    }
    else if (wx == '1' && yz == '0'){
        vValue = '0';
    }
    else if (wx == '0' && yz == '1'){
        vValue = '0';
    }
    else {
        vValue = '1';
    }

    cout << "Value of w x y and z: " << vValue << endl;

    return 0; 
}

void wAndx (char w, char x, char& wx){
    //(w*x)'
    if (w == '0' && x == '0'){
        wx = '0';
    }
    else if (w == '1' && x == '0'){
        wx = '0';
    }
    else if (w == '0' && x == '1'){
        wx = '0';
    } 
    else{
        wx = '1';
    }
    //(value)'
    if (wx == '1'){
        wx = '0';
    }
    else if (wx == '0'){
        wx = '1';
    }
}

void yAndz (char y, char z, char& yz){

    // y'
    if (y == '0'){
        y = '1';
    } 
    else {
        y = '0';
    }

    // z'
    if (z == '0'){
        z = '1';
    } 
    else {
        z = '0';
    }

    // (y+z)'
    if (y == '0' && z == '0'){
        yz = '0';
    }
    else if (y == '1' && z == '0'){
        yz = '1';
    }
    else if (y == '0' && z == '1'){
        yz = '1';
    }
    else {
        yz = '1';
    }

    // (value)'
    if (yz == '1' ){
        yz = '0';
    }
    else {
        yz = '1';
    }
}