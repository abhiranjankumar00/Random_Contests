/*  LOGIC
 *  For each node, find the two children with greatest heights.
 *  Add these heights to get the largest path, with one bend, which
 *  passess through (or bends at) current node.
 *  Do this for each node recursively.
*/
import java.io.*;
import java.util.*;
import java.math.*;

class Solution
{
  static void dfs(int nd, int []height, int par, Integer ans, List<List<Integer>> neigh) {
    height[nd] = 0;
    List <Integer> lst = neigh.get(nd);

    int mx1 = 0, mx2 = 0;

    for(int i = 0; i < lst.size(); i++) if(lst.get(i) != par) {
      int v = lst.get(i);
      dfs(v, height, nd, ans, neigh);
      int ht = height[v]+1;

      if(ht >= mx1) {
        mx2 = mx1;
        mx1 = ht;
      }
      else if(ht >= mx2){
        mx2 = ht;
      }

      height[nd] = Math.max(height[nd], ht);
    }
    ans = Math.max(ans, mx2+mx1);
  }

  public static void main(String [] args) throws Exception
  {
    initShinChanNohara();

    int numOfNodes = getInt();
    int root = getInt();
    int height[] = new int[numOfNodes];
    Arrays.fill(height, 0);
    List<List<Integer> > neigh = new ArrayList< List<Integer> >(numOfNodes);

    for(int i = 0; i < numOfNodes; i++) {
      neigh.set(i, new ArrayList<Integer>());
    }

    for(int i = 0; i < numOfNodes-1; i++) {
      int u = getInt();
      int v = getInt();

      List<Integer> lst = neigh.get(u);
      lst.add(v);

      lst = neigh.get(v);
      lst.add(u);
    }

    Integer ans = 0;
    dfs(root, height, -1, ans, neigh);
    

  }

//================================================================
  static BufferedReader br;//{{{
  static StringTokenizer strTok;

  static void initShinChanNohara() {
    br = new BufferedReader(new InputStreamReader(System.in));
    strTok = null;
  }

  static void initShinChanNohara(String file) {
    try {
      br = new BufferedReader(new FileReader(file));
      strTok = null;
    }
    catch(FileNotFoundException e) {
      writeln(e);
    }
  }

  static String getLine() {
    try {
      String st = br.readLine();
      return st;
    }
    catch(IOException e) {
      return null;
    }

  }

  static String getToken() {
    while(strTok == null || strTok.hasMoreTokens() == false) {
      String st = getLine();
      if(st == null)
        return null;
      strTok = new StringTokenizer(st);
    }
    return strTok.nextToken();
  }

  static int getInt() {
    return Integer.parseInt(getToken()); 
  }
  static double getDouble() {
    return Double.parseDouble(getToken());
  }
  static long getLong() {
    return Long.parseLong(getToken());
  }

  static void write(Object ... ob) {
    for(int i = 0; i < ob.length; i++) {
      if(i > 0)
        System.out.print(" ");
      System.out.print(ob[i]);
    }
  }
  static void writeln(Object ... ob) {
    write(ob);
    System.out.println();
  }
  static void debug(Object ... ob) {
    System.out.println(Arrays.deepToString(ob));
  }//}}}
}

