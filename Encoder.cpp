#include "Encoder.h"
#include <iostream>
using namespace std;

Encoder::Encoder(){};

string Encoder::encodeVariable(string varName, int value){
        return  Encoder::generateHash("int"+varName+std::to_string(value));
}

string Encoder::encodeVariable(string varName, double value){
        return  Encoder::generateHash("double"+varName+std::to_string(value));
}

string Encoder::encodeVariable(string varName, float value){
        return  Encoder::generateHash("float"+varName+std::to_string(value));
}

string Encoder::encodeVariable(string varName, char* value){
        return  Encoder::generateHash("char*"+varName+value);
}

string Encoder::encodeVariable(string varName, long value){
        return  Encoder::generateHash("long"+varName+std::to_string(value));
}

char Encoder::getKey() {
        return Encoder::key;
}

string  Encoder::generateHash(string varName) {
        int len = varName.length();
        for(int i = 0; i < len; i++){
                varName[i] = varName[i] ^ Encoder::getKey(); 
        }
        return varName;
}
