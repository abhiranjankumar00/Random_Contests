
import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class Solution
{
	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();
    int R, k, N;
    R = getInt();
    k = getInt();
    N = getInt();

    long [] g = new long [N];
  
    for(int i = 0; i < N; i++) {
      g[i] = getLong();
    }

    int idx = 0;
    long sum = 0;

    for(int i = 0; i < R; i++) {
      int begin = idx;
      long curSum = g[begin];
      idx = (idx+1)%N;

      while(true) {
        if(idx == begin)
          break;
        if(curSum + g[idx] > k)
          break;
        curSum += g[idx];
        idx = (idx+1)%N;
      }
      sum += curSum;
    }
    writeln(sum);
	}

//================================================================
	static BufferedReader br;//{{{
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
	}//}}}
}

