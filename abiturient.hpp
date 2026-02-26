#ifndef ABITURIENT_H_
#define ABITURIENT_H_

#include <numeric>
#include <ostream>
#include <string>
#include <vector>

class Observer;

struct Address {
    std::string city;
    std::string street;
    int house;

    Address() : city("Unknown"), street("Unknown"), house(0) {}
    Address(std::string _city, std::string _street, int _house)
        : city(std::move(_city)), street(std::move(_street)), house(_house) {}
};

class Abiturient {
    std::string lastName;
    std::string firstName;
    std::string middleName;
    Address address;
    std::vector<double> scores;
    double averScore;

  private:
    void update_aver_score() {
        if (scores.empty()) {
            averScore = 0;
            return;
        }
        double sum = std::accumulate(scores.begin(), scores.end(), 0.0);
        averScore = sum / scores.size();
    }

  public:
    friend class Observer;

    // Default constructor
    Abiturient()
        : lastName("None"), firstName("None"), middleName("None"), address(),
          scores({0, 0, 0}), averScore(0) {}
    // Parametrized constructor
    Abiturient(std::string _lastN, std::string _firstN, std::string _middleN,
               Address _addr, std::vector<double> _scs)
        : lastName(std::move(_lastN)), firstName(std::move(_firstN)),
          middleName(std::move(_middleN)), address(std::move(_addr)),
          scores(std::move(_scs)) {
        update_aver_score();
    }

    // Copy constructor
    Abiturient(const Abiturient &other) = default;

    // Destructor
    ~Abiturient() = default;

    // Getters
    inline const std::string &get_lastname() const { return lastName; }
    inline const std::string &get_firstname() const { return firstName; }
    inline const std::string &get_middlename() const { return middleName; }
    inline const Address &get_address() const { return address; }
    inline const auto &get_scores() const { return scores; }
    inline double get_averScore() const { return averScore; }

    inline double get_total_score() const {
        return std::accumulate(scores.begin(), scores.end(), 0.0);
    }

    // Setters
    inline void set_lastname(std::string _lastN) {
        lastName = std::move(_lastN);
    }
    inline void set_firstname(std::string _firstN) {
        firstName = std::move(_firstN);
    }
    inline void set_middlename(std::string _middleN) {
        middleName = std::move(_middleN);
    }
    inline void set_address(Address _address) { address = std::move(_address); }
    inline void set_scores(std::vector<double> _scs) {
        scores = std::move(_scs);
        update_aver_score();
    }

    /*
     * Operator << overload to print abiturient
     * instead of separate function
     */
    friend std::ostream &operator<<(std::ostream &os, const Abiturient &a) {
        os << a.lastName << " " << a.firstName[0] << '.' << a.middleName[0]
           << ". | "
           << "Avg: " << a.averScore << " | Total: " << a.get_total_score();
        return os;
    }

    friend bool operator==(const Abiturient &lhs, const Abiturient &rhs) {
        return lhs.firstName == rhs.firstName && lhs.lastName == rhs.lastName &&
               lhs.middleName == rhs.middleName;
    }

    friend bool operator!=(const Abiturient &lhs, const Abiturient &rhs) {
        return lhs.firstName != rhs.firstName || lhs.lastName != rhs.lastName ||
               lhs.middleName != rhs.middleName;
    }

    Abiturient &operator=(const Abiturient &other) {
        if (this == &other)
            return *this;

        this->lastName = other.lastName;
        this->firstName = other.firstName;
        this->middleName = other.middleName;
        this->address = other.address;
        this->averScore = other.averScore;
        this->scores = other.scores;

        return *this;
    }
};

#endif // ABITURIENT_H_
