#pragma once

#include "Shape.hh"
#include <iostream>

class Ellipse : public Shape{

    private:
        double major,minor;

    public:

        //constructor here
        Ellipse(double x, double y, double major, double minor):
          Shape(x,y), major(major), minor(minor) {}

        double area() const override {
            double r = (major+minor)/2;
            return pi*r*r;
        }

        
        double perimeter()  const override {
            double r = (major+minor)/2;
            return 2*pi*r;
        } 

        void print(std::ostream& s) const override {
            s << major << ", " << minor << std::endl;            
        }

};
