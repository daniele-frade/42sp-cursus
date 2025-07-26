#ifndef IVAULT_HPP
# define IVAULT_HPP

# include <string>


class IVault {
    public:
        virtual ~IVault() {}
        virtual bool validate_password(const std::string& pass_to_validate) const = 0;
};

#endif
