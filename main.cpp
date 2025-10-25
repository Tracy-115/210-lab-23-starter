#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main_menu(){
    int num;

    cout <<  "*** GOAT MANAGER 3001 ***" << endl;
    cout <<  "[1] Add a goat" << endl;
    cout <<  "[2] Delete a goat" << endl;
    cout <<  "[3] List goats" << endl;
    cout <<  "[4] Quit" << endl;
    cout <<  "Choice --> ";
    cin >> num;

    while (num <1 || num>4 ){
        cout << "Invalid number choice, please re-enter: ";
        cin >> num;
    }
    return num;
}
void add_goat(list<Goat> &trip, string names[], string colors[]){
    //randomly select a name and color from main()'s arrays and select a random age between 0 and MAX_AG
    int name = rand()% SZ_NAMES; //these are the positions or the index
    int color = rand()% SZ_COLORS;
    int age = rand()% (MAX_AGE+1);

    Goat g(names[name], age, colors[color]); //this takes back to the constructor int goat.h
    trip.push_back(g);

    cout << "New goat: ";
    g.print();
}
void display_trip(list<Goat> trip){ //the choices are going to be displayed in the format [number] information
    if (trip.empty()){
        cout << "It is empty, there is no trip";
    }
    
    int a = 1;
    for (Goat g:trip){
        cout << "[" << a << "]" ;
        g.print();
        a++;
    }
}
int select_goat(list<Goat> trip){
    cout << "Choice --> "; //the user will have to make a choice 
    int choice;
    cin >> choice;
    while (choice <1 || choice >=a){
        cout << "Re-enter your choice: ";
        cin >> choice;
    }
    return choice -1;
}
void delete_goat(list<Goat> &trip){//this si for the delete choice 
    int num = select_goat(trip);
    if (num == - 1) return;

    int a = 0;
    for (auto it = trip.begin(); it != trip.endl(); ++it, ++a){ //in this loop it points from the start and goes until the end to find the index that the user wishes to delete
        if (a ==num){
            cout << "Delete";
            it->print();
            trip.erase(it);
            cout << "Chosen goat is deleted" << endl;
            return;
        }
    }
}

int main() {
    srand(time(0));
    bool again =true;
    list<Goat> trip;
    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    while(again) {
        int num = main_menu();
        cout << endl;
        switch(num){
            case 1{
                add_goat(trip, names, colors);
                cout << endl;
                break;
            }
            case 2{
                delete_goat(trip);
                cout << endl;
                break;
            }
            case 3{
                display_trip(trip);
                cout << endl;
                break;
            }
            case 4{
                again = false;
                break;
            }
    }
}

    return 0;
}

