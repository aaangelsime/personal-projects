#include <iostream>

using namespace std; 

//Function : f = (W*X)' * (Y'+ Z')'
void expression(char x, char y, char w, char z, char f, char wANDx, char orr, char yANDz){
    char x;
    char y;
    char z;
    char w;
    char f;
    char wANDx;
    char orr;
    char yORz;

    cout << "Enter First collumn of the 4 gates with spaces in between." << endl;
    cout << "Example: x y z w" << endl;

    cin >> x >> y >> z >> w ;



    if (w == '0' && y == '0'){
        wANDx = 0;
    } 
    else if (w == '1' && y == '0') {
        wANDx = 0;
    }
    else if (w == '0' && y == '1') {
        wANDx = 0;
    }
    else {
        wANDx = 1;
    }
    //
    if (wANDx == '0'){
        wANDx = 1;
    } 
    else (wANDx = '1') {
        wANDx = 0;
    }
    //
    if (y == '0'){
        y = 1;
    }
    else (y == '1'){
        y = 0;
    }
    //
    if (z == '0'){
        z = 1;
    }
    else (z == '1'){
        z = 0;
    }
    //
    if (y == '0' && z == '0'){
        yORz = 0;
    }
    else if (y == '1' && z == '0'){
        yORz = 1;
    }
    else if (y == '0' && z == '1'){
        yORz = 1;
    }
    else (y == '1' && z == '1'){
        yORz = 1;
    }
    //
    if (yORz == '1'){
        yORz = 0;
    }
    else (yORz == '0'){
        yORz = 1;
    }
    //
    if (wANDx == '0' && yORz == '0'){
        f = 0;
    }
    else if (wANDx == '1' && yORz == '0'){
        f = 0;
    }
    else if (wANDx == '0' && yORz == '1'){
        f = 0;
    }
    else if (wANDx == '0' && yORz == '0'){
        f = 1;
    }




}

int main(){
    expression; 
    return 0; 
}