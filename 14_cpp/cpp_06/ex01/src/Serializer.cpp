#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { (void)other; }
Serializer& Serializer::operator=(const Serializer& other) { (void)other; return *this; }
Serializer::~Serializer() {}

// Static method implementation for serialization.
// It casts the Data* pointer to a uintptr_t.
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// Static method implementation for deserialization.
// It casts the uintptr_t back to a Data* pointer.
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}