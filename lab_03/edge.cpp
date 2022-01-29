#include "edge.h"

Edge::Edge(const std::size_t from_id, const std::size_t to_id)
    : from_id(from_id), to_id(to_id){};

std::size_t Edge::getFrom() const {
    return from_id;
}

std::size_t Edge::getTo() const {
    return to_id;
}

void Edge::setFrom(const std::size_t id) {
    from_id = id;
}

void Edge::setTo(const std::size_t id) {
    to_id = id;
}
