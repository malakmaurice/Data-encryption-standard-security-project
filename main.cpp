#include<math.h>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>roundShifts{
    1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1
};
vector<vector<int>> pc1{
	{57,49,41,33,25,17,9},
	{1,58,50,42,34,26,18},
	{10,2,59,51,43,35,27},
	{19,11,3,60,52,44,36},
	{63,55,47,39,31,23,15},
	{7,62,54,46,38,30,22},
	{14,6,61,53,45,37,29},
	{21,13,5,28,20,12,4}
};
vector<vector<int>> pc2{
    {14,17,11,24,1,5},
    {3,28,15,6,21,10},
    {23,19,12,4,26,8},
    {16,7,27,20,13,2},
    {41,52,31,37,47,55},
    {30,40,51,45,33,48},
    {44,49,39,56,34,53},
    {46,42,50,36,29,32}
};
vector<vector<int>> ip{
    {58,50,42,34,26,18,10,2},
    {60,52,44,36,28,20,12,4},
    {62,54,46,38,30,22,14,6},
    {64,56,48,40,32,24,16,8},
    {57,49,41,33,25,17,9,1},
    {59,51,43,35,27,19,11,3},
    {61,53,45,37,29,21,13,5},
    {63,55,47,39,31,23,15,7}
};
vector<vector<int>> expan{

    {32,1,2,3,4,5},
    {4,5,6,7,8,9},
     {8,9,10,11,12,13},
    {12,13,14,15,16,17},
    {16,17,18,19,20,21},
    {20,21,22,23,24,25},
    {24,25,26,27,28,29},
    {28,29,30,31,32,1}
};
vector<vector<int>>s{
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},
    {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
    {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
    {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
    {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},
    {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
    {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
    {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
    {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},
    {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
    {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
    {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
    {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},
    {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
    {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
    {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
    {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3},
    {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
    {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
    {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
    {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13},
    {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
    {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
    {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
    {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},
    { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
      {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
      {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
      {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 }

};
vector< vector<int>>strPer{
    { 16, 7, 20, 21},
    {29, 12, 28, 17},
    {1, 15, 23, 26},
    {5, 18, 31, 10},
    {2, 8, 24, 14},
    {32, 27, 3, 9},
    {19, 13, 30, 6},
    {22, 11, 4, 25 }
};
vector< vector<int>>inverseIp{
    { 40, 8, 48, 16, 56, 24, 64, 32},
    {39, 7, 47, 15, 55, 23, 63, 31},
    {38, 6, 46, 14, 54, 22, 62, 30},
    {37, 5, 45, 13, 53, 21, 61, 29},
    {36, 4, 44, 12, 52, 20, 60, 28},
    {35, 3, 43, 11, 51, 19, 59, 27},
    {34, 2, 42, 10, 50, 18, 58, 26},
    {33, 1, 41, 9, 49, 17, 57, 25 }
};
string decimalToBinary(int n){
 // array to store binary number
    int binaryNum[32];
    string res="";

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        res+= binaryNum[j]+'0';
   return  res;

}
int binaryToDecimal(string s){
    int res=0,siz=s.size();
    for(int i=0;i<siz;i++){
            res+= (s[i]-'0') * pow(2,siz-1-i);
    }
    return res;
}
string bin2hex(string s)
{
	// binary to hexadecimal conversion
	unordered_map<string, string> mp;
	mp["0000"] = "0";
	mp["0001"] = "1";
	mp["0010"] = "2";
	mp["0011"] = "3";
	mp["0100"] = "4";
	mp["0101"] = "5";
	mp["0110"] = "6";
	mp["0111"] = "7";
	mp["1000"] = "8";
	mp["1001"] = "9";
	mp["1010"] = "A";
	mp["1011"] = "B";
	mp["1100"] = "C";
	mp["1101"] = "D";
	mp["1110"] = "E";
	mp["1111"] = "F";
	string hex = "";
	for (int i = 0; i < s.length(); i += 4) {
		string ch = "";
		ch += s[i];
		ch += s[i + 1];
		ch += s[i + 2];
		ch += s[i + 3];
		hex += mp[ch];
	}
	return hex;
}
string hexaToBinary(string x) {
	string b="";
	map<char, string> m;
	m['0'] = "0000";
	m['1'] = "0001";
	m['2'] = "0010";
	m['3'] = "0011";
	m['4'] = "0100";
	m['5'] = "0101";
	m['6'] = "0110";
	m['7'] = "0111";
	m['8'] = "1000";
	m['9'] = "1001";
	m['A'] = "1010";
	m['B'] = "1011";
	m['C'] = "1100";
	m['D'] = "1101";
	m['E'] = "1110";
	m['F'] = "1111";
	for (int i = 0; i < x.length(); i++) {
		b += m[x[i]];
	}
	return b;
}
string permutation(string s,vector<vector<int>>&table) {
	string permutResult = "";
	for (int i = 0; i< table.size(); i++) {
		for (int j = 0; j < table[i].size(); j++) {
			permutResult += s[table[i][j] - 1];
		}
	}

	return permutResult;

}
string leftShift(string s,int shift){
for(int i=0;i<shift;i++){
        char c=s[0];
    for(int j=1;j<s.size();j++){
        s[j-1]=s[j];
    }
    s[s.size()-1]=c;
}
return s;
}
vector<string>generateKeys(string key){
    vector<string>res;
    string leftKey= key.substr(0,28);
    string rightKey=key.substr(28,28);
    for(int i=0;i<16;i++){
        leftKey=leftShift(leftKey,roundShifts[i]);
        rightKey=leftShift(rightKey,roundShifts[i]);
        key=leftKey+rightKey;
        key=permutation(key,pc2);
        res.push_back(key);
    }
return res;
}
string xoor(string s1,string s2){
    string res="";
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[i])
            res+="0";
        else
            res+="1";
    }
    return res;
}
string subInSbox(string text){
    string res="",r;
    int row,col;
    for(int i=0;i<8;i++){
        r=text[i*6];
        r+=text[(i*6)+5];
        row=binaryToDecimal(r) + (i*4) ;
        r=text.substr(1+(i*6),4);
        col=binaryToDecimal(r);
        //res+=decimalToBinary(s[row][col]);
        int w=s[row][col];
        res += char(w / 8 + '0');
        w = w % 8;
        res += char(w / 4 + '0');
        w = w % 4;
        res += char(w/ 2 + '0');
        w = w % 2;
        res += char(w+ '0');

    }
    return res;
}
string encrypt(string plainText,vector<string>&roundKeys){
    string res;
    plainText=permutation(plainText,ip);


    string leftText=plainText.substr(0,32);
    string rightText=plainText.substr(32,32);
    string x=rightText;
    for(int i=0;i<16;i++){
    x=rightText;
    rightText=permutation(rightText,expan);

    rightText =xoor(rightText,roundKeys[i]);

    rightText=subInSbox(rightText);

    rightText=permutation(rightText,strPer);

    rightText=xoor(rightText,leftText);

    leftText=x;
    if(i==15){
            swap(rightText,leftText);

    }
    /*cout<< "Round " << i + 1 << " "<<bin2hex(leftText)<<" "
        <<bin2hex(rightText)<<"\n";*/
    }
    res=leftText+rightText;
    res=permutation(res,inverseIp);
    return res;
}
int main() {
    vector<string>roundKeys;
	string key,plainText;
	key = "1323445A6D788381";
	plainText="7A6C731D22347676";

	key = hexaToBinary(key);
	key= permutation(key,pc1);
	roundKeys=generateKeys(key);

	plainText=hexaToBinary(plainText);

	string encryptedText=encrypt(plainText,roundKeys);
    cout<<"Cipher Text: "<<bin2hex(encryptedText)<<"\n";

    reverse(roundKeys.begin(),roundKeys.end());

    string text=encrypt(encryptedText,roundKeys);
    cout<<"plain Text: "<<bin2hex(text)<<"\n";
	return 0;
}
