//
// Created by marmus_a on 30/01/18.
//

#ifndef CPP_ZIA_NETWORK_HPP
#define CPP_ZIA_NETWORK_HPP

#include <Network/Socket.hpp>
#include <api/net.h>
#include <list>
#include <memory>
#include <thread>

class Network : public zia::api::Net {
public:
    Network();
    virtual ~Network();

    virtual bool    config(const zia::api::Conf& conf);
    virtual bool    run(zia::api::Net::Callback cb);
    virtual bool    stop();
    virtual bool    send(zia::api::ImplSocket* sock, const Raw& resp);

    friend void     networkRoutine(Network* net);
private:
    int                                     setFdsSet();
    fd_set                                  fdsSet;
    zia::api::Net::Callback                 callback;
    std::unique_ptr<ISocket>                listener;
    std::list<std::shared_ptr<ISocket>>     sockets;
    std::unique_ptr<std::thread>            thread;
};

void                networkRoutine(Network* net);

#endif //CPP_ZIA_NETWORK_HPP
