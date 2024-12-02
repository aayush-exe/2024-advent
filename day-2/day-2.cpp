#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
const int RLEN = 1000;

void selection_sort(vector<int>& arr){
    for (int i=0; i<arr.size(); i++){
        int min = i;
        for (int j=i; j<arr.size(); j++){
            if (arr[j]<arr[min]) min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int search(vector<int>& arr, int target){
    for (int i=0; i<arr.size(); i++){
        if (arr.at(i) == target) return i;
    }

    return -1;

}

void printv(vector<int>& arr){
    for (int i=0;i<arr.size();i++)
        cout << arr.at(i) << ", ";
    cout << endl;
}

void pop(vector<int>& arr, int index){
    //pop back
    stack<int> temp;
    while (arr.size() - 1 != index){
        temp.push(arr.back());
        arr.pop_back();
    }
    arr.pop_back();
    while (!temp.empty()){
        arr.push_back(temp.top());
        temp.pop();
    }

}

bool test_v(vector<int>& arr){
    int dir = 0;
    for(int j=0; j<arr.size() - 1; j++){
        if (dir == 0){
            //first time
            dir = (arr[j] < arr[j+1]) ? 1 : -1;
        }
        if (!((arr[j] - arr[j+1] < 0) == (dir > 0) && abs(arr[j]-arr[j+1])>=1 && abs(arr[j]-arr[j+1])<=3)) return false;
    }
    return true;
}


int main() {
    ifstream inputFile("input.txt");
    vector<vector<int> > arr;
    vector<string> lines;
    string line;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            lines.push_back(line);
        }
        inputFile.close();
    } else {
        cerr << "Unable to open file";
        return 1;
    }


    for(int i=0; i<lines.size(); i++){
        vector<int> current;
        line = lines.at(i);
        string temp = "";
        for (int j=0; j<line.size(); j++){
            if (line[j] == ' '){
                current.push_back(stoi(temp));
                temp = "";
            } 
            else{
                temp += line[j];
            }
        }
        current.push_back(stoi(temp));
        arr.push_back(current);
    }

    // for (int i=0; i<RLEN; i++)
    //     printv(arr[i]);

    // day 1 solution:


    int sum = 0;


    // day 1 solution
    for (int i=0; i<RLEN; i++){
        if (test_v(arr[i])) sum++;
    }

    cout << "day 1: " << sum << endl;

    sum = 0;

    // day 2 solution
    for (int i=0; i<RLEN; i++){
        bool check = false;
        if (test_v(arr[i])) check = true;

        for(int j=0; j<arr[i].size(); j++){
            vector<int> temp = arr[i];
            // made my own pop function cause i couldnt find c++ lib standard for it
            // idk if its doing too much lmao
            pop(temp, j);
            if (test_v(temp)) check = true;
        }

        if (check) sum++;
    }

    cout << "day 2: " << sum << endl;


    return 0;
}


