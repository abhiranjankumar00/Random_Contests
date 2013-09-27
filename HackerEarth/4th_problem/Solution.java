//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

class Solution
{
	static Integer array[];

	static int binarySearch(int val, int l, int r ) {
		if(l == r)
			return array[l];

		int mid = (l+r+1)/2;

		if(array[mid] > val)
			return binarySearch(val, l, mid-1);
		else
			return binarySearch(val, mid, r);
	}

	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();
		int C = getInt(), N = getInt();
		array = new Integer[N];

		for(int i = 0; i < N; i++)
			array[i] = getInt();

		Arrays.sort(array);
/*
		debug(C, N);
		for(int i = 0; i < N; i++)
			write(array[i], "");
		writeln("");
*/
		if(array[0] != 1) {
			writeln(-1);
			return;
		}

		int mx = 0;
		int ans = 0;

		while(mx < C) {
			ans ++;
			int val = binarySearch(mx+1, 0, N-1);
			mx += binarySearch(mx+1, 0, N-1);
//			debug(val, mx);
		}
//		debug();
		writeln(ans);
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



