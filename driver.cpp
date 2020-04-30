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
 @param varHashes the vector of variable data to hash and insert diagonally
 */
void writeHashToCsv(string filename, vector<string> varHashes) {
  fstream fout;
  fout.open(filename, ios::out | ios::trunc);
  int maxLength = 0;
  int tempLength = 0;
  // Get length of longest string
  for (int v = 0; v < varHashes.size(); v++) {
    tempLength = varHashes.at(v).length();
    if (tempLength > maxLength) {
      maxLength = tempLength;
    }
  }
  // Place hashes into csv file
  int offset = 0;
  for (int i = 0; i < maxLength; i++) {
    for (int k = 0; k < offset; k++) {
      fout << " " << ", ";
    }
    for (int j = 0; j < varHashes.size(); j++) {
      if (i < varHashes.at(j).size()) fout << varHashes.at(j).at(i) << ", ";
      else fout << " " << ", ";
    }
    offset += 1;
    fout << "\n";
  }
}