#ifndef VAULT_HPP
# define VAULT_HPP

# include <string>
# include <stdexcept>
# include <cctype>

# include "interfaces/IVault.hpp"

class Vault : public IVault {
    private:
        std::string _password;

        bool _is_valid_password(const std::string& password);

    public:
        Vault(const std::string& password);
        ~Vault();

        bool validate_password(const std::string& pass_to_validate) const;
};

#endif
