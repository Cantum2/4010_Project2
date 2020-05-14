##Approach
- We decided to store our data values diagonally to a csv file in order to hide the values
- Added in random data to the csv to keep the data in a rectangular format (disguised our strings and prevented the diagonal pattern from being revealed easily to intruders)
- Hashes of rows added to the end of each row in the csv to allow for value checking (if someone went in and changed the values to what they are not supposed to be)

##Detection
- When the program is started, a long list of random characters are created (Ensures that if the data is not changed from before, the random characters surrounding the diagonals stays the same)
- Number of rows compared between the old (containing what was there before changes) and new file (containing the changed values) to check if same number of rows (if not, data definitely has been changed)
- Whole rows are compared between the old, previously unchanged, file to the new and changed file; additionally, the row hashes in the ending column from the old file and the new file are compared to check for changes
