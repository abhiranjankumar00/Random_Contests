//-----------
//----lost---
//-----------

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

class tmp
{
	static int V, M;
	static int S[], sum[][], countVariety[][];
	static BufferedReader br ;

	static int solve(int n, int k) {
		if(n == 0)
			return k == 0 ? 0 : -2;

		if(countVariety[n][k] != -1)
			return countVariety[n][k];
		
		countVariety[n][k] = solve(n-1, k);
		sum[n][k] = sum[n-1][k];

		int preIdx = (k - S[n]) % M;
		preIdx = (preIdx + M) % M;
		
		int tmpAns = solve(n-1, preIdx);
		if(tmpAns == -2)
			return countVariety[n][k];

		if(tmpAns + 1 > countVariety[n][k]) {
			countVariety[n][k] = tmpAns+1;
			sum[n][k] = sum[n-1][preIdx] + S[n];
		}
		else if(tmpAns+1 == countVariety[n][k]) {
			sum[n][k] = Math.max(sum[n][k], sum[n-1][preIdx] + S[n]);
		}

		return countVariety[n][k];
	}

	public static void main(String [] args) throws Exception
	{
		br = new BufferedReader (new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());

		int test = getInt();
		S = new int[555];
		countVariety = new int[555][1111];
		sum = new int[555][1111];

		while(test-- > 0) {
			for(int [] rows: sum)
				Arrays.fill(rows, 0);
			for(int [] rows: countVariety)
				Arrays.fill(rows, -1);

			V = getInt();
			M = getInt();

			for(int i = 1; i <= V; i++)
				S[i] = getInt();

			System.out.println(solve(V, 0) + " " + sum[V][0]/M);
		}
	}

	static StringTokenizer st;

	static int getInt() throws Exception {
		while(st.hasMoreTokens() == false) {
			st = new StringTokenizer(br.readLine());
		}
		return Integer.parseInt(st.nextToken());

	}
}

