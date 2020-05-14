## Strengths
- Hashes were hidden from IdaPro
- The diagonal writing approach to a csv was intuitive and hid the data in a clever way
- Filled empty cells around the diagonals of true data further hid the values, created a red herring

## Weaknesses
- Strings and names were evident and you could derive a lot about how the program worked, as well as the fact there was value checking to begin with
- Clearly shown that data was written to csv's and that two separate csv files were being used for data validation
- If someone studied the subroutine code that writes data diagonally, maybe they could figure out that it's writing diagonally

## Future Changes
- Changing name of functions to not reveal intent
- Removing prints to the console that notify of file removing or renaming
- Change name of the csv files so as to not reveal the intent of the program
