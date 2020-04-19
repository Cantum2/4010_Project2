#include <iostream>
#include <fstream>
#include "vector"
#include <string>
#include <sstream>
#include "Encoder.h"



using namespace std;

const string FILE_NAME = "output.csv";

void writeHashToCSV(string colName, string value);
void writeJunk(string fileName,int lastUsedColumn);
string getColName(string varName, string value);
vector<string> readRow(istream& str);

int main(){

    Encoder *encoder = new Encoder(); 

    cout<<"Hello"<<endl;
    cout<<"Hello"<<encoder->encodeDiagonal("guy", 5)<<endl;
    writeHashToCSV("data.csv", "%^&*#");
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

/**
 opens and creates file
 (a job for python)
 @param fileName file to create or update
 @param colStart column to start diagnol at
 @param value hashed value to write starting at col start
*/
void writeHashToCSV(string fileName, string value){
  vector<char> hashChars(value.begin(), value.end()); // convert hashed value to vector
  string temp, newRow;
  int hashCharsIndex = 0;
  fstream file; 
  file.open(fileName, ios::out | ios::app);
  cout<<"1"<<endl;
  while (hashCharsIndex < hashChars.size()){
    // read each row 
    vector<string> row = readRow(file); // _ 9 % $
    cout<<"2"<<endl;
    // start adding new has into csv
    string s(1, hashChars[hashCharsIndex++]); // "5" 
    cout<<s<<endl;
    cout<<"3"<<endl;
    row.push_back(s); // _ 9 % $ 5
    cout<<"4"<<endl;
    // read vector back to string
    // TODO: optimize this
    cout<<"5"<<endl;
    for(size_t vecIndex = 0; vecIndex < row.size(); vecIndex++){
      newRow += row[vecIndex] + ",";
    }
    cout<<newRow<<endl;
    newRow += "\n";
    file << newRow; 
  } 
  file.close();
  cout<<"end f"<<endl;
  
}

// Possible concept for writing (and reading) diagonal of csv data
  // Writes a diagonal of 1's in csv with 0's in upper right and lower left cells.
  // Assumes that variables specified by rows, not columns (my bad, I can change that).
/**
 @param filename The name of the file to create or update
 */
void write_diagonal(string filename) {
    fstream fout;
    fout.open(filename, ios::out | ios::app);
    int startRow = 0, rowWidth = 10;
    int i = 0, diag = 0;
    for(diag = 0; diag < rowWidth - 1; diag++) {        
        for(i = 0; i < diag; i++) { // i = 0..(d - 1)
            fout << 0 << ','; // Insert random value
        }
        fout << 1; // i = d, Insert desired value on diagonal 
        for(i = diag + 1; i < rowWidth - 1; i++) { // i = (d + 1)..rowWidth
            fout << ", " << 0;// Insert random value
        }
        fout << "\n";
    }
}