#ifndef VALORES_H
#define VALORES_H

#include <sstream>

using namespace std;

int stringToInt(string value){
	stringstream ss;
	int a;
	
	ss<<value;
	ss>>a;
	
	return a;
}

float stringToFloat(string value){
	stringstream ss;
	float a;
	
	ss<<value;
	ss>>a;
	
	return a;
}

string intToString(int value){
	stringstream ss;
	string a;
	
	ss<<value;
	ss>>a;

	return a;
}

string floatToString(float value){
	stringstream ss;
	string a;
	
	ss<<value;
	ss>>a;

	return a;
}

#endif //VALORES_H
