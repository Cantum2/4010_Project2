#include "Encoder.h"
#include <iostream>
using namespace std;

Encoder::Encoder(){};

string Encoder::encodeVariable(string varName, int value){
        return  Encoder::generateHash("int_"+varName+'_'+std::to_string(value));
}

string Encoder::encodeVariable(string varName, double value){
        return  Encoder::generateHash("double_"+varName+'_'+std::to_string(value));
}

string Encoder::encodeVariable(string varName, float value){
        return  Encoder::generateHash("float_"+varName+'_'+std::to_string(value));
}

string Encoder::encodeVariable(string varName, char* value){
        return  Encoder::generateHash("char*_"+varName+'_'+value);
}

string Encoder::encodeVariable(string varName, long value){
        return  Encoder::generateHash("long_"+varName+'_'+std::to_string(value));
}

char Encoder::getKey() {
        return Encoder::key;
}

char Encoder::getSeparator() {
        return Encoder::separator;
}


string Encoder::generateHash(string varName) {
        int len = varName.length();
        for(int i = 0; i < len; i++){
                varName[i] = varName[i] ^ Encoder::getKey(); 
        }
        return varName;
}
