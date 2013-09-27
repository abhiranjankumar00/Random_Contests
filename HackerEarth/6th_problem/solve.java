//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

class Main
{
	int ans = -1;
	int N, M;
	HashSet<Integer> U;
	ArrayList < ArrayList <Integer> > G;

	int dfs(int u) {
		int ret = 0;
		if(U.contains(u))
			ret++;
		for(int i = 0; i < G.get(u).size(); i++)
			ret += dfs(G.get(u).get(i));
		if(ans == -1 && ret == M)
			ans = u;
		return ret;
	}

	void solve() throws Exception {
		N = getInt();

		U = new HashSet<Integer> ();
		G = new ArrayList < ArrayList<Integer> >();
		for(int i = 0; i < N; i++) {
			G.add(new ArrayList<Integer>());
		}

		for(int i = 1; i <= N-1; i++) {
			int u = getInt();
			G.get(u).add(i);
		}

		M = getInt();
		for(int i = 0; i < M; i++) {
			int u = getInt();
			U.add(u);
		}
		dfs(0);
		writeln(ans);
	}

	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();
		new Main().solve();
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

