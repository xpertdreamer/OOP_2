#ifndef OBSERVER_H
#define OBSERVER_H

#include "abiturient.hpp"
#include <string>

class Observer {
  private:
    const Abiturient &observed;

  public:
    explicit Observer(const Abiturient &ab) : observed(ab) {}

    std::string GetInfo() const {
        std::string info =
            "Last name: " + observed.lastName + '\n' +
            "First name: " + observed.firstName + '\n' +
            "Middle name: " + observed.middleName + '\n' +
            "Average score: " + std::to_string(observed.averScore);
        return info;
    }
};

#endif
