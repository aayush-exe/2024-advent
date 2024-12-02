#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
const int NUMLEN = 5;
const int GAPLEN = 3;

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


int main() {
    ifstream inputFile("input.txt");
    vector<int> larr;
    vector<int> rarr;
    vector<int> rnum;
    vector<int> rkey;
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

    string current;
    //12486   98890
    for(int i=0; i<lines.size(); i++){
        current = lines.at(i);
        larr.push_back(stoi(current.substr(0,NUMLEN)));
        rarr.push_back(stoi(current.substr(NUMLEN+GAPLEN,NUMLEN)));
    }

    // part 1 solution

    selection_sort(larr);
    selection_sort(rarr);

    // int sum = 0;
    // for (size_t i=0; i<larr.size(); i++){
    //     sum += abs(larr.at(i) - rarr.at(i));
    // }

    // cout << sum << endl;


    // part 2 solution:

    for (int i=0; i<rarr.size(); i++){
        int current = rarr.at(i);
        int result = search(rnum, current);

        if (result == -1){
            rnum.push_back(current);
            rkey.push_back(1);
        }
        else{
            rkey[result]++;
        }
    }

    // printv(rnum);
    // printv(rkey);

    int sum = 0;

    for (int i=0; i<larr.size(); i++){
        int cur = larr.at(i);
        sum += cur * (search(rnum, cur) == -1 ? 0 : rkey[search(rnum, cur)]);
    }

    cout << sum << endl;


    return 0;
}


