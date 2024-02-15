#include <algorithm>
using std::sort; using std::for_each;
#include <functional>
using std::bind;
using namespace std::placeholders;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cin; using std::cout; using std::endl;

void print(const vector<string> &words)
{
    // uses a lambda function to print elements
    for_each(words.begin(), words.end(), [](const string &s) { cout << s << " "; });
    cout << endl;
}

int main()
{
    vector<string> words;

    // copy contents of each book into a single vector
    string next_word;
    while (cin >> next_word) {
        // insert next book's contents at end of words
        words.push_back(next_word);
    }
    print(words);

    // uses a lambda function to compare elements
    sort(words.begin(), words.end(), [](const string &s1, const string &s2){return s1 < s2;});
    print(words);

    return 0;
}
