class Solution {
  public:
  /*
  Return min number of rotations
  if one could make all elements in A or B equal to x.
  Else return -1.
  */
  int check(int x, vector<int>& A, vector<int>& B, int n) {
    // how many rotations should be done
    // to have all elements in A equal to x
    // and to have all elements in B equal to x
    int rotations_a = 0, rotations_b = 0;
    for (int i = 0; i < n; i++) {
      // rotations coudn't be done
      if (A[i] != x && B[i] != x)
          return -1;
      // A[i] != x and B[i] == x
      else if (A[i] != x)
          rotations_a++;                // make all elements in A equal x
      // A[i] == x and B[i] != x
      else if (B[i] != x)
          rotations_b++;                // make all elements in B equal x
    }
    // min number of rotations to have all
    // elements equal to x in A or B
    return min(rotations_a, rotations_b);
  }

  int minDominoRotations(vector<int>& A, vector<int>& B) {
    int n = A.size();
    // to make swap so that all value of the top/bottom returns equal values
    // only the first value A[0] or B[0] is needed to compare.
    int rotations = check(A[0], A, B, n);
    // If one could make all elements in A or B equal to A[0]
    if (rotations != -1 || A[0] == B[0]) return rotations;         // !!!!!!
    // if check(A[0], A, B, n) returns value, then we don't have to run check(B[0], A, B, n)
    // If one could make all elements in A or B equal to B[0]
    else return check(B[0], A, B, n);
  }
};