#include <iostream>
#include <string>

using namespace std;

const int BUCKET_COUNT = 10;

class Entry {
public:
    string key;
    string value;
    Entry* next;

    Entry(string k, string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class SimpleHashMap {
private:
    Entry* buckets[BUCKET_COUNT];

public:
    // Constructor
    SimpleHashMap() {
        for (int i = 0; i < BUCKET_COUNT; i++) {
            buckets[i] = nullptr;
        }
    }

    // Destructor
    ~SimpleHashMap() {
        for (int i = 0; i < BUCKET_COUNT; i++) {
            Entry* current = buckets[i];
            while (current != nullptr) {
                Entry* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    // Hash Function
    unsigned int hashFunction(const string& key) {
        unsigned int sum = 0;

        for (char ch : key) {
            if (isdigit(ch))
                sum += ch - '0';
        }

        return sum % BUCKET_COUNT;
    }

    // Insert or Update
    void put(const string& key, const string& value) {
        unsigned int index = hashFunction(key);

        Entry* current = buckets[index];

        // Update existing key
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        // Insert new entry
        Entry* newEntry = new Entry(key, value);
        newEntry->next = buckets[index];
        buckets[index] = newEntry;
    }

    // Get value
    string get(const string& key) {
        unsigned int index = hashFunction(key);

        Entry* current = buckets[index];

        while (current != nullptr) {
            if (current->key == key)
                return current->value;

            current = current->next;
        }

        return "Key not found";
    }

    // Remove key-value pair
    void removeEntry(const string& key) {
        unsigned int index = hashFunction(key);

        Entry* current = buckets[index];
        Entry* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr)
                    buckets[index] = current->next;
                else
                    prev->next = current->next;

                delete current;
                return;
            }

            prev = current;
            current = current->next;
        }
    }

    // Print Hash Map
    void printHashMap() {
        cout << "Hash Map Contents:\n";

        for (int i = 0; i < BUCKET_COUNT; i++) {
            cout << "Bucket " << i << ": ";

            Entry* current = buckets[i];

            while (current != nullptr) {
                cout << "(" << current->key << ": "
                     << current->value << ") ";
                current = current->next;
            }

            cout << endl;
        }
    }
};

int main() {
    SimpleHashMap map;

    map.put("123-4567", "Charlotte");
    map.put("123-4568", "Thomas");
    map.put("123-4569", "Jens");
    map.put("123-4570", "Peter");
    map.put("123-4571", "Lisa");
    map.put("123-4672", "Adele");
    map.put("123-4573", "Michaela");
    map.put("123-6574", "Bob");

    map.printHashMap();

    cout << "\nName associated with '123-4570': "
         << map.get("123-4570") << endl;

    cout << "Updating the name for '123-4570' to 'James'.\n";

    map.put("123-4570", "James");

    cout << "Name associated with '123-4570': "
         << map.get("123-4570") << endl;

    return 0;
}