#include<string>
using namespace std;

class Encoder {
    public:
        Encoder();
        string encodeVariable(string varName, int value);
        string encodeVariable(string varName, double value);
        string encodeVariable(string varName, float value);
        string encodeVariable(string varName, char* value);
        string encodeVariable(string varName, long value);
        string generateHash(string varName);
        char getKey();
        char getSeparator();
    private:
        char key = '1';
        char separator = '_';
};