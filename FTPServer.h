/**
 * @desc:   ÍøÂç½Ó¿ÚAPI£¬FTPServer.h
 * @author: luosc
 * @date:   2025
 */

#ifndef FTP_SERVER_H
#define FTP_SERVER_H

#include <stdint.h>
#include <string>

class FTPServer
{
public:
	FTPServer();
	~FTPServer();

	FTPServer(const FTPServer& rhs) = delete;
	FTPServer(FTPServer&& rhs) = delete;

	FTPServer& operator=(const FTPServer& rhs) = delete;
	FTPServer& operator=(FTPServer&& rhs) = delete;
public:
	bool logOn(const char* ip, uint16_t port, const char* name, const char* password);
	std::string list();

	bool cwd();
	bool upload();
	bool download();

	bool setMode(bool passiveMode);
private:

};

#endif //FTP_SERVER_H