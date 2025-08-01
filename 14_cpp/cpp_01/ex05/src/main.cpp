#include "Harl.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }

    Harl harl;
    harl.complain(argv[1]);
    return 0;
}