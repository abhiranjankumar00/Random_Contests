//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

class A
{
	static ArrayList<Integer> filter(String st1) {
		char st2[] = st1.toLowerCase().toCharArray();
		Arrays.sort(st2);
		ArrayList <Character> st = new ArrayList <Character>();
		for(char x: st2)
			if(x >= 'a' && x <= 'z')
				st.add(x);

		ArrayList <Integer> ret = new ArrayList<Integer> ();
		ret.add(1);
		for(int i = 1; i < st.size(); i++) {
			if(st[i] == st[i-1]) {
				int lst = ret.get(ret.size()-1);
				ret.set(ret.size()-1, lst+1);
			}
			else
				ret.add(1);
		}
		Arrays.sort(ret);

		return ret;
	}
	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();
		int Test = getInt();
		writeln(Test);

		for(int test = 1; test <= Test; test++) {
			String st = getLine();
			writeln("Case", test, st);

			ArrayList <Integer> group = filter(st);
		}

	}

//================================================================
	static BufferedReader br;
	static StringTokenizer strTok;

	static void initShinChanNohara() {
		br = new BufferedReader(new InputStreamReader(System.in));
		strTok = null;
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
}


