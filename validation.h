#ifndef VALIDATION_H
#define VALIDATION_H

// interface to declare virtual function that will be implemented in derived class
class Validation
{
public:
    Validation();
    // pure virtual function to check user input validity
    virtual bool validateUserInput() = 0;
};

#endif // VALIDATION_H
