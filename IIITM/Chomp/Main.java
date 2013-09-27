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
	static final int sz = 111;
	static int [][][] dp = new int [sz][sz][sz];
	static final int P = 0, N = 1;

	static int PN(int row1, int row2, int row3) {
		assert(row1 >= 0 && row1 <= 35);
		assert(row2 >= 0 && row2 <= row1);
		assert(row3 >= 0 && row3 <= row2);

		if(dp[row1][row2][row3] > -1)
			return dp[row1][row2][row3];

		for(int r3 = row3-1; r3 >= 0; r3--)
			if(PN(row1, row2, r3) == P)
				return dp[row1][row2][row3] = N;

		for(int r2 = row2-1; r2 >= 0; r2--)
			if(PN(row1, r2, Math.min(r2, row3)) == P)
				return dp[row1][row2][row3] = N;

		for(int r1 = row1-1; r1 >= 0; r1--)
			if(PN(r1, Math.min(r1, row2), Math.min(r1, row3)) == P)
				return dp[row1][row2][row3] = N;

		return dp[row1][row2][row3] = P; 
	}

	public static void main(String [] args) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		Scanner scn = new Scanner(System.in);

		for(int i = 0; i < sz; i++)
			for(int j = 0; j < sz; j++)
				for(int k = 0; k < sz; k++)
					dp[i][j][k] = -1;
		dp[0][0][0] = N;
		dp[1][0][0] = P;

		int T = scn.nextInt();
//		int T = Integer.parseInt(br.readLine());

		assert(T > 0 && T <= (int)1e4);
//		System.out.println(T);
		
		while((T--) > 0) {
/*
			String []s = br.readLine().split(" ");
			int row1 = Integer.parseInt(s[0]);
			int row2 = Integer.parseInt(s[1]);
			int row3 = Integer.parseInt(s[2]);
*/
			int row1 = scn.nextInt();
			int row2 = scn.nextInt();
			int row3 = scn.nextInt();

			assert(0 <= row1 && row1 <= 35);
			assert(0 <= row3 && row3 <= row2 && row2 <= row1);
//			System.out.println(row1 + " " + row2 + " " + row3);
			System.out.println((PN(row1, row2, row3) == N ? "WIN" : "LOSE"));
		}


	}
}

