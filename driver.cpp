#include <iostream>
#include <fstream>
#include "Encoder.h"

using namespace std;

const string FILE_NAME = "output.csv";

void writeToCSV(string colName,int colStart, string value);
void writeJunk(string fileName,int lastUsedColumn);
string getColName(string varName, string value);

int main(){

    Encoder *encoder = new Encoder(); 

    cout<<"Hello"<<endl;
    cout<<"Hello"<<encoder->encodeDiagonal("guy", 5)<<endl;
    return 0;   
}

/**
  based on the var name it will return the column of which to begin diagnol
  @param varname variable name to get diagnol start location
  @returns the column number that the diagnol will start based on var name
 */
int getColName(string varName){

}



/**
  fills the upp and lower triangles with junk
  @param fileName file to write to
  @param lastUsedColumn highest column number that contains a value
 */
void writeJunk(string fileName, int lastUsedColumn){

}

/**
 opens and creates file
 @param fileName file to create or update
 @param colStart column to start diagnol at
 @param value hashed value to write starting at col start
*/
void writeToCSV(string fileName, int colStart, string value){
    fstream file; 
    file.open(fileName, ios::out | ios::app);

}