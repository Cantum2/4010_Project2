#include <iostream>
#include "Encoder.h"

using namespace std;

int main(){
    Encoder *encoder = new Encoder(); 

    cout<<"Hello"<<endl;
    cout<<"Hello"<<encoder->encodeDiagonal("guy", 5)<<endl;
    return 0;   
}