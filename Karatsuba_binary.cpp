// Multiplying two binary numbers and printing the product in decimal form.
// Stratergy used: Divide and Conquer Algorithm
// Time Complexity: O(n^1.585)

#include <iostream>
#include <math.h>
using namespace std;

long long int karatsuba_binary(string str1, string str2){
    int n = str1.length();
    if(n == 2){
        // Converting 4 individual characters to number
        int a, b, c, d;
        a = b = c = d = 0;
        if(str1[0] == '1')
            a = 1;
        if(str1[1] == '1')
            b = 1;
        if(str2[0] == '1')
            c = 1;
        if(str2[1] == '1')
            d = 1;
        
        return(pow(2,n)*a*c + pow(2, n/2) * (a*d + b*c) + b*d);
    }
	
	else {
	    string str3(str1, 0, n/2);
	    string str4(str1, n/2, n);
	    string str5(str2, 0, n/2);
	    string str6(str2, n/2, n);
	    return(pow(2,n)*karatsuba_binary(str3, str5) + pow(2,n/2)*(karatsuba_binary(str3,str6)+karatsuba_binary(str4,str5)) + karatsuba_binary(str4, str6));
	}
}

int main() {
    int len1, len2, po = 1;
    long long int ans;
    string str1, str2;
    cin >> str1 >> str2;
    len1 = str1.length();
    len2 = str2.length();
    int ref = len2;

    if(len1 > len2){
        ref = len1;
    }

    while(po < ref){
        po = po * 2;
    }

    for(int i = 0; i < po-len1; i++){
        str1 =  "0" + str1;
    }
    for(int i = 0; i < po-len2; i++){
        str2 =  "0" + str2;
    }

    ans = karatsuba_binary(str1, str2);
    cout<<ans;

    return 0;
}
