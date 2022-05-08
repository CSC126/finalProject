#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

string firstName, lastName;
float quiz1, quiz2, quiz3, quiz4;
float lab1, lab2, lab3, lab4, lab5, lab6, lab7, lab8;
float hw1, hw2, hw3, hw4, hw5, hw6, hw7;
float exam1, exam2;
float final;

int main(){
    
    ifstream fin;
    ofstream fout;
    fin.open("gradesIn.txt");
    fout.open("gradesOut.txt");
    
    while(!fin.eof()){
        fin >> firstName >> lastName >> quiz1 >> quiz2 >> quiz3 >> quiz4 >> lab1 >> lab2 >> lab3 >> lab4 >> lab5 >> lab6 >> lab7 >> lab8 >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> hw6 >> hw7 >> exam1 >> exam2 >> final;
        
    }
    
    return 0;
}

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
    return(a + b)/2
}
