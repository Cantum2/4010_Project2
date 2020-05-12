#include <iostream>
#include <fstream>
#include "vector"
#include <string>
#include <sstream>
#include "Encoder.h"

using namespace std;

const string FILE_NAME = "output.csv";
Encoder *encoder = new Encoder();

void writeDiagHashToCSV(string fileName, vector<string> varHashes);
void writeJunk(string fileName,int lastUsedColumn);
string getColName(string varName, string value);
string readRow(string const &fileName);
char randCharacter();
void addRowHashes(string const &fileName);

int main() {    
    cout<<"Hello"<<endl;
    string res = encoder->encodeVariable("guy", 5);
    cout<<"guy5 encodes to "<<res<<endl;
    cout<<res<< " decodes to "<<encoder->generateHash(res)<<endl;
    writeDiagHashToCSV("dataDiag.csv", {"johnnyappleseed", "guy", "0x401123", "girl", "1234", "3.14", "abc"});
    cout << "Row hashes to: " << encoder->generateHash(readRow("dataDiag.csv"));
    //addRowHashes("dataDiag.csv");
    return 0;
}

/**
  based on the var name it will return the column of which to begin diagnol
  @param varname variable name to get diagonal start location
  @returns the column number that the diagonal will start based on var name
 */
int getColName(string varName) {
  return 0;
}

string readRow(string const &fileName) {
  ifstream file(fileName);
  string row = "", line = "", cell = "";
  getline(file, line);
  stringstream stream(line);
  
  while(getline(stream, cell, ',')) row += cell;
  for (int i = 0; i < row.length(); i++) row.erase(row.find(' '), 1);
  file.close();
  return row;
}

// Function to write hash at end of file
// 1. Take the hash of each row
// 2. We put it in the next column (where cell is empty)
// 3. Keep going until no more lines
void addRowHashes(string const &fileName) {
   ofstream write;
   ifstream read(fileName);
   
   string hash = encoder->generateHash(readRow(fileName));
   string line, cell;

   getline(read, line);
   //stringstream stream(line);
   //while(getline(stream, cell, ',')) {
   //    write << cell << ',';
   //}
   //write << hash << ",";

   write.open(fileName, ios::out | ios::trunc);
   write << line << "," << hash << ",\n";

   read.close();
   write.close();
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
  fout.close();
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