#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Set global Variables.
ifstream fIn;
const int MAX = 35; // number of students
struct STUDENTS{
        string fname;
        string lname;
        int testScore;
        char grade;
};

void input(ifstream &);
char calculateGrade(STUDENTS);
int highestScore(STUDENTS *, int);

int main(){ 
    input(fIn);
}

void input(ifstream &fIn){
    ofstream fOut;
    fIn.open("students.txt");
    fOut.open("students-out.txt");
    STUDENTS studentsArr[MAX] = {};
    int r = 0;
    int hTestScore;

    if (!fIn){
        cout << "Cannot open input file. Program terminates!." << endl;
        return;
    }


    while(!fIn.eof()){
        STUDENTS student;
        studentsArr[r] = student;

        fIn >> student.fname >> student.lname >> student.testScore;
        // switch statement that calculates grade goes here
        student.grade = calculateGrade(student);
        fOut << left << setw(12) << student.lname + ", " << setw(12) << 
            student.fname << right << setw(4) << student.testScore << 
            setw(4) << student.grade << endl;
        hTestScore = highestScore(&studentsArr[r], MAX);
        r++;

    }
    fOut << endl << hTestScore << endl;

    fIn.close();
    fOut.close();
}

char calculateGrade(STUDENTS student){
    if(student.testScore >= 90 && student.testScore <= 100){
        return 'A';
    }else if(student.testScore >= 80 && student.testScore <= 89){
        return 'B';
    }else if(student.testScore >= 70 && student.testScore <= 79){
        return 'C';
    }else if(student.testScore >= 60 && student.testScore <= 69){
        return 'D';
    }else if(student.testScore >= 0 && student.testScore <= 59){
        return 'F';
    }else{
        return 'N';
    }
}

int highestScore(STUDENTS listOfStudents[], int MAX){
     //Declare variables
     int highTest = 0,i;

     //Loop until length

     for(i = 0; i < MAX; i++){
         if (highTest < listOfStudents[i].testScore && listOfStudents[i].testScore > listOfStudents[i + 1].testScore){
            highTest = listOfStudents[i].testScore;
         }
     }
     //Return high

     return highTest;

}