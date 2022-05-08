#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//declaring all the functions
char calculateLetterGrade(double);
double findMinQuiz(double, double, double, double);
double findAverageQuizScore(double, double, double, double);
double findAverageHomeworkScore(double, double, double, double, double, double, double);
double findAverageLabScore(double, double, double, double, double, double, double, double);
double findAverageTestScore(double, double);

string firstName, lastName;
float quiz1, quiz2, quiz3, quiz4, lab1, lab2, lab3, lab4, lab5, lab6, lab7, lab8, hw1, hw2, hw3, hw4, hw5, hw6, hw7, exam1, exam2, Thefinal;
double FINAL_AVERAGE;
char LETTER_GRADE;
double studentsInClass = 0, averageOfCourseAverage = 0;

int main(){
    
    ifstream fin;
    ofstream foutOne, foutTwo;
    fin.open("gradesIn.txt");
    foutOne.open("gradesOut1.txt");
    foutTwo.open("gradesOut2.txt");
    
    //The loop works by checking if all these variables can be defined in a row and if they can then the condition is met and the loop runs
    while(fin >> firstName >> lastName >> quiz1 >> quiz2 >> quiz3 >> quiz4 >> lab1 >> lab2 >> lab3 >> lab4 >> lab5 >> lab6 >> lab7 >> lab8 >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> hw6 >> hw7 >> exam1 >> exam2 >> Thefinal){
       //calling all the functions and setting their values to variables to be used later
        double calcQuizWeight = findAverageQuizScore(quiz1, quiz2, quiz3, quiz4)*.20;
        double calcHwWeight = findAverageHomeworkScore(hw1, hw2, hw3, hw4, hw5, hw6, hw7)*.10;
        double calcLabWeight = findAverageLabScore(lab1, lab2, lab3, lab4, lab5, lab6, lab7, lab8)*.10;
        double calcTestWeight = findAverageTestScore(exam1, exam2)*.30;
        double calcFinalWeight = Thefinal * .30;
        FINAL_AVERAGE = calcQuizWeight + calcHwWeight + calcLabWeight + calcTestWeight + calcFinalWeight;
        LETTER_GRADE = calculateLetterGrade(FINAL_AVERAGE);
        
        //formatting the output files correctly
        foutOne << firstName << ", " << lastName << endl << "Quiz Average: " << calcQuizWeight << endl
        << "Average Of Exams: " << calcTestWeight << endl << "Average of labs: " << calcLabWeight << endl << "Average of Homework: " << calcHwWeight << endl << "The Final: " << calcFinalWeight << endl << "The course Average: " << FINAL_AVERAGE << endl << endl;
        
        foutTwo << firstName << ", " << lastName << endl << "Course Average: " << FINAL_AVERAGE << endl << "Letter Grade: " << LETTER_GRADE << endl << endl;
        
        //adding to two variables that will be printed after the while loop
        studentsInClass++;
        averageOfCourseAverage += FINAL_AVERAGE;
        
    }
        
    foutTwo << "Total Students in the class: " << studentsInClass << endl << "Average of course average: " << (averageOfCourseAverage / studentsInClass);
    
    //closing the files as we do not need to add to them anymore
    fin.close();
    foutOne.close();
    foutTwo.close();
    
    return 0;
}


//all the functions to use in the code
char calculateLetterGrade(double a){
    char grade;
    if(a >= 90){
        grade = 'A';
        return grade;
    }
    else if(a >= 80){
        grade = 'B';
        return grade;
    }
    if(a >= 70){
        grade = 'C';
        return grade;
    }
    if(a >= 60){
        grade = 'D';
        return grade;
    }
    else{
        grade = 'F';
        return grade;
    }
}

double findMinQuiz(double a, double b, double c, double d){
    if(a < (b && c && d)){
        return a;
    }
    if(b < (a && c && d)){
        return b;
    }
    if(c < (a && b && d)){
        return c;
    }
    else{
        return d;
    }
}

double findAverageQuizScore(double a, double b, double c, double d){
    if(a < (b && c && d)){
        return (b + c + d)/3;
    }
    if(b < (a && c && d)){
        return (a + c + d)/3;
    }
    if(c < (a && b && d)){
        return (a + b + d)/3;
    }
    else{
        return (a + b + c)/3;
    }
    
}

double findAverageHomeworkScore(double a, double b, double c, double d, double e, double f, double g){
    return (a + b + c + d + e + f + g)/7;
}

double findAverageLabScore(double a, double b, double c, double d, double e, double f, double g, double h){
    return(a + b + c + d + e + f + g + h)/8;
}

double findAverageTestScore(double a, double b){
    return(a + b)/2;
}
