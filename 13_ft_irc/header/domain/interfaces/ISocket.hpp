#ifndef ISOCKET_HPP
# define ISOCKET_HPP


class ISocket {
    public:
        virtual ~ISocket() {}
        virtual int get_fd() const = 0;
};

#endif
