#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <sstream>
# include <string>


class Utils {
    private:
        static void validate_args(int ac, const char* program_name);
        static int  get_port(const char* input);

    public:
        static std::string  get_time();
        static int          set_port(int argc, char** argv);
};

#endif