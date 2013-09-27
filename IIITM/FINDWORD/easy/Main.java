//-----------
//----lost---
//-----------

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
/*
class node {
	public node child[] = new node[26];
	public  node() {
		for(int i = 0; i < 26; i++)
			child[i] = null;
	}
}
*/
class Main
{
	static int N;
	static String []s;
	static String st;

	static boolean find(int y, int x, int yadd, int xadd) {
		int idx = 0;	

		while(true) {
			if(idx == st.length())
				return true;
			if(x == N || y == N)
				return false;
			if(s[y].charAt(x) != st.charAt(idx))
				return false;
			y += yadd;
			x += xadd;
			idx++;
		}
	}

	public static void main(String [] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		s = new String[N];
		assert(N > 0 && N <= 50);

		for(int i = 0; i < N; i++)
			s[i] = br.readLine();

		int T = Integer.parseInt(br.readLine());
		assert(T > 0 && T <= 50);


		while((T--) > 0) {
			st = br.readLine().split(" ")[1];

			boolean isFound = false;

			for(int y = 0; y < N && !isFound; y++) {
				for(int x = 0; x < N && !isFound; x++) {
					isFound |= find(y, x, 1, 1);
					isFound |= find(y, x, 0, 1);
					isFound |= find(y, x, 1, 0);
				}
			}
			System.out.println((isFound ? "YES" : "NO"));
		}
	}
/*
	static void insert(int x, int y, int xadd, int yadd, node nd) {
		if(x == N || y == N)
			return;

		int id = (int)(s[y].charAt(x) - 'a');

		if(nd.child[id] == null)
			nd.child[id] = new node();

		insert(x + xadd, y + yadd, xadd, yadd, nd.child[id]);
	}

	static boolean find(int idx, String st, node nd) {
		if(idx == st.length())
			return true;

		int id = (int)(st.charAt(idx) - 'a');
		
		return nd.child[id] == null ? false : find(idx+1, st, nd.child[id]);
	}

	public static void main(String [] args) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		node root = new node();

		N = Integer.parseInt(br.readLine());

		s = new String[N];

		for(int i = 0; i < N; i++)
			s[i] = br.readLine();

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				insert(i, j, 1, 1, root);
				insert(i, j, 0, 1, root);
				insert(i, j, 1, 0, root);
			}
		}

		int T = Integer.parseInt(br.readLine()); 

		while((T--) > 0) {
			String k = br.readLine().split(" ")[1];
			
			System.out.println((find(0, k, root) ? "YES" : "NO"));
		}
	}
*/
}

