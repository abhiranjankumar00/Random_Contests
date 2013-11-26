//Name         : Shinchan Nohara//{{{
//Age          : 5 years
//Organisation : Kasukabe Defense Force

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;//}}}

class Main
{
  static void backtrack(int id, char cur[], String[] keys) {
    if(id == keys.length) {
      for(int i = 0; i < cur.length; i++)
        System.out.print(cur[i]);
      System.out.println("");
      return;
    }

    for(int j = 0; j < keys[id].length(); j++) {
      cur[id] = keys[id].charAt(j);
      backtrack(id+1, cur, keys);
    }
  }

  static void solve(String []keys) {
    char cur[] = new char[keys.length];
    backtrack(0, cur, keys);
  }

	public static void main(String [] args) throws Exception
  {
    String keys[] = {"abc", "def", "ghi"};
    solve(keys);
  }
}

