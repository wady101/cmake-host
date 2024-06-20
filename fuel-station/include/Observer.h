#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
class I_Observer {
public:
  virtual void update() = 0;
  virtual ~I_Observer() = default;
};

class Observe {
    public:
    std::vector <I_Observer *> observers;

    void updateObserver() {
        for (auto a : observers)
            a->update();
    }
};

#endif /* OBSERVER_H */
