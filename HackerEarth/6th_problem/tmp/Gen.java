//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

class Gen
{
	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();
		int N, M;

		N = getInt();
		M = getInt();
		ArrayList < ArrayList <Integer > > child = new ArrayList <ArrayList<Integer> > (N);
		HashSet <Integer> hs = new HashSet <Integer>();
		int par[] = new int[N];

		Arrays.fill(par, -2); par[0] = -1;
		Queue <Integer> q = new Queue<Integer> ();
		hs.add(0);

		for(int i = 0; i < N && hs.size() < N; i++) {
			
		}
	}

//================================================================
	static BufferedReader br;
	static StringTokenizer strTok;
	static Random rndOb = new Random();

	static int getRnd(int N) {
		return Math.abs(rndOb.nextInt()) % N;
	}

	static void initShinChanNohara() {
		br = new BufferedReader(new InputStreamReader(System.in));
		rndOb = new Random();
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

