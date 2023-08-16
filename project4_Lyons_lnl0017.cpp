//Lauren Lyons
//project4_Lyons_lnl0017.cpp
//lnl0017

//MinGW G++ Compiler
//g++ -std=c++11 project4_Lyons_lnl0017.cpp -o project4.out
//./project4.out
//Currently the UNIT_TESTING define is commented out. In order to use the testing version
//  you must comment out the #define trivia_quiz and then uncomment #define UNIT_TESTING

// Reference comments
// I used the Project Hints pdf
 
#include <fstream> 
#include <iostream> 
#include <string>
using namespace std; 
 
 
//Structure for creating a linked list that holds a trivia question,answer and point amount. 
struct triva_node 
{ 
    string question; 
    string answer; 
    int point; 
    triva_node *next; 
}; 

//creates a pointer to triva_node. 
typedef triva_node* ptr_node; 
 
//Prototypes 
void Unit_Test();
void init_question_list(ptr_node& q_list);
void add_question(ptr_node& q_list);
int ask_question(ptr_node q_list, int num_ask);


//Global Variables
int num_of_questions;
int points_awarded;
 
 
//creates two versions. 
//#define UNIT_TESTING 
#define triva_quiz 
int main() 
{ 
    //Unit_Test(); 
    ptr_node node_list = new triva_node; 
    //Creates a new trivia game / 
    //Sets up three original  questions/ 
    //Sets up loop for user to input his or her own questions. 
    //Quiz questions are stored in linked list. 
    #ifdef triva_quiz 
    init_question_list(node_list); 
    points_awarded = 0;
    string answer_continue;
    cout << "*** Welcome to Lauren's trivia quiz game ***\n"; 
    
    do {
        add_question(node_list); 
        cout << "Continue? (Yes/No): "; 
        cin >> answer_continue;
        cin.sync();
    } 
    while (answer_continue.compare("Yes") == 0 || answer_continue.compare("yes") == 0);
    
    //This is start of Trivia quiz game. 
    ask_question(node_list, num_of_questions); 
    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***"; 
    return 0; 
    #endif 


    //Method for testing 
    #ifdef UNIT_TESTING 
    
    cout << "***This is a debugging version ***\n";
    Unit_Test(); 
    return 0; 
    #endif 
}

 
 
 
//initializes the quiz to have these three questions inputted into the linked list. 
void init_question_list(ptr_node& q_list) 
{ 
    string bob; 
    ptr_node cur_ptr = new triva_node; 
    q_list->next = cur_ptr;
    cur_ptr->question = "How long was the shortest war on record? (minutes)"; 
    cur_ptr->answer = "38"; 
    cur_ptr->point = 100; 
    cur_ptr->next = new triva_node;
    cur_ptr = cur_ptr->next;

    cur_ptr->question = "What was Bank of America's original name?"; 
    cur_ptr->answer = "Bank of Italy"; 
    cur_ptr->point = 50; 
    cur_ptr->next = new triva_node;
    cur_ptr = cur_ptr->next;

    cur_ptr->question = "What is the best-selling video game of all time?"; 
    cur_ptr->answer = "Wii Sports"; 
    cur_ptr->point = 20; 

    num_of_questions = 3;
} 


//gives user the option to add a question to the linked list. 
//question is added to the front of the linked list. 
void add_question(ptr_node& q_list) 
{ 
    int pointanswer; 
    ptr_node new_ptr = new triva_node; 
    new_ptr->next = q_list->next;
    q_list->next = new_ptr;
    //gets data from user.  
    cout << "Enter a question: "; 
    getline(cin, new_ptr->question); 
    cout << "Enter an answer: "; 
    getline(cin, new_ptr->answer); 
    cout << "Enter award points: ";
    cin >> pointanswer;
    new_ptr->point = pointanswer;
    cin.sync();

    num_of_questions++;
} 


//Checks for null value 
//Ask the user trivia questions and starts the game 
int ask_question(ptr_node q_list, int num_ask) 
{ 
    string user_answer;
    ptr_node cur_ptr = q_list->next;
    if (q_list == NULL) 
    {
        return 0; 
    }

    if(num_ask < 1) 
    { 
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1."; 
    }   
    else if(num_of_questions < num_ask) 
    { 
        cout << "\nWarning - There is only " << num_of_questions << " trivia in the list."; 
    } 
    else 
    { 
        for(int x = 0; x < num_ask; x++) 
        { 
            cout << "\nQuestion: " << cur_ptr->question << endl; 
            cout << "Answer: "; 
            getline(cin, user_answer); 
            if (user_answer.compare(cur_ptr->answer) == 0) //correct
            {
                cout << "Your answer is correct! You recieved " << cur_ptr->point << " points."; 
                points_awarded += cur_ptr->point;
                cur_ptr = cur_ptr->next;
                cout << "\nYour total points: " << points_awarded << endl;
            } 
            else //wrong
            { 
                cout << "Your answer is wrong. The correct answer is " << cur_ptr->answer << endl;
                cout << "\nYour total points: " << points_awarded << endl;
                cur_ptr = cur_ptr->next; 
            } 
        }
    } 
    return 0; 
} 
 
 
 
//Test cases to check whether the methods work. 
void Unit_Test() 
{
    ptr_node node_list = new triva_node; 
    init_question_list(node_list); 
    cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl; 
    ask_question(node_list, 0); 
    points_awarded = 0;
    cout << "\nCase 1 Passed\n\n"; 
    
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list.  The tester enters an incorrect answer."; 
    ask_question(node_list, 1);
    points_awarded = 0;
    cout << "\nCase 2.1 Passed\n\n"; 

    cout << "Unit Test Case 2.2: Ask 1 question in the linked list.  The tester enters an correct answer."; 
    ask_question(node_list, 1);
    points_awarded = 0;
    cout << "\nCase 2.2 Passed\n\n"; 

    cout << "Unit Test Case 3: Ask all the questions of the last trvia in the linked list."; 
    ask_question(node_list, num_of_questions);
    points_awarded = 0;
    cout << "\nCase 3 Passed\n\n"; 

    cout << "Unit Test Case 4: Ask 5 questions in the linked list."; 
    ask_question(node_list, 5);
    cout << "\nCase 4 Passed";

    cout << "\n\n*** End of the Debugging Version ***"; 
} 
 
