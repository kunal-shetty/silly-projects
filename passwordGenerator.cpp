#include<iostream>
#include<string>
#include<time.h>
using namespace std;
string generatePassword(int length){
	string passWord;
	string allCharacters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@!#$";
	while(length != 0){
		passWord += allCharacters[rand() % allCharacters.length()];
		length--;
	}
	return passWord;
}
string generateSpecializedPassword(int length, string mustInclude){
	string passWord;
	length = length - mustInclude.length();
	passWord += mustInclude;
	string allCharacters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@!#$";
	while(length != 0){
		passWord += allCharacters[rand() % allCharacters.length()];
		length--;
	}
	return passWord;
}

int main(){
	srand(time(0));
	string pass = generatePassword(13);
	cout<<pass<<endl;
	pass = generateSpecializedPassword(10,"Hello");
	cout<<pass<<endl;
	return 0;
}