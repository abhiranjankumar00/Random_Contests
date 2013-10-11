import java.io.*;

class Merge
{
	public static void main(String [] args) throws Exception
	{

    int[] a = {1, 4, 6, 7, 11, 44, 64};
    int[] b = {3, 5, 7, 33, 56, 102};
    int n = a.length;
    int m = b.length;

    int [] ans = new int [n+m];

    int aIdx = 0, bIdx = 0, idx = 0;

    while(aIdx < a.length && bIdx < b.length) {
      if(a[aIdx] < b[bIdx]) 
        ans[idx++] = a[aIdx++];
      else
        ans[idx++] = b[bIdx++];
    }

    while(aIdx < a.length)
      ans[idx++] = a[aIdx++];
    while(bIdx < b.length)
      ans[idx++] = b[bIdx++];

    for(int v: a)
      System.out.print(v + " ");
    System.out.println("");

    for(int v: b)
      System.out.print(v + " ");
    System.out.println("");

    for(int v: ans)
      System.out.print(v + " ");
    System.out.println("");
	}
}

