#include <cstdio>
#include <algorithm>

#include <vector>

using namespace std;

int n, s;
vector<int> num_list;

bool check(int mid)
{
 int count = 1;
 int curr = num_list[0];

 for (int v : num_list)
 {
  if (v >= curr + mid)
  {
   curr = v;

   count++;
   if (count == s)
   {
    return true;
   }
  }
 }

 return false;
}

int binary_search(int lo, int hi)
{
 int result = lo;
 while (hi - lo >= 2)
 {
  int mid = (lo + hi) / 2;

  if (!check(mid))
  {
   hi = mid;
  }
  else
  {
   lo = mid;
  }
 }

 for (int x = hi; x >= lo; x--)
 {
  if (check(x))
  {
   result = x;
   break;
  }
 }

 return result;
}

int main()
{
 int T;
 scanf("%d", &T);

 while (T--)
 {
  scanf("%d %d", &n, &s);

  num_list.assign(n, 0);

  for (int i = 0; i < n; i++)
  {
   scanf("%d", &num_list[i]);
  }

  sort(num_list.begin(), num_list.end());

  printf("%d\n", binary_search(1, num_list[n - 1] - num_list[0]));
 }

 return 0;
}