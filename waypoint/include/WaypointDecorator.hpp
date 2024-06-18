#ifndef WAYPOINTDECORATOR_HPP
#define WAYPOINTDECORATOR_HPP


#include "I_Waypoint.h"
#include "Waypoint.h"

class WaypointDecorator : public I_Waypoint {
    public:
        /* WaypointDecorator() = default; */
        /* WaypointDecorator(I_Waypoint& dev) : decorated_obj(&dev) {}; */
    void decorate(I_Waypoint &wpt)
    {
        decorated_obj = &wpt;
    }
    void display () const override {
        std::cout << "Extend display behaviour" << std::endl;
        decorated_obj->display();
    }
    private:
    I_Waypoint* decorated_obj;
};


#endif /* WAYPOINTDECORATOR_HPP */
