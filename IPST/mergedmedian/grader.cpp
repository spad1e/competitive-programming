#include "mergedmedian.h"
#include <algorithm>

static std::vector<long long> a, b;
static int n;
static int count;

void fail(std::string s) {
  std::cerr << s << std::endl;
  exit(1);
}

long long alice(int i) {
  if (i < 0 || i > n)
    fail("index out of bound");
  count++;
  if (count > 300000)
    fail("too many questions");
  return a[i];
}
long long bob(int i) {
  if (i < 0 || i >= n)
    fail("index out of bound");
  count++;
  if (count > 300000)
    fail("too many questions");
  return b[i];
}

int main() {
  std::cin >> n;
  count = 0;
  for (int i = 0; i <= n; i++) {
    long long x;
    std::cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    long long x;
    std::cin >> x;
    b.push_back(x);
  }
  long long mm = find_merged_median(n);
  std::cout << mm << std::endl << count << std::endl;
  return 0;
}