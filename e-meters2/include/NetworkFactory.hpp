#ifndef NETWORKFACTORY_HPP
#define NETWORKFACTORY_HPP

#include "I_Network.h"
#include "MBus_Network.h"
#include "ZigBee_Network.h"

#include <memory>

class NetworkBase {
    public:
    std::unique_ptr<I_Network> chooseNetwork(std::string_view choice) {
        std::unique_ptr<I_Network> net {};
        if (choice == "Z")
            net = std::make_unique<ZigBee>();
        else
            net = std::make_unique<MBus>();
        return net;
    }
};

template <class T>
T& chooseNetwork() {
    T inst;
    return inst;
}
template<typename Ty, typename ...Param_Ty>
auto make_network(Param_Ty&&... param) {
  return Ty{std::forward<Param_Ty>(param)...};
}


#endif /* NETWORKFACTORY_HPP */
