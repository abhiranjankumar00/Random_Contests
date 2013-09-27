//-----------
//----lost---
//-----------

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

class Main
{
	static int V, M;
	static int S[], mx[][], cnt[][];

	public static void main(String [] args) throws Exception
	{
		st = new StringTokenizer(br.readLine());

		S = new int[555];
		mx = new int[555][1111];
		cnt = new int[555][1111];
		int test = getInt();

		while(test-- > 0) {
			for(int [] rows: mx)
				Arrays.fill(rows, 0);
			for(int [] rows: cnt)
				Arrays.fill(rows, -1);
			cnt[0][0] = 0;

			V = getInt();
			M = getInt();

			for(int i = 0; i < V; i++)
				S[i] = getInt();

			for(int i = 0; i < V; i++) {
				for(int j = 0; j < M; j++) if(cnt[i][j] > -1) {
					if(cnt[i][j] > cnt[i+1][j]) {
						cnt[i+1][j] = cnt[i][j];
						mx[i+1][j] = mx[i][j];
					}
					else if(cnt[i][j] == cnt[i+1][j] ) {
						mx[i+1][j] = Math.max(mx[i+1][j], mx[i][j]);
					}

					int sum = (j + S[i]) % M;
					if(cnt[i][j] + 1 > cnt[i+1][sum]) {
						cnt[i+1][sum] = cnt[i][j] + 1;
						mx[i+1][sum] = mx[i][j] + S[i];
					}
					else if(cnt[i][j] + 1 == cnt[i+1][sum]) {
						mx[i+1][sum] = Math.max(mx[i+1][sum], mx[i][j] + S[i]);
					}
				}
			}
			System.out.println(cnt[V][0] + " " + mx[V][0]/M);

		}
	}

	static StringTokenizer st;
	static BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
	static int getInt() throws Exception {

		while(st.hasMoreTokens() == false)
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}

