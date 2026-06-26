//
// Created by Nikita Singh on 03/06/26.
//

#include "returnvalueFUNC.h"
#include<iostream>


int FUNC(int x,int y) {
    if (x>=y) {
       std:: cout<<"the answer is +";
    }
    else {
        std::cout<<"The value is -";

    }
    return x + y;

}

