//
// Created by Garrett on 12/2/21.
//

#ifndef GLW_CUBE_HPP
#define GLW_CUBE_HPP
//internal headers
#include "drawable.hpp"

namespace glw { //start of namespace glw


    class cube : public drawable {  // class cube derived from class drawable
public:
    virtual ~cube(); //cube class constructor
    cube(); //cube class distructor

    void draw() override; //function that draws cube on attached window context.
};

} //end of namespace glw


#endif //GLW_CUBE_HPP
