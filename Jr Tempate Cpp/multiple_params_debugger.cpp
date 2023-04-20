#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <cstdarg>
#include <utility>

using namespace std;

queue<string> getWords(string str) {
    istringstream iss(str);

    string word;
    queue<string> words;
    while (getline(iss, word, ',')) {
        words.push(word);
    }
    return words;
}

template<typename T>
void debugAll(queue<string>&q, T arg) {
    cout << (q.front()) << " " << arg << endl;
    q.pop();
}

template<typename T, typename... Args>
void debugAll( queue<string>&q, T arg, Args... args) {

    cout << (q.front()) << " " << arg << endl;
    q.pop();
    debugAll(q, forward<Args>(args)...);
}

template<typename... Args>
void callBoth(const char* str, Args... args) {
    string args_str = str;
    queue<string> varNames = getWords(str); // pass only #__VA_ARGS__
    debugAll(varNames, forward<Args>(args)...); // pass only __VA_ARGS__
}

#define DEBUG_ALL(...) callBoth(#__VA_ARGS__, __VA_ARGS__)

int main() {
    int x = 42;
    double y = 3.14;
    string z = "hello";
    DEBUG_ALL(x, y, z);
    return 0;
}

// Output
// x 42
//  y 3.14
//  z hello
