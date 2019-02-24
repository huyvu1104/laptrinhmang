// tcpclient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main(int argc, char* argv[]) // tcpclient.exe thamso1 thamso2 thamso3
{
		// argc = 4
		// argv = ["c:/user.../.../tcpclient.exe","thamso1","thamso2","thamso3"] 
		// tcpclient 127.0.0.1 8888
		// argv[1] = "127.0.0.1"
		// argv[2] = "8888" 
	for (int i = 0; i < argc; i++)
	{
		cout << "argv[" << i << "]: " << argv[i] << endl;
	}
		WORD version = MAKEWORD(2, 2);
		WSADATA wsaDATA;
		if (WSAStartup(version, &wsaDATA)) {
			cout << "Version doesnt support!!";
		}
		else {
			cout << "Initialized!!" << endl;
		}
		SOCKET s;
		s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		SOCKADDR_IN severaddr;
		short port = 8888; // port = atoi(argv[2]);
		severaddr.sin_family = AF_INET;
		severaddr.sin_addr.s_addr = inet_addr("127.0.0.1");// argv[1]
		severaddr.sin_port = htons(port);

		connect(s, (SOCKADDR*)&severaddr, sizeof(severaddr));
		char str[256];
		cin >> str;
		int res = send(s, str, strlen(str), 0);
		res = send(1, 0, 1, 0);
		
		closesocket(s);
		WSACleanup();
	}


