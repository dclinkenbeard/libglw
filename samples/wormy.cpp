//
// Created by Garrett on 12/7/2021.
//

#include "wormy.hpp"

#define PI glm::pi<float>()

wormy::wormy(int vertex_count, int r)
{
    std::vector<float> p;

    float slice = 2 * PI / vertex_count;

    for (auto i = 0; i < vertex_count; i ++) {
        float rads = i * slice;

        p.push_back(r * glm::cos(rads));
        p.push_back(r * glm::sin(rads));
    }

    /**
     * Changing the vert_size to anything greater than 3 will not display the wormy image
     * Changing the vert_size to 2 or even 1 will display a tiny line that moves around
     * just as the wormy does.
     */
    this->positions_ = vertex_buffer::create(p.data(), p.size(), 3);

    this->ib_ = nullptr;
    this->va_ = vertex_array::create();

    this->va_->add_vertex_buffer(this->positions_);

    this->topology_ = topology::TRIANGLE_FAN;
    this->model_ = glm::mat4(1.f);
    this->shader_ = nullptr;
}

wormy::~wormy()
{

}

void wormy::draw()
{
    this->va_->bind();

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
