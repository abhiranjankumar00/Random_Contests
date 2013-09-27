import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.net.*;
import java.io.File;

class Server
{
	int port;
	ServerSocket s;
	BufferedReader is;

	String browsers[];
	PrintWriter os;
	String firefox = "firefox";

	String chrome = "google-chrome";

	String ie = "opera";

	File homedir = new File(System.getProperty("user.home"));
	String home = homedir.toString();
	String firefoxPath =  home + "/.mozilla/firefox";
	String chromePath = home + "/.config/google-chrome/";
	String iePath = home + "/.opera";
// Please update these paths according to the machine. // NOT REQUIRED
//	String firefoxPath = "/home/ranjan/.mozilla/firefox/";
//	String chromePath = "/home/ranjan/.config/google-chrome/";
//	String iePath = "/home/ranjan/.opera";

	int currentBrowser;
	boolean isRunning;

	Server(int p) {
		port = p;
		currentBrowser = 0;
		isRunning = false;
		browsers = new String[3];
		browsers[0] = firefox;
		browsers[1] = chrome;
		browsers[2] = ie;
	}

	void runServer() throws Exception {
		s = new ServerSocket(port);
		try {
			Socket client = s.accept();
			handleRequest(client);
		}
		catch(IOException e) {
			System.out.println("Failed to start server: " + e.getMessage());
			System.exit(0);
			return;
		}
	}

	void deleteFolder(File f) {
		File [] files = f.listFiles();
		if(files != null) {
			for(File ff: files) {
				if(ff.isDirectory())
					deleteFolder(ff);
				else
					ff.delete();
			}
		}
		f.delete();
	}

	void handleRequest(Socket s) throws Exception {
		is = new BufferedReader(new InputStreamReader(s.getInputStream()));
		os = new PrintWriter(s.getOutputStream(), true);

		while(true) {
			int op = Integer.parseInt(is.readLine());
			if(op == -1)
				break;

			int browser = -1;
			if(op == 1 || op == 3) 
				browser = Integer.parseInt(is.readLine())-1;

			if(op == 2) {
				if(isRunning == false) {
					os.println("No running browser.");
				}
				else {
					if(currentBrowser == 1) {
						Process p = Runtime.getRuntime().exec("pkill " + "chrome");
					}
					else {
						Process p = Runtime.getRuntime().exec("pkill " + browsers[currentBrowser]);
					}
					isRunning = false;
					os.println(browsers[currentBrowser] + " killed.");
					System.out.println(browsers[currentBrowser] + " killed.");
				}
			}
			else if(op == 1) {
				if(isRunning) {
						os.println(browsers[currentBrowser] + " is already running. Please kill it first." );
						System.out.println(browsers[currentBrowser] + " is already running. Please kill it first." );
				}
				else {
					currentBrowser = browser;
					Process p = Runtime.getRuntime().exec(browsers[currentBrowser]);
					isRunning = true; os.println("Launching " + browsers[currentBrowser] );
					System.out.println("Launching " + browsers[currentBrowser] );
				}
			}
			else if(op == 3){
				//File f = new File(firefoxPath);
				if(isRunning) {
					os.println(browsers[currentBrowser] + " is running. Please kill all browsers.");
					System.out.println(browsers[currentBrowser] + " is running. Please kill all browsers.");
					continue;
				}
				else {
					File f;
					os.println(browsers[browser] + " is restored.");
					System.out.println(browsers[browser] + " is restored.");
					if(browser == 0)
						f = new File(firefoxPath);
					else if(browser == 1)
						f = new File(chromePath);
					else  
						f = new File(iePath);

					File [] files = f.listFiles();
					if(files != null) {
						for(File ff: files) {
							if(ff.isDirectory())
								deleteFolder(ff);
							else
								ff.delete();
						}
					}
				}
			}
			else
				os.println("Wrong option");
			System.out.println("");

		}
		
		System.out.println("Exiting\n");
		os.println("Bye!!");
		os.close();
		is.close();
		s.close();
	}

	public static void main(String [] args) throws Exception
	{
		/*
		Process p = Runtime.getRuntime().exec("echo $HOME");
		InputStream stdin = p.getInputStream();
		InputStreamReader isr = new InputStreamReader(stdin);
		BufferedReader brr = new BufferedReader(isr);
		String line = brr.readLine();
		System.out.println(line);
		*/
		Server server = new Server(5513);
		try {
			server.runServer();
		} catch(Exception e) {
			e.printStackTrace();
		}
		
	}
}

