#ifndef EDGE_H
#define EDGE_H

#include <cstddef>

class Edge
{
public:
    Edge() = default;
    Edge(std::size_t from_id, std::size_t to_id);
    Edge(const Edge &edge) = default;
    ~Edge() = default;

    std::size_t getFrom() const;
    std::size_t getTo() const;

    void setFrom(const std::size_t id);
    void setTo(const std::size_t id);
private:
    std::size_t from_id, to_id;
};

#endif // EDGE_H
