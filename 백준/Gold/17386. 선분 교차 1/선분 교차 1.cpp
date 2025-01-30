// https://mathworld.wolfram.com/Line-LineIntersection.html

#include <bits/stdc++.h>
using namespace std;

constexpr double kEpsilon = 0.00000001;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto is_zero = [](double d) { return fabs(d) < kEpsilon; };
  auto in_segment = [](double x, double y, double x1, double y1, double x2,
                       double y2) {
    if (x < min(x1, x2) - kEpsilon || x > max(x1, x2) + kEpsilon) {
      return false;
    }

    if (y < min(y1, y2) - kEpsilon || y > max(y1, y2) + kEpsilon) {
      return false;
    }

    return true;
  };

  double x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

  array<array<double, 3>, 2> line;
  line[0] = {y2 - y1, x1 - x2, x2 * y1 - x1 * y2};
  line[1] = {y4 - y3, x3 - x4, x4 * y3 - x3 * y4};
  double determinant = line[0][0] * line[1][1] - line[1][0] * line[0][1];

  if (is_zero(determinant)) {
    double on_line = line[0][0] * x3 + line[0][1] * y3 + line[0][2];
    if (!is_zero(on_line)) {
      cout << 0;
      return 0;
    }

    bool on_x = (max(x1, x2) >= min(x3, x4) - kEpsilon) &&
                (max(x3, x4) >= min(x1, x2) - kEpsilon);
    bool on_y = (max(y1, y2) >= min(y3, y4) - kEpsilon) &&
                (max(y3, y4) >= min(y1, y2) - kEpsilon);

    if (on_x && on_y) {
      cout << 1;
    } else {
      cout << 0;
    }
  } else {
    double x =
        (line[0][1] * line[1][2] - line[1][1] * line[0][2]) / determinant;
    double y =
        (line[0][2] * line[1][0] - line[1][2] * line[0][0]) / determinant;

    if (in_segment(x, y, x1, y1, x2, y2) && in_segment(x, y, x3, y3, x4, y4)) {
      cout << 1;
    } else {
      cout << 0;
    }
  }

  return 0;
}