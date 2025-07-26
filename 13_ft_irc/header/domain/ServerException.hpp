#ifndef SERVER_EXCEPTION_HPP
# define SERVER_EXCEPTION_HPP

# include <exception>
# include <iostream>
# include <cstring>


class ServerException : public std::exception {
    private:
        std::string message_;
        std::string original_message_;

    public:
        ServerException(const std::exception& e, const std::string& message);

        virtual ~ServerException() throw();

        const char* what() const throw();
};

#endif