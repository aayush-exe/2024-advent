#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

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

// dir pos.
// 0 1 2
// 3 X 4
// 5 6 7
struct map{
    
    const int arrSize = 9;
    bool dir[9] = {false};
};


map adjPos(const vector<string>& v, char t, int r, int c){
    // assumes r and c are valid calls
    int count = 0;
    map finder;
    int index = 0;

    cout << r << " "<< c << " " << v[r][c] << ": ";

    int rUpper = v.size() - 1;
    int cUpper = v[0].size() - 1;
    for (int i = (r>0 ? r-1 : r); i <= (r<rUpper ? r+1 : r); i++){
        for (int j = (c>0 ? c-1 : c); j <= (c<cUpper ? c+1 : c); j++){
            index++;
            if (i!=r || j!=c){
                if (v[i][j] == t){
                    count++;
                    finder.dir[index] = true;
                }
            }
        }
    }

    cout << count << endl;
    return finder;
}

const string order = "XMAS"; //this is the order of strings to follow

int checkVertical(const vector<string>& lines){
    int sum = 0;

    for(int i=0; i<lines.size() - 3; i++){
        for (int j=0; j<lines[0].length();j++){
            if ((lines[i][j] == 'X') && (lines[i+1][j] == 'M') && lines[i+2][j] == 'A' && lines[i+3][j] == 'S'){
                cout << i << " " << j << endl;
                sum++;
            }
        }
    }

    cout << "next" << endl;

    for(int i=lines.size() - 1; i>=3; i--){
        for (int j=0; j<lines[0].size();j++){
            if ((lines[i][j] == 'X') && (lines[i-1][j] == 'M') && lines[i-2][j] == 'A' && lines[i-3][j] == 'S'){
                cout << i << " " << j << endl;
                sum++;
            }
        }
    }

    return sum;

}

int checkHorizontal(const vector<string>& lines){
    int sum = 0;

    for(int i=0; i<lines.size(); i++){
        for (int j=0; j<lines[0].length() - 3;j++){
            if ((lines[i][j] == 'X') && (lines[i][j+1] == 'M') && lines[i][j+2] == 'A' && lines[i][j+3] == 'S'){
                cout << i << " " << j << endl;
                sum++;
            }
        }
    }

    cout << "next" << endl;

    for(int i=0; i<lines.size(); i++){
        for (int j=lines[0].size()-1; j>=3;j--){
            if ((lines[i][j] == 'X') && (lines[i][j-1] == 'M') && lines[i][j-2] == 'A' && lines[i][j-3] == 'S'){
                cout << i << " " << j << endl;
                sum++;
            }
        }
    }

    return sum;

}

int checkRDiag(const vector<string>& lines){
    int sum = 0;

    for(int i=0; i<lines.size() - 3; i++){
        for (int j=0; j<lines[0].length() - 3;j++){
            if ((lines[i][j] == 'X') && (lines[i+1][j+1] == 'M') && lines[i+2][j+2] == 'A' && lines[i+3][j+3] == 'S'){
                cout << i << " " << j << endl;
                sum++;
            }
        }
    }

    cout << "next" << endl;

    for(int i=lines.size() - 1; i>=3; i--){
        for (int j=lines[0].size() - 1; j>=3;j--){
            if ((lines[i][j] == 'X') && (lines[i-1][j-1] == 'M') && lines[i-2][j-2] == 'A' && lines[i-3][j-3] == 'S'){
                cout << i << " " << j << endl;
             sum++;
            }
        }
    }

    return sum;

}

int checkLDiag(const vector<string>& lines){
    int sum = 0;

    for(int i=0; i<lines.size() - 3; i++){
        for (int j=lines[0].size() - 1; j>=3;j--){
            if ((lines[i][j] == 'X') && (lines[i+1][j-1] == 'M') && lines[i+2][j-2] == 'A' && lines[i+3][j-3] == 'S'){
                cout << i << " " << j << endl;
                sum++;
            }
        }
    }
    cout << "next" << endl;

    for(int i=lines.size() - 1; i>=3; i--){
        for (int j=0; j<lines[0].size() - 3;j++){
            if ((lines[i][j] == 'X') && (lines[i-1][j+1] == 'M') && lines[i-2][j+2] == 'A' && lines[i-3][j+3] == 'S'){
                cout << i << " " << j << endl;
                sum++;
            }
        }
    }
    return sum;
}



int main() {
    ifstream inputFile("input.txt");
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

    int sum = 0;

    cout << "Vertical" << endl;
    sum += checkVertical(lines);

    cout << "Horizontal" << endl;
    sum += checkHorizontal(lines);

    cout << "RDiag" << endl;
    sum += checkRDiag(lines);

    cout << "LDiag" << endl;
    sum += checkLDiag(lines);
    
    cout << sum << endl;


}

