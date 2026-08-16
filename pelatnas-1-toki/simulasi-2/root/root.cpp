#include "root.h"	
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define vi vector<int>
#define pb push_back

int findRoot(int H) {
	int ans;
  for(int i = 1; i <= (1 << H) - 1; i++){
    vi anstmp = getNeighbours(i);
    if(anstmp.size() == 2){
        ans = i;
    }
  }
  return ans;
}