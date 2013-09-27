import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.net.*;

class Client
{
	public static void main(String [] args) throws Exception
	{
		Socket s = new Socket("localhost", 5513);

		BufferedReader is;
		is = new BufferedReader(new InputStreamReader(s.getInputStream()));
		PrintWriter os = new PrintWriter(s.getOutputStream(), true);

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		while(true) {
			System.out.println("Enter your input: ");
			System.out.println(" 1. Launch a Browser");
			System.out.println(" 2. Kill current Browser");
			System.out.println(" 3. Restore original settings in a browser");
			System.out.println("-1. Exit");

			int op = Integer.parseInt(br.readLine());
			os.println(new Integer(op).toString());

			if(op == -1)
				break;


			if(op == 1 || op == 3) {
				System.out.println("Browser Option:");
				System.out.println("1. Firefox");
				System.out.println("2. Chrome");
				System.out.println("3. Opera");
				int browser =  Integer.parseInt(br.readLine());
				os.println(new Integer(browser).toString());
			}
			String msg = is.readLine();
			System.out.println(msg + "\n");
			System.out.println("");

		}

		is.close();
		os.close();
		s.close();
	}
}

