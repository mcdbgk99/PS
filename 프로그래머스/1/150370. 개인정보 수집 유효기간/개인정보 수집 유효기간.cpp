#include <string>
#include <vector>
using namespace std;

vector<int> solution(string today, vector<string> terms,
                     vector<string> privacies) {
  vector<int> answer;

  auto str_to_day = [](const string &date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    return year * 12 * 28 + month * 28 + day;
  };

  int today_day = str_to_day(today);

  int term_dur[26] = {0};
  for (string s : terms) {
    term_dur[s[0] - 'A'] = stoi(s.substr(2));
  }

  for (int i = 0; i < privacies.size(); ++i) {
    char type = privacies[i][11];
    int year = stoi(privacies[i].substr(0, 4));
    int month = stoi(privacies[i].substr(5, 2));
    int day = stoi(privacies[i].substr(8, 2));

    month += term_dur[type - 'A'];
    year += (month - 1) / 12;
    month = (month - 1) % 12 + 1;

    day -= 1;
    if (day == 0) {
      day = 28;
      month -= 1;
      if (month == 0) {
        month = 12;
        year -= 1;
      }
    }

    if (today_day > (year * 12 * 28 + month * 28 + day)) {
      answer.push_back(i + 1);
    }
  }

  return answer;
}