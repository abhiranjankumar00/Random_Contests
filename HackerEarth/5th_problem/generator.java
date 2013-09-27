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
	static void init(int []arr, Random obj) {
		for(int i = 0; i < arr.length; i++) {
			arr[i] = Math.abs(obj.nextInt()) % 10000 + 1;
			int sign = obj.nextInt();
			if(sign == 0)
				continue;
			sign /= Math.abs(sign);
			arr[i] *= sign;
		}
	}
	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();
		Random rnd = new Random();
		int t = Math.abs(rnd.nextInt()) % 10000 + 1;
		System.out.println(t);
		
		int bo_pts[] = new int[3], bo_vel[] = new int[3];
		int masao_pts[] = new int[3], masao_vel[] = new int[3];

		init(bo_pts, rnd);
		init(bo_vel, rnd);
		init(masao_pts, rnd);
		init(masao_vel, rnd);

		for(int x: bo_pts)
			write(x, "");
		System.out.println("");
		for(int x: bo_vel)
			write(x, "");
		System.out.println("");
		for(int x: masao_pts)
			write(x, "");
		System.out.println("");
		for(int x: masao_vel)
			write(x, "");
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

