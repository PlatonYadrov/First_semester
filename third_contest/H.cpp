#include <iostream>

int Ans(int m, int prefix, int max_pow, int* pows, int* pows_prefs);

int Weights(int m, int prefix, int max_pow, int* pows, int* pows_prefs) {
  if (max_pow < 0 || prefix - pows_prefs[max_pow] > m) {
    if (prefix <= m) {
      return 1;
    }
    return 0;
  }
  if (prefix + pows_prefs[max_pow] <= m) {
    int pow = 1;
    for (int i = 0; i < max_pow + 1; ++i) {
      pow *= 3;
    }
    return pow;
  }
  return Ans(m, prefix, max_pow, pows, pows_prefs);
}

int Ans(int m, int prefix, int max_pow, int* pows, int* pows_prefs) {
  int answer = 0;
  answer += Weights(m, prefix - pows[max_pow], max_pow - 1, pows, pows_prefs);
  answer += Weights(m, prefix, max_pow - 1, pows, pows_prefs);
  answer += Weights(m, prefix + pows[max_pow], max_pow - 1, pows, pows_prefs);
  return answer;
}

void Update(int pows_prefs[100], int prefs[100], int pows[100]) {
  for (int i = 1; i < 100; ++i) {
    pows[i] = pows[i - 1] << 2;
    pows_prefs[i] = pows_prefs[i - 1] + pows[i];
    prefs[i] = prefs[i - 1] + prefs[i - 1] * 2 + 1;
  }
}

void MaxPow(int& max_pow, int m, int dp[100]) {
  int pow = 0;
  if (m == 0) {
    pow = 1;
  }
  int pos = 0;
  int temp = m;
  while (temp > 0) {
    dp[pos] = temp % 4;
    ++pow;
    temp /= 4;
    ++pos;
  }
  if (dp[pow - 1] > 1) {
    max_pow = pow;
  } else {
    max_pow = pow - 1;
  }
}

int Solution(int m, int n, int pows_prefs[100], int prefs[100], int pows[100], int dp[100]) {
  pows_prefs[0] = 1;
  prefs[0] = 1;
  pows[0] = 1;
  dp[0] = 0;
  Update(pows_prefs, prefs, pows);
  int max_pow;
  MaxPow(max_pow, m, dp);
  int answer;
  if (max_pow + 1 > n) {
    answer = prefs[n - 1];
  } else {
    answer = Weights(m, pows[max_pow], max_pow - 1, pows, pows_prefs);
    if (max_pow > 0) {
      answer += prefs[max_pow - 1];
    }
  }
  return answer;
}

int main() {
  int m, n;
  std::cin >> n >> m;
  int pows_prefs[100];
  int prefs[100];
  int pows[100];
  int dp[100];
  std::cout << Solution(m, n, pows_prefs, prefs, pows, dp);
  return 0;
}
