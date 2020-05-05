#include <iostream>
#include <fstream>
#include "vector"
#include <string>
#include <sstream>
#include "Encoder.h"

using namespace std;

const string FILE_NAME = "output.csv";

void writeDiagHashToCSV(string fileName, vector<string> varHashes);
void writeJunk(string fileName,int lastUsedColumn);
string getColName(string varName, string value);
vector<string> readRow(istream& str);
char randCharacter();

int main(){
    Encoder *encoder = new Encoder();     
    cout<<"Hello"<<endl;
    string res = encoder->encodeVariable("guy", 5);
    cout<<"guy5 encodes to "<<res<<endl;
    cout<<res<< " decodes to "<<encoder->generateHash(res)<<endl;
    writeDiagHashToCSV("dataDiag.csv", {"appleseed", "guy", "0x401123", "girl", "1234", "3.14", "abc"});
    return 0;   
}

/**
  based on the var name it will return the column of which to begin diagnol
  @param varname variable name to get diagnol start location
  @returns the column number that the diagnol will start based on var name
 */
int getColName(string varName){
  return 0;
}

vector<string> readRow(istream& str){
  vector<string> row;
  string line, word, temp;  
  getline(str, line);
  stringstream stream(line);
  string cell;

  row.clear();
  while(std::getline(stream, cell, ',')){
    row.push_back(cell);
  }
  if(!stream && cell.empty()){
    row.push_back("");
  }
  return row; 
}

// Takes in updated variable data and filename, then
// updates the file using trunc constant to discard
// the old data before updating
/**
 @param filename The name of the file to create or update
 @param varHashes the vector of variable hashed data and insert diagonally
 */
void writeDiagHashToCSV(string filename, vector<string> varHashes) {
  // "maxLength" is the length of longest hashed string
  // "maxWidth" is number of columns needed for data
  // "offset" keeps track of placement in diagonal
  int maxLength = 0, maxWidth = 0, temp = 0, offset = 0;
  // file output stream that overwrites file with new data
  fstream fout;
  fout.open(filename, ios::out | ios::trunc);
  // Gets maxLength and maxWidth
  for (int v = 0; v < varHashes.size(); v++) {
    temp = varHashes.at(v).length();
    if (temp > maxLength) maxLength = temp;
    temp = v + varHashes.at(v).length();
    if (temp > maxWidth) maxWidth = temp;
  }
  // Place hashed strings into csv file in diagonal fashion
  for (int i = 0; i < maxLength; i++) {
    int j = 0;
    for (int k = 0; k < offset; k++) fout << randCharacter() << ", ";
    for (; j < varHashes.size() && j < maxWidth - offset; j++) {
      if (i < varHashes.at(j).size()) fout << varHashes.at(j).at(i) << ", ";
      else fout << randCharacter() << ", ";
    }
    for (; j < maxWidth - offset; j++) fout << randCharacter() << ", ";
    offset += 1;
    fout << "\n";
  }
}

/**
 Generates a random character (letter or number)
 @returns a char that is either a letter or a number
*/
char randCharacter() {
  int letterOrNum = rand() % 2;
  if (letterOrNum == 0) return rand() % 26 + 65;
  else return rand() % 10 + 48;
}