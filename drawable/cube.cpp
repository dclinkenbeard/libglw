//
// Created by Garrett on 12/2/21.
//

#include "cube.hpp"

#include "../ext/glad/gl.h"
#include "../graphics/opengl/topology.hpp"

namespace glw { //start of glw namespace

cube::cube() //constructor of cube class
{
    std::vector<float> p = {
            -0.5f, -0.5f, -0.5f,
            0.5f, 0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, 0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, 0.5f, -0.5f,

            -0.5f, -0.5f, 0.5f,
            0.5f, -0.5f, 0.5f,
            0.5f, 0.5f, 0.5f,
            0.5f, 0.5f, 0.5f,
            -0.5f, 0.5f, 0.5f,
            -0.5f, -0.5f, 0.5f,

            -0.5f, 0.5f, 0.5f,
            -0.5f, 0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f, 0.5f,
            -0.5f, 0.5f, 0.5f,

            0.5f, 0.5f, 0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, 0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, 0.5f, 0.5f,
            0.5f, -0.5f, 0.5f,

            -0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, 0.5f,
            0.5f, -0.5f, 0.5f,
            -0.5f, -0.5f, 0.5f,
            -0.5f, -0.5f, -0.5f,

            -0.5f, 0.5f, -0.5f,
            0.5f, 0.5f, 0.5f,
            0.5f, 0.5f, -0.5f,
            0.5f, 0.5f, 0.5f,
            -0.5f, 0.5f, -0.5f,
            -0.5f, 0.5f, 0.5f,
    };
    /* Texture coordinates of each vertex/position defined in vector p.
   * These uv coordinates corresponds to the respective texture positions of each point in p.
   */
    std::vector<float> uv = {
            0.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            0.0f, 0.0f,
            0.0f, 1.0f,

            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,

            1.0f, 0.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,

            1.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,

            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f,

            0.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
    };
    /* Normals of each vertex/position defined in vector p.
    * These values correspond to the respective normals at each position defined in p.
    */
    std::vector<float> n = {
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,

            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,

            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,

            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,

            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,

            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
    };

    this->positions_ = vertex_buffer::create(p.data(), p.size(), 3); //initialize vertex buffer object for position with vector p as data source
    this->uvs_ = vertex_buffer::create(uv.data(), uv.size(), 2); //initialize vertex buffer object for uv texture coordinates with vector uv as data source
    this->normals_ = vertex_buffer::create(n.data(), n.size(), 3); //initialize vertex buffer object for normals with vector n as data source

    this->ib_ = nullptr; //index buffer object
    this->va_ = vertex_array::create(); //create vertex array object which will later used to bind different Vertex buffer objects together during rendering call.

    this->va_->add_vertex_buffer(this->positions_); //create position VBO attach it to VAO, enable the VBO and bind it for rendering.
    this->va_->add_vertex_buffer(this->uvs_); //create uv texture positions VBO attach it to VAO, enable the VBO and bind it for rendering.
    this->va_->add_vertex_buffer(this->normals_); //create normals VBO attach it to VAO, enable the VBO and bind it for rendering.

    this->topology_ = topology::TRIANGLES; //define openGL topology as triangles which notifies what drawing primitive is used for draw.
    this->model_ = glm::mat4(1.f); // define model matrix as identify matrix.
    this->shader_ = nullptr; // initialize shader to nullptr, later will be bind to respective shaders sources.
}

cube::~cube() // destructor of cube class
{
    this->positions_->unbind(); //unbind the position VBO
    this->uvs_->unbind(); //unbind the uv texture coordinates VBO
    this->normals_->unbind(); //unbind  the normals VBO
    this->va_->unbind(); //unbind the vertex array object(VAO)

    delete this->positions_; //erase the position vector
    delete this->uvs_; //erase the uv texture coordinate vector
    delete this->normals_; //erase the normals vector
    delete this->va_; //delete VAO object
}

void cube::draw() //function that is used to draw the cube
{
    this->va_->bind();  //bind the vertex array object which holds different VBA's of position, uv, normals
    /*check if index buffer is initialized.
    * if yes then call glDrawElements with triangle as topology and index buffer for drawing order.
    * else call glDrawArrays with triangle as topology and size of positions and stride
    */
    if (this->ib_ && this->ib_->get_count() > 0)
        glDrawElements(gl_topology::get_gl_topology(this->topology_),
                (GLint) this->ib_->get_count(),
                GL_UNSIGNED_INT,
                nullptr);
    else
        glDrawArrays(gl_topology::get_gl_topology(this->topology_),
                0,
                (GLint) this->positions_->get_data_size());
}

} //end of glw namespace