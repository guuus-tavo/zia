//
// Created by marmus_a on 25/01/18.
//

#ifndef CPP_ZIA_UNIXSOCKET_HPP
#define CPP_ZIA_UNIXSOCKET_HPP

#include <unistd.h>
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "ISocket.hpp"

class UnixSocket : public ISocket {
public:
    const static int MAXQUEUE = 1024;
    UnixSocket();
    virtual ~UnixSocket();

    virtual bool                    bind(const std::string& addr, const std::string& port);
    virtual bool                    bind(const std::string& addr, int port);
    virtual bool                    listen();
    virtual bool                    accept(ISocket& socket);
    virtual bool                    close();

    virtual int                     send(const std::string& str);
    virtual int                     recv(std::string& buff);

    virtual int                     getSocket() const;
    virtual bool                    isOpen() const;

    friend std::ostream&            operator<<(std::ostream& out, const ISocket& sock);

protected:
    int                             socket;
    sockaddr_in                     addr;
    bool                            opened;
};

std::ostream&    operator<<(std::ostream& out, const ISocket& sock);

#endif //CPP_ZIA_UNIXSOCKET_HPP
