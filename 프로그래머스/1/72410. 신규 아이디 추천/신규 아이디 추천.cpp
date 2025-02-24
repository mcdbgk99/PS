#include <string>
#include <vector>

using namespace std;

string solution(string step_1) {
  for (char &c : step_1) {
    c = tolower(c);
  }

  string step_2;
  for (char c : step_1) {
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' ||
        c == '_' || c == '.') {
      step_2.push_back(c);
    }
  }

  string step_3;
  for (char c : step_2) {
    if (!step_3.empty() && c == '.' && step_3.back() == '.') {
      continue;
    }
    step_3.push_back(c);
  }

  if (!step_3.empty() && step_3.front() == '.') {
    step_3.erase(step_3.begin());
  }

  if (!step_3.empty() && step_3.back() == '.') {
    step_3.pop_back();
  }

  if (step_3.empty()) {
    step_3 = "a";
  }

  if (step_3.size() >= 16) {
    step_3 = step_3.substr(0, 15);
    if (!step_3.empty() && step_3.back() == '.') {
      step_3.pop_back();
    }
  }

  while (step_3.size() < 3) {
    step_3.push_back(step_3.back());
  }

  return step_3;
}