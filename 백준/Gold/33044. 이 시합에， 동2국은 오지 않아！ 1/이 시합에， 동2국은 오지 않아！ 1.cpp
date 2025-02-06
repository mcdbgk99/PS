#include <bits/stdc++.h>
using namespace std;

int64_t FastExp(int64_t base, int64_t exp) {
  int64_t result = 1;

  while (exp) {
    if (exp & 1) {
      result *= base;
    }
    base *= base;
    exp >>= 1;
  }

  return result;
}

constexpr int kMaxFact = 36;
array<int64_t, kMaxFact + 1> fact;

void BuildFactorialTable() {
  fact[0] = 1;
  for (int i = 1; i <= kMaxFact; ++i) {
    fact[i] = fact[i - 1] * i;
  }
}

int64_t Combination(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }

  return fact[n] / (fact[k] * fact[n - k]);
}

void DivideBlockRecursion(vector<int>& hand, int& current_solution,
                          bool& solved) {
  if (current_solution == 5) {
    solved = true;
    return;
  }

  int index = -1;
  for (int i = 0; i < hand.size(); ++i) {
    if (hand[i] > 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    return;
  }

  if (hand[index] >= 3) {
    hand[index] -= 3;
    ++current_solution;
    DivideBlockRecursion(hand, current_solution, solved);
    --current_solution;
    hand[index] += 3;

    if (solved) {
      return;
    }
  }

  if (index <= 7 && hand[index] > 0 && hand[index + 1] > 0 &&
      hand[index + 2] > 0) {
    --hand[index];
    --hand[index + 1];
    --hand[index + 2];
    ++current_solution;
    DivideBlockRecursion(hand, current_solution, solved);
    --current_solution;
    ++hand[index];
    ++hand[index + 1];
    ++hand[index + 2];
  }
}

bool DivideTiles(vector<int>& hand) {
  for (int i = 1; i <= 9; ++i) {
    if (hand[i] >= 2) {
      hand[i] -= 2;

      int solution = 1;
      bool solved = false;
      DivideBlockRecursion(hand, solution, solved);

      hand[i] += 2;

      if (solved) {
        return true;
      }
    }
  }

  return false;
}

bool CheckSevenPairs(vector<int>& hand) {
  int pair_count = 0;

  for (int i = 1; i <= 9; ++i) {
    if (hand[i] == 2) {
      ++pair_count;
    }
  }

  return pair_count == 7;
}

bool IsWinHand(vector<int>& hand) {
  if (CheckSevenPairs(hand)) {
    return true;
  }

  if (DivideTiles(hand)) {
    return true;
  }

  return false;
}

void Dfs(vector<int>& deck, vector<int>& hand, int deck_index, int hand_index,
         int64_t& solution) {
  if (deck_index == 10) {
    if (hand_index == 14 && IsWinHand(hand)) {
      int64_t combination = 1;
      for (int i = 1; i <= 9; ++i) {
        combination *= Combination(deck[i], hand[i]);
      }

      solution += combination;
    }

    return;
  }

  for (int i = 0; i <= deck[deck_index]; ++i) {
    if (hand_index + i > 14) {
      break;
    }

    hand[deck_index] = i;
    Dfs(deck, hand, deck_index + 1, hand_index + i, solution);
    hand[deck_index] = 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  BuildFactorialTable();

  int n;
  cin >> n;

  vector<int> deck(10, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++deck[x];
  }

  vector<int> hand(10, 0);
  int64_t result = 0;
  Dfs(deck, hand, 1, 0, result);

  cout << result;

  return 0;
}