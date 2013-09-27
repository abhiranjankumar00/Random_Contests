//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class Solution
{
	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();
		int N = getInt()+1;
		String [] buffer = new String[N+1];
		int l = 0, r = 0;

		for(char ch = getToken().charAt(0); ch != 'Q'; ch = getToken().charAt(0)) {
			if(ch == 'L') {
				for(int i = l; i != r; i = (i+1)%N)
					writeln(buffer[i]);
			}
			else if(ch == 'R') {
				int cnt = getInt();
				while(cnt-->0)
					l = (l+1)%N;
			}
			else { // ch == 'A'
				int cnt = getInt();
				while(cnt-->0) {
					String str = getToken();
					buffer[r] = str;
					r = (r+1)%N;
					if(r == l)
						l = (l+1)%N;
				}
			}
		}

	}

//================================================================
	static BufferedReader br;
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
	}
}

