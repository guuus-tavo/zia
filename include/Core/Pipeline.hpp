//
// Created by marmus_a on 27/01/18.
//

#ifndef CPP_ZIA_PIPELINE_HPP
#define CPP_ZIA_PIPELINE_HPP

#include <iostream>
#include <memory>
#include "api/module.h"
#include "ThreadPool.hpp"

class Pipeline : public std::map<std::string, std::shared_ptr<zia::api::Module>>{
public:
    Pipeline(int nbWorker = 4);
    ~Pipeline();

    void                                    run(zia::api::Net::Raw, zia::api::NetInfo) const;
    zia::api::Net::Callback                 getCallback() const;
private:
    ThreadPool*     pool;
};

#endif //CPP_ZIA_PIPELINE_HPP
