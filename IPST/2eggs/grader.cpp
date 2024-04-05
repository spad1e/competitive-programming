//#include "2eggs.h"
#include <bits/stdc++.h>

static int N, H, Q;
static int drop_count;
static bool active1, active2;

void fail(std::string s) {
  std::cerr << s << std::endl;
  exit(1);
}



bool drop_egg(int egg_number, int h) {
  if (h < 1 || h > N)
    fail("invalid height");
  if (egg_number < 1 || egg_number > 2)
    fail("invalid egg number");
  if (egg_number == 1) {
    if (!active1)
      fail("egg 1 is already broken");
  } else if (egg_number == 2) {
    if (!active2)
      fail("egg 2 is already broken");
  }
  drop_count++;
  if (h > H) {
    if (egg_number == 1)
      active1 = false;
    else if (egg_number == 2)
      active2 = false;
    return true;
  } else {
    return false;
  }
}

int drop2(int l, int r) {
    for (int i = l; i < r; ++i) {
        if (drop_egg(2, i)) return i;
    }
    return r;
}

int drop1(int l, int r) {
    int h = l + ceil(sqrt(r-l+1));
    if (h >= r) return drop2(l, r);
    if (drop_egg(1, h)) return drop2(l, h);
    return drop1(h+1, r);
}

int height_threshold (int N, int Q) {
    return drop1(1, N);
}


int main() {
  std::cin >> N >> H >> Q;
  drop_count = 0;
  active1 = active2 = true;
  int hp1 = height_threshold(N, Q);
  std::cout << hp1 << std::endl;
  std::cout << drop_count << std::endl;
  return 0;
}
