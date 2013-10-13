import java.io.*;
import java.util.*;
public class Solution {

  static int binarySearch(int l, int r, int val, List<Integer> lst) {
    if(l == r) {
      if(lst.get(l) >= val)
        return lst.get(l);
      else
        return -1;
    }
    int mid = (l+r)/2;
    if(lst.get(mid) >= val)
      return binarySearch(l, mid, val, lst);
    else
      return binarySearch(mid+1, r, val, lst);
  }

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

  public static void main(String args[] ) throws Exception {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int test_cases;
    test_cases = Integer.parseInt(br.readLine());
    for(int i = 0; i<test_cases; i++)
      solution_first();
  }

  public static void solution_first() throws Exception{
    Map<Character, List<Integer>> position = new HashMap<Character, List<Integer>>();
    String str = br.readLine();
    List<Integer> list = null;

    for(int i = 0;i < str.length(); i++)
    {
      if(position.containsKey(str.charAt(i)))
      {
        list = position.get(str.charAt(i));
        list.add(i);
        position.put(str.charAt(i), list);
      }
      else
      {
        list = new ArrayList<Integer>();
        list.add(i);
        position.put(str.charAt(i), list);
      }
    }

    int n = Integer.parseInt(br.readLine());

    for(int i = 0; i < n; i++)
    {
      int left = -1, right = -1;
      String order = br.readLine();
      int len_order = order.length();

      for(int j = 0; j < len_order; j++)
      {
        if(!position.containsKey(order.charAt(j)))
        {
          System.out.println("-1");
          return;
        }
      }

      List<Integer> ord = position.get(order.charAt(0));

      for(int k = 0; k < ord.size(); k++)
      {
        int lt = ord.get(k), rt = ord.get(k);
        int j;
        for(j = 1; j <= len_order-1; j++)
        {
          List<Integer> temp = position.get(order.charAt(j));

          int pos = binarySearch(0, temp.size()-1, rt+1, temp);
          if(pos == -1)
            break;
          rt = pos;
        }

        if( j== len_order) {
          if(left == -1) {
            left = lt;
            right = rt;
          }
          else if(rt - lt < right - left) {
            left = lt;
            right = rt;
          }
        }
      }

      if(left ==-1) {
        System.out.println(-1);
      }
      else {
        left++;
        right++;
        System.out.println(left+","+right);
      }
    }

  }
}
