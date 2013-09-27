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

	boolean checkRow(String []game, char p ) {
		for(int i = 0; i < 4; i++) {
			boolean flag = true;
			for(int j = 0; j < 4; j++)
				flag &= (game[i].charAt(j) == p || game[i].charAt(j) == 'T');
			if(flag == true)
				return true;
		}
		return false;
	}
	boolean checkCol(String []game, char p ) {
		for(int j = 0; j < 4; j++) {
			boolean flag = true;
			for(int i = 0; i < 4; i++)
				flag &= (game[i].charAt(j) == p || game[i].charAt(j) == 'T');
			if(flag == true)
				return true;
		}
		return false;
	}

	boolean checkDiag(String[] game, char p) {
		boolean flag1 = true;
		for(int i = 0; i < 4; i++) 
			if(game[i].charAt(i) == p || game[i].chatAt(i) == 'T')
				flag1 = false;
		
		boolean flag2 = true;
		for(int i = 0; i < 4; i++)
			if(game[i].charAt(3-i) == p || game[i].charAt(3-i) == 'T')
				flag2 = false;
		return flag1 && flag2;
	}

	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();
		int test = getInt();

		for(int t = 1; t <= test; t++) {
			String game[] = new String[4];
			for(int i = 0; i < 4; i++)
				game[i] = getLine();
			debug(game, "");
			if(t < test)
				getLine();
		}

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

