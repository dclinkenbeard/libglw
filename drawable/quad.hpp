//
// Created by Garrett on 12/6/2021.
//

#ifndef GLW_QUAD_HPP
#define GLW_QUAD_HPP
//internal headers
#include "drawable.hpp"

namespace glw { //start of namespace glw

class quad : public drawable { // class quad derived from class drawable
public:
    virtual ~quad(); // virtual distructor of class quad
    quad(); //constructor of class qual


    void draw() override; // draw method used to draw quad on attached window context
};

} //end of namespace glw


#endif //GLW_QUAD_HPP
