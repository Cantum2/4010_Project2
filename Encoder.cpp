#include "Encoder.h"
using namespace std;

Encoder::Encoder(){};

string Encoder::encodeDiagonal(string varName, int value){
        return varName+std::to_string(value);
}
