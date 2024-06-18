#ifndef SYMBOLDECORATOR_HPP
#define SYMBOLDECORATOR_HPP

#include "WaypointDecorator.hpp"

class SymbolDecorator : public WaypointDecorator {
    public:
            // SymbolDecorator() {};
            // explicit SymbolDecorator(WaypointDecorator dect) : WaypointDecorator(dect) {};
        void display() const {
            std::cout << "symbol" << std::endl;
            WaypointDecorator::display();
        }
};

class AltitudeDecorator : public WaypointDecorator {
        public:
            // AltitudeDecorator() {};
            // explicit AltitudeDecorator(WaypointDecorator dect) : WaypointDecorator(dect) {};
        void display() const {
            std::cout << "altitude" << std::endl;
            WaypointDecorator::display();
        }

};


#endif /* SYMBOLDECORATOR_HPP */
