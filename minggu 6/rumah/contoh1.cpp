#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(string text) {
  stack<char> charStack;
  string reversedText = "";
  // Push karakter ke stack
  for (char c : text) {
    charStack.push(c);}
  // Pop karakter dari stack dan bentuk string terbalik
  while (!charStack.empty()) {
    reversedText += charStack.top();
    charStack.pop();}
  return reversedText;}

int main() {
  string inputString;
  cout << "Masukkan string: ";
  getline(cin, inputString);

  string reversedString = reverseString(inputString);
  cout << "String terbalik: " << reversedString << endl;
  return 0;
}