/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 ******* Create a branch named Part2 ********

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */











 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers  
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write some add/subtract/divide/multiply member functions for each type that take your 3 UDTs
         for example, IntType::divide(const DoubleType& dt);
 
 5) print out the results with some creative couts 
    i.e.
         FloatType ft(0.1f);
         IntType it(3);
         std::cout << "adding 3 and subtracting 'it' from 'ft' results in the following value: " << *ft.add(2.f).subtract( it ).value << std::endl;  //note the dereference of the `value` member of `ft`
 
 6) Don't let your heap-allocated owned type leak!
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */




#include <stdexcept>
#include <iostream>
 
struct FloatType
{
    float add(float lhs, float rhs);
    float subtract(float lhs, float rhs);
    float multiply(float lhs, float rhs);
    float divide(float lhs, float rhs);
};

float FloatType::add(float lhs, float rhs)
{
    return lhs + rhs;
}

float FloatType::subtract(float lhs, float rhs)
{
    return lhs - rhs;
}

float FloatType::multiply(float lhs, float rhs)
{
    return lhs * rhs;
}

float FloatType::divide(float lhs, float rhs)
{
    if (rhs == 0.0f)
    {
        std::cout << "Trying to divide by 0" << std::endl; 
    }
    
    return lhs / rhs;
}

struct DoubleType
{
    double add(double lhs, double rhs);
    double subtract(double lhs, double rhs);
    double multiply(double lhs, double rhs);
    double divide(double lhs, double rhs);
};

double DoubleType::add(double lhs, double rhs)
{
    return lhs + rhs;
}

double DoubleType::subtract(double lhs, double rhs)
{
    return lhs - rhs;
}

double DoubleType::multiply(double lhs, double rhs)
{
    return lhs * rhs;
}

double DoubleType::divide(double lhs, double rhs)
{
    if (rhs == 0.0)
    {
        std::cout << "Trying to divide by 0" << std::endl; 
    }
    
    return lhs / rhs;
}

struct IntType
{
    int add(int lhs, int rhs);
    int subtract(int lhs, int rhs);
    int multiply(int lhs, int rhs);
    int divide(int lhs, int rhs);
};

int IntType::add(int lhs, int rhs)
{
    return lhs + rhs;
}

int IntType::subtract(int lhs, int rhs)
{
    return lhs - rhs;
}

int IntType::multiply(int lhs, int rhs)
{
    return lhs * rhs;
}

int IntType::divide(int lhs, int rhs)
{
    if (rhs == 0)
    {
        std::cout << "Trying to divide by 0" << std::endl; 
        return 0;
    }
    
    return lhs / rhs;
}

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
    
    FloatType ft;
    IntType it; 
    DoubleType dt;
    
    auto result1 = ft.add(13.0f, 15.3f);
    auto result2 = it.divide(236, 3);
    auto result3 = dt.multiply(0.2, 20.5);
    
    std::cout << "ft.add(13.0f, 15.3f): " << result1 << std::endl;
    std::cout << "it.divide(236, 3): " << result2 << std::endl;
    std::cout << "dt.multiply(0.2, 20.5): " << result3 << std::endl;
}
