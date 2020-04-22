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

// Possible concept for writing (and reading) diagonal of csv data
  // Writes a diagonal of 1's in csv with 0's in upper right and lower left cells.
  // Assumes that variables specified by rows, not columns (my bad, I can change that).
/**
 @param filename The name of the file to create or update
 */
void writeHashToCSV(string filename) {
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