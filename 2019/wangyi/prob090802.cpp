
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
    long nTest = 0;
    cin >> nTest;
    while (nTest--)
    {
        long first = 0;
        long second = 0;
        cin >> first >> second;
        if(first > second)
        {
            first = first ^ second;
            second = first ^ second;
            first = first ^ second;
        }
        if(first == 1) 
        {
            if(second == 1)
            {
                cout << 1 << endl;
            }else{
                cout << (second - 2) << endl;
            }
        }
        else if(first == 2)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << (first*second-2*first-2*second+4) << endl;
        }
    }

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
		try{
			while((str = in.readLine())!=null){
				int t = Integer.parseInt(str);
				while(t!=0){
					String[] s = in.readLine().split(" ");
					long n = Integer.parseInt(s[0]);
					long m = Integer.parseInt(s[1]);
					if(n>m){
						n=n^m;
						m=n^m;
						n=n^m;
					}
					if(n==1){
						if(m==1){
							System.out.println(1);
						}else{
							System.out.println(m-2);
						}
					}else if(n==2){
						System.out.println(0);
					}else{
						System.out.println(n*m-2*n-2*m+4);
					}
					t--;
				}
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}

}
