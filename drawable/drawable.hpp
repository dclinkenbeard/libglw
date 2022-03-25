//
// Created by Garrett on 12/1/2021.
//

#ifndef GLW_DRAWABLE_HPP
#define GLW_DRAWABLE_HPP
//internal headers
#include "../ext/glm/glm/glm.hpp"
#include "../ext/glm/glm/ext.hpp"

#include "../graphics/buffer.hpp"
#include "../graphics/shader.hpp"
#include "../graphics/vertex_array.hpp"

namespace glw { //start of namespace glw
//enum class that defines different drawing mesh topology that can be used later while openGL draw calls.
enum class topology {
    POINTS,
    LINES,
    LINE_LOOP,
    LINE_STRIP,
    TRIANGLES,
    TRIANGLE_STRIP,
    TRIANGLE_FAN,
};

class drawable { // interface class drawable
public:
    virtual ~drawable() = default; //default virtual destructor of class drawable


    virtual void draw() = 0; //pure virtual function draw, will be defined inside derived classes.

    inline shader *get_shader() const { return this->shader_; } // returns shader source
    inline void set_shader(shader *s) { this->shader_ = s; } // sets shader source

    inline void set_model_mat(const glm::mat4 &m) { this->model_ = m; } // sets model matrix
    inline glm::mat4 get_model_mat() const { return this->model_; } // returns model matrix
//function to translate the model matrix to given position
    inline void translate(const glm::vec3 &v)
    {
        this->model_ = glm::translate(this->model_, v);
    }
//funtion to rotate the model matrix at given position with given angle
    inline void rotate(float deg, const glm::vec3 &v)
    {
        this->model_ = glm::rotate(this->model_, glm::radians(deg), v);
    }
    // function to scale the model matrix at given position
    inline void scale(const glm::vec3 &v)
    {
        this->model_ = glm::scale(this->model_, v);
    }
    //funtion to get the position coordinates of model matrix
    inline glm::vec3 get_position()
    {
        return {
            this->model_[3][0],
            this->model_[3][1],
            this->model_[3][2]
        };
    }

protected:
    topology topology_; // declare an objet of topology enum class
    glm::mat4 model_; // placeholder for model matrix
    shader *shader_;  // object of shader class


    index_buffer *ib_; // object of index buffer class
    vertex_array *va_; // object of vertex array object class
    vertex_buffer *positions_, *uvs_, *normals_; // objects of verted buffer class to create VBO's of positions, uv, normals
};

} //end of namespace glw


#endif //GLW_DRAWABLE_HPP
