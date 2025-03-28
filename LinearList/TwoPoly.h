//
// Created by microindole on 25-3-28.
//

#ifndef TWOPOLY_H
#define TWOPOLY_H
#include <iostream>
#endif //TWOPOLY_H

const int MAXNUMBER = 100;
class poly{

public:
    float coef;
    int exp;
    poly(float coef, int exp) {
        this->coef = coef;
        this->exp = exp;
    }

    poly(){}

    void append(float co,int e, poly c[],int k) {
        if (k > 100 - 1) {
            std::cout<<"Error"<<std::endl;
        }else {
            c[k].coef = co;
            c[k].exp = exp;
        }
    }

};

