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
    float coef; //具体数值
    int exp; //次数

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

void polyAdd(poly a[],poly b[],poly c[],int at,int bt) {
    int i = 0, j = 0, k = 0;
    float co;
    while(i <= at && j <= bt) {
        if (a[i].exp == b[j].exp) {
            co = a[i].coef + b[j].coef;
            if (co != 0) {
                c->append(co,a[i].exp,c,k);
                k++;
            }
            i++;j++;
        }else {
            if (a[i].exp > b[j].exp) {
                c->append(a[i].coef,a[i].exp,c,k);
                k++;i++;
            }else {
                c->append(b[j].coef,b[j].exp,c,k);
            }
        }
    }
    while(i <= at) {
        c->append(a[i].coef,a[i].exp,c,k);
        k++;i++;
    }
    while(j <= bt) {
        c->append(b[j].coef,b[j].exp,c,k);
        k++;j++;
    }
    // 这里要返回c[]，思考怎么做
}

