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

    struct tuple{
        int x;
        int y;
    };

    int sum = 0;
    int doC = 0, dontC = 0;
    bool isDo = true;

    for (int i=0; i<lines.size(); i++){
        string cur = lines[i];
        int stage = 0;
        string temp; 
        tuple nums;
        
        

        for (int j=0; j<cur.size(); j++){
           
            if ((cur.size() -1 >= j+3)  && cur.substr(j, 4) == "do()") {
                isDo = true;
                doC++;
            }
            else if ((cur.size() -1 >= j+6)  && cur.substr(j, 7) == "don't()") {
                isDo = false;
                dontC++;
            }

            if (stage == 0 && (cur.size() -1 >= j+3) && cur.substr(j, 4) == "mul("){
                j+=3;
                stage = 1;
                
            }
            else if (stage == 1 && isdigit(cur[j])){
                temp += cur[j];
               
            }
            else if (stage == 1 && cur[j] == ','){
                nums.x = stoi(temp);
                temp = "";
                stage = 2;
              
            }
            else if (stage == 2 && isdigit(cur[j])){
                temp += cur[j];
                
            }
            else if (stage == 2 && cur[j] == ')'){
                nums.y = stoi(temp);
                temp = "";
                stage = 0;

                if (isDo) sum += nums.x * nums.y;

                nums.x = 0;
                nums.y = 0;
               

            }
            else{
                nums.x = 0;
                nums.y = 0;
                temp = "";
                stage = 0;
                
            }
            

        }
    }
    cout << doC << endl;
    cout << dontC << endl;
    cout << sum << endl;


}

