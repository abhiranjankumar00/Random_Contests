//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

class Node implements Comparable
{

	int x, y, t;
	public int compareTo(Object ob) {
		Node nd = (Node) ob;
		return t - nd.t;
	}
	void set(int a, int b, int c) {
		x = a; y = b; this.t = c;
	}
	Node(int a, int b, int c) {
		set(a, b, c);
	}
	Node() {}
	public String toString() {
		return "(" + x + ", "  + y + ": " + t + ")";
	}

	static boolean valid(int id, int N) {
		return id >= 0 && id < N;
	}

	static void solve(int N, int M) {
		int D[][] = new int[N][];
		for(int i  =0 ; i < N; i++)
			D[i] = new int[M];
		boolean vis[][] = new boolean[N][];
		for(int i = 0; i < N; i++) {
			vis[i] = new boolean[M];
			Arrays.fill(vis[i], false);
		}

		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				D[i][j] = nextInt();
		int x = nextInt() - 1, y = nextInt() - 1, t = nextInt();

		int X[] = {1, -1, 0, 0};
		int Y[] = {0, 0, -1, 1};

		PriorityQueue <Node> pq = new PriorityQueue <Node>();

		pq.add(new Node(0, 0, D[0][0]));

		while(!pq.isEmpty()) {
			Node nd = pq.poll();

			if(nd.t > t)
				continue;

			if(nd.x == x && nd.y == y) {
				writeln("YES\n" + (t - nd.t));
				return;
			}

			if(vis[nd.x][nd.y])
				continue;
			vis[nd.x][nd.y] = true;

			for(int i = 0; i < 4; i++) {
				int xx = nd.x + X[i], yy = nd.y + Y[i];
				if(valid(xx, N) && valid(yy, M) && !vis[xx][yy] && nd.t + D[xx][yy] <= t) {
					pq.add(new Node(xx, yy, nd.t + D[xx][yy]));
				}
			}
		}

		writeln("NO");
	}

	public static void main(String [] args) throws Exception
	{
		br = new BufferedReader(new InputStreamReader(System.in));
		strTok = null;

		int test = nextInt();

		while(test --> 0) {
			int N = nextInt(), M = nextInt();
			new Node().solve(N, M);
		}

	}

	static BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
	static StringTokenizer strTok = null;

	static String nextLine() {
		try {
			String st = br.readLine();
			return st;
		}
		catch(IOException e) {
			return null;
		}

	}

	static String nextToken() {
		while(strTok == null || strTok.hasMoreTokens() == false) {
			String st = nextLine();
			if(st == null)
				return null;
			strTok = new StringTokenizer(st);
		}
		return strTok.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(nextToken()); 
	}
	static double nextDouble() {
		return Double.parseDouble(nextToken());
	}
	static long nextLong() {
		return Long.parseLong(nextToken());
	}

	static void write(Object ob) {
		System.out.print(ob.toString());
	}
	static void writeln(Object ob) {
		System.out.println(ob.toString());
	}
}
