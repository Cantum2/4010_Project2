## Dissection
1. Opened the executable for the program, a.exe, with the IdaPro tool
2. Checking the imports window, the import TerminateProcess was found (Could reveal to the intruder that a process could be terminated if something or an action is detected with the code or data)
3. Checking the strings window, the strings for the data of the old and new file were found
4. Found the subroutine for writing data to a csv diagonally
5. Discovered in the names window many references to the renaming, removing, and changing of files

## Analysis
1. When finding the strings for the variables (int, strings, array,...) reveals way too much about how the program works and the actual data begin stored
2. Also, the strings of data from the old and new file were easily found to be corresponding (revealing that two files being used to store and check the data)
3. In the .text section of the IDA View-A window, there are references to int_, double_, and so on... (could tell the intruder that the program or a class could be involved that encodes certain data types)
4. In the subroutine writing data diagonally, many references to the string ", " were found (could reveal that data is being stored to a csv diagonally)
5. The names aTheyMatch, aTheyDontMatch, aSuccessRemoving, ..., aSuccessRenaming,... were found (showing that the program is checking for user/intruder intervention, seeing if someone is changing the data)
