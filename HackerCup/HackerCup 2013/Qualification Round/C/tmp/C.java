//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

class C 
{
	int singleTree[], multipleTree[];
	final int sz = (int)1e5 + 111;
	int []arr, period;
	int N, K;

	void updateFreq(int idx, int val, int [] tree) {
		while(idx < sz) {
			tree[idx] += val;
			idx += idx & (-idx);
		}
	}
	int cumFreq(int idx, int [] tree) {
		int ret = 0;
		while(idx > 0) {
			ret += tree[idx];
			idx -= idx & (-idx);
		}
		return ret;
	}
	int freq(int idx, int []tree) {
		return cumFreq(idx, tree) - cumFreq(idx-1, tree); 	
	}

	int binarySearch(int l, int r) {
		if(l == r)
			return l;
		int mid = (l+r)/2;
		int f = cumFreq(mid+1, singleTree);

		if(f == mid+1)
			return binarySearch(mid+1, r);
		else
			return binarySearch(l, mid);
	}

	void manageFreq(int id, int val) {
		if(id < 0 || id >= sz)
			return;
		updateFreq(id, val, multipleTree);
		int f = freq(id, multipleTree);
		if(val == 1 && f == 1)
			updateFreq(id, +1, singleTree);
		else if(val == -1 && f == 0)
			updateFreq(id, -1, singleTree);
	}

	void solve(int test) {
		singleTree = new int[sz];
		multipleTree = new int[sz];
		long b, c, r;

		N = getInt();
		K = getInt();
		arr = new int[K];
		period = new int[K+1];

		arr[0] = getInt();
		manageFreq(arr[0] + 1, +1);
		b = getLong();
		c = getLong();
		r = getLong();

		for(int i = 1; i < K; i++) {
			arr[i] = (int) ( (arr[i-1]*b + c)%r );
			arr[i] = (int)((arr[i] + r) % r);
			manageFreq(arr[i]+1, +1);
		}

		period[0] = binarySearch(0, (int)1e5 + 11);

		for(int i = 1; i <= K; i++) {
			manageFreq(arr[i-1] + 1, -1);
			manageFreq(period[i-1] + 1, +1);
			period[i] = binarySearch(0, (int)1e5 + 11);
		}

		N = N - K - 1;
		System.out.println("Case #" + test + ": " + period[N%(K+1)]);
	}

	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();

		int T = getInt();

		for(int test = 1; test <= T; test++)
			new C().solve(test);
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


