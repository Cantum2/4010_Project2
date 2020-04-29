#include <iostream>
#include <fstream>
#include "vector"
#include <string>
#include <sstream>
#include "Encoder.h"

using namespace std;

const string FILE_NAME = "output.csv";

void writeHashToCSV(string fileName);
void writeJunk(string fileName,int lastUsedColumn);
string getColName(string varName, string value);
vector<string> readRow(istream& str);

int main(){

    Encoder *encoder = new Encoder();     
    cout<<"Hello"<<endl;
    string res = encoder->encodeVariable("guy", 5);
    cout<<"guy5 encodes to "<<res<<endl;
    cout<<res<< " decodes to "<<encoder->generateHash(res)<<endl;
    writeHashToCSV("data.csv");
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



/**
  fills the upp and lower triangles with junk
  @param fileName file to write to
  @param lastUsedColumn highest column number that contains a value
 */
void writeJunk(string fileName, int lastUsedColumn){

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
 @param hashes the vector of variable data to hash and insert diagonally
 */
void writeHashToCsv(string filename, vector<string> hashes) {
  fstream fout;
  fout.open(filename, ios::out | ios::trunc);
  int maxLength = 0;
  // Get length of longest string
  for (size_t v = 0; v < hashes.size(); v++) {
    if (int tempLength = hashes.at(v).length() > maxLength) {
      maxLength = tempLength;
    }
  }
  int offset = 0;
  for (size_t i = 0; i < maxLength; i++) {
    for (size_t j = 0; j < maxLength; j++) {
      // Place hashes.at(j).at(i) @ cell [j + offset][i]
    }
    offset += 1;
  }
}

/*
void writeHashToCSV(string filename, vector<string> updateData) {
    fstream fout;
    fout.open(filename, ios::out | ios::trunc);
    int startRow = 0, rowWidth = 10;
    int i = 0, diag = 0;
    for(diag = 0; diag < rowWidth - 1; diag++) {        
        for(i = 0; i < diag; i++) fout << 0 << ", ";
        fout << 1;
        for(i = diag + 1; i < rowWidth - 1; i++) fout << ", " << 0;
        fout << "\n";
    }
}
*/