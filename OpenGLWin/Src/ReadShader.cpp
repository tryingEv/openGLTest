#include "ReadShader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ReadShader::ReadShader()
{
}

ReadShader::~ReadShader()
{
}

char* ReadShader::paraseShader(char* path)
{
	ifstream fs(path);
	if (!fs.is_open())
	{
		cout << "open file is failed, file path" << path << endl;
		return NULL;
	}
	string bufferStr;
	string text;

	while (!fs.eof())
	{
		getline(fs, bufferStr);
		text.append(bufferStr);
	}
	fs.close();
	cout << "read end text is :" << endl;
	cout << text << endl;
	char* value = (char*)text.c_str();
	return value;
}