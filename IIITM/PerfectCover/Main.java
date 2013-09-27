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
	public static void main(String [] args) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		Scanner s = new Scanner(System.in);

		final int sz = (int)1e6 + 10;
		final int mod = (int)1e8 + 7;

		int F[] = new int[sz];
		F[1] = 1;
		F[2] = 2;

		for(int i = 3; i < sz; i++)
			F[i] = (F[i-1] + F[i-2]) % mod;

		int T = s.nextInt();
//		int T = Integer.parseInt(br.readLine());

		while((T--) > 0) {
//			int n = Integer.parseInt(br.readLine());
			int n = s.nextInt();
			System.out.println(F[n]);
		}
	}
}

