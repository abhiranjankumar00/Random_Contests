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

	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();

    String keys[] = {"abc", "def", "ghi"};
    int N = keys.length;
    char cur[] = new char[N];

    backtrack(0, cur, keys);

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

