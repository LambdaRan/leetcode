import java.io 

.BufferedReader;
import java.io 

.InputStreamReader;

public class Main {
	static int count = 0;
	public static void main(String[] args) {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in 

));
		String str;
		try {
			while ((str = in.readLine()) != null) {
				String ip = "";
				split(0, str.length(), str, ip);
				System.out.println(count);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static void split(int start, int length, String str, String ip) {
		String back = ip;
		for (int i = 1; i < 4 && (start + i) <= length; i++) {
			ip = back;
			String a = str.substring(start, start + i);
			if (isValidIp(a)) {
				ip += a;
				String[] strings = ip.split("\\.");
				if (strings.length == 4 && (start + i) == length) {
					count++;
					return;
				}
				ip += ".";
				split(start + i, length, str, ip);
			}
		}
	}

	private static boolean isValidIp(String s) {
		if (s.charAt(0) == '0') {
			return s.equals("0");
		}
		int num = Integer.parseInt(s);

		if (num <= 255 && num > 0) {
			return true;
		} else {
			return false;
		}
	}
}
