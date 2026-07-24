#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hash Set using separate chaining
vector<vector<string>> myHashSet = {
    {},
    {"Jones"},
    {},
    {"Lisa"},
    {},
    {"Bob"},
    {},
    {"Siri"},
    {"Pete"},
    {}
};

int hashFunction(string name) {
    int a = 0;
    for (char ch : name) {
        a += ch;
    }
    return a % myHashSet.size();
}

// Add a value to the hash set
void add(string name) {
    int index = hashFunction(name);
    vector<string>& bucket = myHashSet[index];

    // Check if already exists
    for (string item : bucket) {
        if (item == name)
            return;
    }

    bucket.push_back(name);
}

// Check if value exists
bool Contains(string name) {
    int index = hashFunction(name);
    vector<string>& bucket = myHashSet[index];

    for (string item : bucket) {
        if (item == name) {
            return true;
        }
    }

    return false;
}

int main() {
    add("Stuart");

    cout << "Hash Set:\n";
    for (int i = 0; i < myHashSet.size(); i++) {
        cout << i << ": ";
        for (string item : myHashSet[i]) {
            cout << item << " ";
        }
        cout << endl;
    }

    cout << "\nContains Stuart: ";

    if (Contains("Stuart"))
        cout << "true";
    else
        cout << "false";

    return 0;
}
