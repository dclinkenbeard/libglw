//
// Created by Garrett on 12/6/2021.
//

#include "quad.hpp"

#include "../ext/glad/gl.h"
#include "../graphics/opengl/topology.hpp"

namespace glw { //created a namespace glw

quad::quad()
{
    //define the four coordinates/vertices of a quad
    std::vector<float> p = { //created a float variable p of vector type
        -1.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,
        1.0f, 1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
    };
    std::vector<float> uv = { //define the uv texture coordinates for each vertices of a quad
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
    };
    std::vector<float> n = { //define the normals at each vertices of a quad
        0.0, 0.0, 1.0,
        0.0, 0.0, 1.0,
        0.0, 0.0, 1.0,
        0.0, 0.0, 1.0,
    };

    this->positions_ = vertex_buffer::create(p.data(), p.size(), 3); //create vertex buffer object for quad coordinates/vertices with vector p as buffer source
    this->uvs_ = vertex_buffer::create(uv.data(), uv.size(), 2); //create vertex buffer object for quad uv texture coordinates with vector uv as buffer source
    this->normals_ = vertex_buffer::create(n.data(), n.size(), 3); //create vertex buffer object for quad normals with vector n as buffer source
    std::vector<uint32_t> inds = { // define indices for vertices of each triangles in the quad. quad consist of two triangles
            0, 1, 2,
            1, 3, 2
    };

    this->ib_ = index_buffer::create(inds.data(), inds.size()); // initialize index buffer object with inds vector as source
    this->va_ = vertex_array::create(); // create VAO, which will hold VBO's of position, uv, normal
    this->va_->set_index_buffer(this->ib_); // set index buffer object
    this->va_->add_vertex_buffer(this->positions_); //create postion VBO attach it to VAO, enable the VBO and bind it for rendering.
    this->va_->add_vertex_buffer(this->uvs_); //create uv texture positions VBO attach it to VAO, enable the VBO and bind it for rendering.
    this->va_->add_vertex_buffer(this->normals_); //create normals VBO attach it to VAO, enable the VBO and bind it for rendering.

    this->topology_ = topology::TRIANGLES; //define openGL topology as trangles which notifies what drawing primitive is used for draw.
    this->model_ = glm::mat4(1.f); // define model matrix as identifty matrix.
    this->shader_ = nullptr; // initialize shader to nullptr, later will be bind to respective shaders sources.
}

quad::~quad() //destructor of cube class for deallocating memory allocated to positions_, uvs_  ,normals_, ib_, va_
{
    this->positions_->unbind(); //unbing the position VBO
    this->uvs_->unbind(); //unbing the uv texture coordinates VBO
    this->normals_->unbind(); //unbing the normals VBO
    this->ib_->unbind(); //unbind the index buffer object(IBO)
    this->va_->unbind(); //unbing the vertext array object(VAO)

    delete this->positions_; //erase the position vector
    delete this->uvs_; //erase the uv texture coordinate vector
    delete this->normals_; //erase the normals vector
    delete this->ib_; //delete IBO object
    delete this->va_; //delete VAO object
}

void quad::draw() //function that is used to draw the quad
{
    this->va_->bind(); //bind the vertex array object which holds different VBO's of position, uv, normals
    /*check if index buffer is initialized.
       * if yes then call glDrawElements with triangle as topology and index buffer for drawing order.
       * else call glDrawArrays with triangle as topology and size of postions and stride
       */
    if (this->ib_ && this->ib_->get_count() > 0) //check condition for value this->ib_ according to topology and count >0
        glDrawElements(gl_topology::get_gl_topology(this->topology_),
                       (GLint) this->ib_->get_count(),
                       GL_UNSIGNED_INT,
                       nullptr);
    else
        glDrawArrays(gl_topology::get_gl_topology(this->topology_),
                     0,
                     (GLint) this->positions_->get_data_size());
}
} //end of namespace glw
