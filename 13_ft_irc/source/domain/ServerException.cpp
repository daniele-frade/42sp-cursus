#include "ServerException.hpp"


ServerException::ServerException(const std::exception& e, const std::string& message)
    : message_(message), original_message_(e.what()) {}

ServerException::~ServerException() throw() {}

const char* ServerException::what() const throw() {
    std::cerr << message_ << ": " << original_message_ << std::endl;
    return original_message_.c_str();
}
