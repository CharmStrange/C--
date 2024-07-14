#ifndef Simulations_h
# define Simulations_h

# include <iostream>
# include <string>

using namespace std;

class Function{
private:
    unsigned char state;
    string flow;
public:
    Function(){}
    ~Function(){}
};

struct manager{
    string name;
    unsigned char age;
    unsigned char power;
}manager;

class Aquarium{
    string fish;
    string not_fish;
    struct manager information;
private:
public:
    Aquarium(){}
    ~Aquarium(){}
};

class Zoo{
    unsigned char state;
    string animal;
    struct manager information;
private:
public:
    Zoo(){}
    ~Zoo(){}
};

class Farm{
    unsigned char state;
    string crop;
    struct manager information;
private:
public:
    Farm(){}
    ~Farm(){}
};

void Simulate_Aquarium(const struct manager& parameter){

}

void Simulate_Zoo(const struct manager& parameter){

}

void Simulate_Farm(const struct manager& parameter){

}


#endif
