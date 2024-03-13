#include <iostream>
using namespace std;
#include <cstring>
#include <fstream>


//void cit(int n,int mat[20][20]) {
//    for(int i = 0;i < n;i++) {
//        for(int j = 0;j < n;j++) {
//            cin >> mat[i][j];
//        }
//    }
//}
//
//void afis(int n,int mat[20][20]) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << mat[i][j] << " ";
//
//        }
//        cout << endl;
//    }
//}


class BankAccount{
    public:
        int balance = 0;


    //public:
    void auszahlen(int amount){
        this->balance -= amount;
    }

    void einzahlen(int amount){
        this->balance += amount;
    }

    int kontostand(){
        return this->balance;
    }

};





int main() {
    // Task1
//    char name[100], lastname[100];
//    cin >> name;
//    cin >> lastname;
//    int cnt = 0, i = 1;
//
//    cout << "Hello " << name << " " << lastname << endl;
//
//    cnt = strlen(name) + strlen(lastname);
//
//    cout << cnt;

//    string firstName, lastName;
//    cout << "Enter your Name:";
//    cin >> firstName;
//
//    cout << "Enter Last Name:";
//    cin >> lastName;
//
//    cout << "Hello " << firstName << " " << lastName << " " << firstName.length() + lastName.length();


//Task2

//    struct Daten{
//        int nr;
//        string name;
//        int post;
//        string place;
//    } person[100];
//
//
//    cout << "Enter name:";
//    cin >> person[0].name;
//
//    cout << "Enter number:";
//    cin >> person[0].nr;
//
//    cout << "Post number:";
//    cin >> person[0].post;
//
//    cout << "Place:";
//    cin >> person[0].place;
//
//    cout << "Number: " << person[0].nr << endl;
//    cout << "Name: " << person[0].name << endl;
//    cout << "Post: " << person[0].post << endl;
//    cout << "Place: " << person[0].place << endl;



//    BankAccount b;
//    b.balance = 1000;

// Task 3

    int i, j, n, mat1[20][20], mat2[20][20], mat3[20][20];

    ifstream fin("data.in");
    fin >> n;

    for (i = 0;i < n;i++){
        for (j = 0;j < n;j++){
            fin >> mat1[i][j];
        }
    }

    for (i = 0;i < n;i++){
        for (j = 0;j < n;j++){
            fin >> mat2[i][j];
        }
    }

    for (i = 0;i < n;i++){
        for (j = 0;j < n;j++){
            mat3[i][j] += mat1[i][j] * mat2[j][i];
        }
    }

    for (i = 0;i < n;i++){
        for (j = 0;j < n;j++){
            cout << mat3[i][j] << " ";
        }

        cout << endl;
    }

//    for (i = 0;i < n;i++){
//        for (j = 0;j < n;j++){
//            cout << mat1[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << endl;
//
//    for (i = 0;i < n;i++){
//        for (j = 0;j < n;j++){
//            cout << mat2[i][j] << " ";
//        }
//
//        cout << endl;
//    }

}
