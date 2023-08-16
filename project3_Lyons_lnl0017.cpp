//Lauren Lyons
//project3_Lyons_lnl0017.cpp
//lnl0017

//MinGW G++ Compiler
//g++ -std=c++11 project3_Lyons_lnl0017.cpp -o project3.out
//./project3.out
//My input files that I used for testing are 1input1.txt, 1input2.txt, 2input1.txt, and 2input2.txt

// Reference comments
// I used the Project Hints pdf
// I used https://www.cplusplus.com/reference/vector/vector/ to understand vector
 
#include <fstream> 
#include <iostream> 
#include <string>
#include <sstream>
#include <vector> 
using namespace std; 
 
/* declare user-defined functions */ 

/* 
* Checks to see if file is a valid input file.
* Returns true if valid and false if not. 
* 
* Param: file Name of file to check (string)
* Return: validity of file's ability to be opened (bool)
*/
bool check_file(string);  
 
/*
* read_file will take the string passed as the
* name of the file and open that file. The numbers
* in the file will be in natural number order.
* Then it will read in all of the values into 
* a vector and return that vector. 
* 
* Param: file Name of file to be read in (string)
* Return: vector of all numbers in file (vector<int>)
*/ 
vector<int> read_file(string); 

/*
* Take the string passed as the name of the 
* file to print out in text and to create or 
* open a file to write to. It will then output 
* each number from the vector onto one line at 
* a time. 
*
* Param: name of File to be used (string)
* Param: a vector of the numbers to go into the file (vector<int>)
*/
void write_file(string, vector<int>); 
 
/* 
* Passes two vectors of ints and then it will
* use the fact that they are in natural number order
* to put the numbers from both into one vector that
* is also in natural number order. 
*
* Param: a vector to be merged with other param vector (vector<int>)
* Param: another vector to be merged with other param vector (vector<int>)
* Return: vector with the values from both parameter vectors (vector<int>)
*/
vector<int> merge(vector<int>, vector<int>); 
 
/* 
* Display the values of a given vector. 
* 
* Param: file Name of file to display. (string) 
* Param: v Vector containing values to display. (vector<int>) 
*/ 
void to_string(string, vector<int>); 
 
/* 
* Merge the numbers in two specified files and write all the numbers 
* to a specified third file sorted in ascending order. 
* 
* Return: 1 Program completed successfully. (int) 
*/ 
int main() 
{ 
    /* declare your variables */ 
    vector<int> numbers1, numbers2, numbers3;
    string file1, file2, file3;
 
    cout << "*** Welcome to Lauren's sorting program ***\n";

    /* Get name of file one. */ 
    do { 
        cout << "Enter the first input file name: "; 
        cin >> file1;
    } while (cin.fail() || !check_file(file1)); 
 
    /* Get and display numbers from file one. */ 
    numbers1 = read_file(file1);  
    to_string(file1, numbers1);
 
    /* Get name of file two. */ 
    do { 
        cout << "\nEnter the second input file name: "; 
        cin >> file2;
    } while (cin.fail() || !check_file(file2)); 
 
    /* Get and display numbers from file two. */ 
    numbers2 = read_file(file2); 
    to_string(file2, numbers2);
 
    /* Combine vectors and display the sorted result. */ 
    numbers3 = merge(numbers1, numbers2); 
  
    /* Get name of output file. */ 
    do { 
        cout << "\nEnter the output file name: "; 
        cin >> file3;
    } while (cin.fail()); 
 
    /* Write combined vector to output file. */ 
    write_file(file3, numbers3); 
  
    return 0; 
} 
 
//------------------------------------------------------------------//
//------------------------------------------------------------------//
bool check_file(string file) 
{ 
    /* Input file stream. (ifstream) */ 
    ifstream stream; 
 
    /* Check whether file exists. */ 
    stream.open(file.c_str()); 
    if (stream.fail()) 
    { 
        cout << "\n*** Not a valid file ***\n\n";
        return false;
    } 
    stream.close(); 
 
    return true; 
} 

//------------------------------------------------------------------//
//------------------------------------------------------------------//
vector<int> read_file(string file) 
{ 
    /* Input file stream. (ifstream) */ 
    ifstream stream; 
 
    /* Vector containing numbers from file. (vector<int>) */ 
    vector<int> v; 
 
    /* Integer read from file. (int) */ 
    string line; 
    int num;
 
    /* Add each number in the file to a vector. */ 
    stream.open(file); 
    if(stream.good())   getline(stream, line);
 
    for(int i = 0; stream.good(); i++) 
    { 
        stringstream(line) >> num;
        v.push_back(num);
        getline(stream,line);
    } 
  
    stream.close();
    return v; 
} 
 
//------------------------------------------------------------------//
//------------------------------------------------------------------//
void write_file(string file, vector<int> v) 
{ 
    /* Output file stream. (ofstream) */ 
    ofstream outFile;

    outFile.open(file); 
    for (int i = v.size()-1 ; i >= 0; i--)
    {
        outFile << v.at(i) << "\n";
    }

    outFile.close();
    cout << "*** Please check the new file - " << file << " ***";
    cout << "\n*** Goodbye. ***\n\n";
} 
 
//------------------------------------------------------------------//
//------------------------------------------------------------------//
vector<int> merge(vector<int> v1, vector<int> v2) 
{ 
    vector<int> v3;

    /* Compare both vectors. */ 
    while (v1.size() > 0 && v2.size() > 0) 
    { 
        if (v1.at(v1.size()-1) > v2.at(v2.size()-1)) 
        { 
            v3.push_back(v1.at(v1.size()-1));
            v1.pop_back();
        } else 
        { 
            v3.push_back(v2.at(v2.size()-1));
            v2.pop_back();
        } 
    } 
 
    /* Add any remaining numbers from vector one. */ 
    if (v1.size() > 0) 
    { 
        while(v1.size() > 0)
        {
            v3.push_back(v1.at(v1.size()-1));
            v1.pop_back();
        }
    } 
 
    /* Add any remaining numbers from vector two. */ 
    if (v2.size() > 0) 
    { 
        while(v2.size() > 0)
        {
            v3.push_back(v2.at(v2.size()-1));
            v2.pop_back();
        }
    } 
    
    cout << "\nThe sorted list of " << v3.size() << " numbers is:";
    for (int j = v3.size()-1 ; j >= 0; j--)
    {
        cout << " " << v3.at(j);
    }

    return v3; 
} 
 
//------------------------------------------------------------------//
//------------------------------------------------------------------//
void to_string(string file, vector<int> v) 
{  
    /* Display the numbers contained in a vector. */ 
    cout << "The list of " << v.size() << " numbers in file " << file << " is:\n";

    for(int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << "\n";
    }
} 