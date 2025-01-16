#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int>> v;
vector<bool> visited;
deque<int> dq;
unordered_map<char, char> parent;
unordered_map<char, char> child;
vector<bool> has_parent;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string str;
  getline(cin, str);

  v.resize(n, {-1, -1});

  for (int i = 0; i < n; ++i) {
    getline(cin, str);

    v[str[0] - 'A'] = {str[2] != '.' ? str[2] - 'A' : -1,
                       str[4] != '.' ? str[4] - 'A' : -1};
  }

  // forward traverse

  visited.assign(n, false);
  visited[0] = true;
  dq.push_back(0);

  while (!dq.empty()) {
    int now = dq.back();
    dq.pop_back();

    visited[now] = true;
    cout << static_cast<char>(now + 'A');

    int left = get<0>(v[now]);
    int right = get<1>(v[now]);

    if (right != -1 && !visited[right]) {
      dq.push_back(right);
    }

    if (left != -1 && !visited[left]) {
      dq.push_back(left);
    }
  }

  cout << "\n";

  // mid traverse

  visited.assign(n, false);
  visited[0] = true;
  dq.push_back(0);

  parent.clear();
  child.clear();
  has_parent.assign(n, false);

  while (!dq.empty()) {
    int now = dq.front();
    char now_char = static_cast<char>(now + 'A');
    dq.pop_front();

    int left = get<0>(v[now]);
    char left_char = static_cast<char>(left + 'A');
    int right = get<1>(v[now]);
    char right_char = static_cast<char>(right + 'A');

    if (left != -1 && !visited[left]) {
      visited[left] = true;
      dq.push_back(left);
      if (parent[now_char]) {
        child[parent[now_char]] = left_char;
        parent[left_char] = parent[now_char];
        has_parent[left] = true;
      }
      child[left_char] = now_char;
      parent[now_char] = left_char;
      has_parent[now] = true;
    }

    if (right != -1 && !visited[right]) {
      visited[right] = true;
      dq.push_back(right);
      if (child[now_char]) {
        parent[child[now_char]] = right_char;
        child[right_char] = child[now_char];
        has_parent[child[now_char] - 'A'] = true;
      }
      child[now_char] = right_char;
      parent[right_char] = now_char;
      has_parent[right] = true;
    }
  }

  char start = 0;
  for (int i = 0; i < n; ++i) {
    if (!has_parent[i]) {
      start = static_cast<char>(i + 'A');
      break;
    }
  }

  cout << start;
  while (child[start] != 0) {
    cout << child[start];
    start = child[start];
  }
  cout << "\n";

  // backward traverse

  visited.assign(n, false);
  visited[0] = true;
  dq.push_back(0);

  parent.clear();
  child.clear();
  has_parent.assign(n, false);

  while (!dq.empty()) {
    int now = dq.front();
    char now_char = static_cast<char>(now + 'A');
    dq.pop_front();

    int left = get<0>(v[now]);
    char left_char = static_cast<char>(left + 'A');
    int right = get<1>(v[now]);
    char right_char = static_cast<char>(right + 'A');

    if (left != -1 && !visited[left]) {
      visited[left] = true;
      dq.push_back(left);
      if (parent[now_char]) {
        child[parent[now_char]] = left_char;
        parent[left_char] = parent[now_char];
        has_parent[left] = true;
      }
      child[left_char] = now_char;
      parent[now_char] = left_char;
      has_parent[now] = true;
    }

    if (right != -1 && !visited[right]) {
      visited[right] = true;
      dq.push_back(right);
      if (parent[now_char]) {
        child[parent[now_char]] = right_char;
        parent[right_char] = parent[now_char];
        has_parent[right] = true;
      }
      child[right_char] = now_char;
      parent[now_char] = right_char;
      has_parent[now] = true;
    }
  }

  start = 0;
  for (int i = 0; i < n; ++i) {
    if (!has_parent[i]) {
      start = static_cast<char>(i + 'A');
      break;
    }
  }

  cout << start;
  while (child[start] != 0) {
    cout << child[start];
    start = child[start];
  }
  cout << "\n";

  return 0;
}