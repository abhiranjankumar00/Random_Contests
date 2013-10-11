class array {
    int[] a = {1, 4, 6, 7, 11, 44, 64};
    int[] b = {3, 5, 7, 33, 56, 102};
    int n = a.length;
    int m = b.length;

    int aBegin = 0, bBegin = 0;
    int aEnd = n-1, bEnd = m-1;

    int first() {
      int ans = -1;
      if(aBegin <= aEnd && bBegin <= bEnd) {
          if(a[aBegin] < b[bBegin]) {
              ans = a[aBegin];
              aBegin++;
          }
          else {
              ans = b[bBegin];
              bBegin++;
          }
      }
      else if (aBegin <= aEnd) {
          ans = a[aBegin];
          aBegin++;
      }
      else if (bBegin <= bEnd) {
          ans = b[bBegin];
          bBegin++;
      }
      return ans; // returns -1 if all elements are traversed.
    }

    int last() {
      int ans = -1;
      if(aBegin <= aEnd && bBegin <= bEnd) {
          if(a[aEnd] > b[bEnd]) {
              ans = a[aEnd];
              aEnd--;
          }
          else {
              ans = b[bEnd];
              bEnd--;
          }
      }
      else if (aBegin <= aEnd) {
          ans = a[aEnd];
          aEnd--;
      }
      else if (bBegin <= bEnd) {
          ans = b[bEnd];
          bEnd--;
      }
      return ans;  // returns -1 if all elements are traversed.

    }
}

