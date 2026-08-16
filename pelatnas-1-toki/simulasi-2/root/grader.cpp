#include "root.h"

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

static int H;
static int Q;
static std::vector<std::vector<int> > N;
static int queries = 0;

void WA() {
  puts("WA");
  exit(0);
}

std::vector<int> getNeighbours(int X) {
  if (++queries > Q) {
    WA();
  }
  if (X < 1 || X > (1 << H) - 1) {
    WA();
  }
  std::sort(N[X].begin(), N[X].end());
  return N[X];
}

int main() {
  int T;
  scanf("%d", &T);
  while (T-- > 0) {
    queries = 0;
    scanf("%d %d", &H, &Q);
    N.resize(1 << H);
    for (int i = 0; i < N.size(); ++i) {
      N[i].clear();
    }
    for (int i = 0; i < (1 << H) - 2; ++i) {
      int A, B;
      scanf("%d %d", &A, &B);
      N[A].push_back(B);
      N[B].push_back(A);
    }
    printf("%d\n", findRoot(H));
  }
}



