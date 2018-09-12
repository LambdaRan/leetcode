
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>

//#include <stdio.h>


using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int result;
    b = abs(b);
    int i;
    for (i = 1; i <= 7; i++) {
        if((a*(7-i)-b*i)<0){
            break;
        }
    }
    int x = 7-i;
    int xx;
    if(x>=3){
        xx=2*x+3;
    }else{
        xx=3*x;
    }
    int yy = 17-xx;

    result = a*xx-b*yy;
    cout << result << endl;
    return 0;
}



import java.io 

.BufferedReader;
import java.io 

.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in 

));
		String str;
		try {
			while ((str = in.readLine()) != null) {
				String[] s = str.split(" ");
				int a = Integer.parseInt(s[0]);
				int b = Math.abs(Integer.parseInt(s[1]));

				int i;
				for (i = 1; i <= 7; i++) {
					if((a*(7-i)-b*i)<0){
						break;
					}
				}
				int x = 7-i;
				int xx;
				if(x>=3){
					xx=2*x+3;
				}else{
					xx=3*x;
				}
				int yy = 17-xx;
				System.out.println(a*xx-b*yy);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
