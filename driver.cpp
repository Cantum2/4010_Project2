#include <iostream>
#include <fstream>
#include "vector"
#include <string>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include "Encoder.h"

using namespace std;

const string FILE_NAME = "output.csv";
vector<char> randChars;
Encoder *encoder = new Encoder();

void writeDiagsHashToCSV(char const filename[], vector<string> varHashes);
void writeJunk(string fileName,int lastUsedColumn);
string getColName(string varName, string value);
string readRow(string const &fileName);
char randCharacter();
void addRowHashes(char const fileName[]);
void deleteOldCSV(const char fileName[]);
void autoChangeValues();
bool checkHashes();
void randCharacterVector();

int main(){    
    cout<<"Hello"<<endl;
    string res = encoder->encodeVariable("guy", 5);
    cout<<"guy5 encodes to "<<res<<endl;
    cout<<res<< " decodes to "<<encoder->generateHash(res)<<endl;
    randCharacterVector();
    writeDiagsHashToCSV("old_data.csv", {"JohnnyAppleseed", "guy", "0x401123", "girl", "1234", "3.14f", "abc", "q^w^e^r^t^y", "4.101010", "T"});
    autoChangeValues();
    return 0;
}

// Checks the hashes of changed to original
bool checkHashes(){
    ifstream readChange("change.csv");
    ifstream readData("data.csv");
    string line, cell, hash;
    vector<string> changeHashes, dataHashes;
    // Get the line
    while(getline(readChange, line)) {
      string last = "";
      // Create a stream for the line
      stringstream stream(line);
      // For every cell in the row, update last variable
      while(getline(stream, cell, ',')) last = cell;
      // Store in hash array for change csv
      changeHashes.push_back(last);
   }
   // Get the line
   while(getline(readData, line)) {
      string last = "";
      // Create a stream for the line
      stringstream stream(line);
      // For every cell in the row, update last variable
      while(getline(stream, cell, ',')) last = cell;
      // Store in hash array for data csv
      dataHashes.push_back(last);
   }
   // Check if csv's have same amount of rows
   if (changeHashes.size() != dataHashes.size()) {
     cout << "Change has been made!\n";
     return false;
   }
   // Checks if hashes are matching
   for (int i = 0; i < changeHashes.size(); i++) {
     if (changeHashes.at(i).compare(dataHashes.at(i)) != 0) {
       cout << "Changes have been made at: " << i << "\n";
       return false;
     }
   }
   return true;
}

// Automatically changes the values
void autoChangeValues(){
    writeDiagsHashToCSV("new_data.csv", {"idontknow", "girl", "0.401123", "guy", "5678", "-3.14f", "def", "q^w^e^r^t", "4.0101010", "C"});
    //writeDiagsHashToCSV("change.csv", {"JohnnyAppleseed", "guy", "0x401123", "girl", "1234", "3.14f", "abc", "q^w^e^r^t^y", "4.101010", "T"});
    if (checkHashes()) {
       cout << "They match!\n";
    } else {
       cout << "They don't match!\n";
       deleteOldCSV("new_data.csv");
       rename("old_data.csv", "new_data.csv");
    }
}

// Delete old csv
void deleteOldCSV(const char fileName[]){
  if (remove(fileName) == 0) cout << "Success removing!\n";
  else cout << "Error removing!\n";
}

/**
  based on the var name it will return the column of which to begin diagonal
  @param varname variable name to get diagonal start location
  @returns the column number that the diagonal will start based on var name
 */
int getColName(string varName){
  return 0;
}

string readRow(string const &fileName){
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
void addRowHashes(char const fileName[]){
   // Renaming current file as old.csv
   const char oldName[] = "old.csv";
   int renameResult = rename(fileName, oldName);
   // Create input stream of old file
   ifstream read(oldName);
   if (renameResult == 0) cout << "Success renaming!\n";
   else cout << "Error renaming!\n";
   // Create output stream and create a new data.csv
   ofstream write;
   write.open(fileName, ios::out | ios::trunc);
   // For every line in the file
   string line, cell, hash;
   while(getline(read, line)) {
     hash = encoder->generateHash(line);
     stringstream stream(line);
     // For every char in the row
     while(getline(stream, cell, ',')) write << cell << ',';
     // Write the row's hash
     write << hash << ",\n";
   }
   // Close the read and write streams
   read.close(); write.close();
}

// Takes in updated variable data and filename, then
// updates the file using trunc constant to discard
// the old data before updating
/**
 @param filename The name of the file to create or update
 @param varHashes the vector of variable hashed data and insert diagonally
 */
void writeDiagsHashToCSV(char const filename[], vector<string> varHashes) {
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
  int a = 0;
  for (int i = 0; i < maxLength; i++) {
    int j = 0;
    for (int k = 0; k < offset; k++) fout << randChars.at(a++) << ",";
    for (; j < varHashes.size() && j < maxWidth - offset; j++) {
      if (i < varHashes.at(j).size()) fout << varHashes.at(j).at(i) << ",";
      else fout << randChars.at(a++) << ",";
    }
    for (; j < maxWidth - offset; j++) fout << randChars.at(a++) << ",";
    offset += 1;
    fout << "\n";
  }
  fout.close(); addRowHashes(filename); deleteOldCSV("old.csv");
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

// Creates a global vector of random chars
void randCharacterVector() {
   for (int i = 0; i < 500; i++) randChars.push_back(randCharacter());
}