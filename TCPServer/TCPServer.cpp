

#include "pch.h"
#include <iostream>

int main()
{
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
short port = 8888;
severaddr.sin_family = AF_INET;
severaddr.sin_addr.s_addr = htonl(INADDR_ANY);
severaddr.sin_port = htons(port);
bind(s, (SOCKADDR*)&severaddr, sizeof(severaddr));
listen(s, 5);
SOCKET s1 = accept(s, NULL, NULL);
char str[256];
cin >> str;
int res = send(s1, str, strlen(str), 0);
res = send(s1, 0, 1, 0);
char buf[256];

while (true)
{
	res = recv(s1, buf, sizeof(buf), 0);
	if (res <= 0)
		break;
	if (res < 256) {
		buf[res] = 0; 
	}
	cout << "Nhan duoc tu client: "<< buf << endl;
}

closesocket(s);
closesocket(s1);
WSACleanup();
	}

