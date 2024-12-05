Compiling the code:

make : makes and compiles the project and creates three executables. create, bruteforce, divideconquer
make clean: cleans up those executables to recompile if needed

How to use the executables:

create : ./create <number> 
	This command line is for create.cpp. The number is the amount of points to create in the file. 

./create 100 // Creates 100 points in a file called output100.txt

 bruteforce : ./bruteforce <filename>
	 The file name must be a file created previously by ./create
 ex.
./bruteforce output100.txt //Finds the closest pair using bruteforce in the output100.txt file previously created

divideconquer : ./divideconquer <filename>
	 The file name must be a file created previously by ./create
ex.
./divideconquer output100.txt //Finds the closest pair using divideconquer in the output100.txt file previously created
