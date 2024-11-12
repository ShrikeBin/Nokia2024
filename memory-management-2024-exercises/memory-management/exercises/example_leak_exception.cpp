#include <resources/kernel_resource.h>
#include <iostream>

#include <stdexcept> // std::runtime_error

void kernel_stress_test()
{
    RESOURCE* resource = nullptr;

    try
    {
        // will return NULL if:
        // 1. allocation was not successful
        // will THROW std::runtime_error if:
        // 1. sometimes, due to internal reasons (wrap in try-catch!)
        resource = allocate_resource();

        // Check if allocation was successful
        if (resource == nullptr) 
        {
            throw std::runtime_error("resource == NULL");
        }

        // will THROW std::runtime_error if:
        // 1. sometimes, with no particular reason (wrap in try-catch!)
        // will CRASH (std::terminate) if:
        // 1. resource is NULL (add NULL-check!)
        // 2. resource was already released
        use_resource(resource);
    }
    catch (const std::runtime_error& e)
    {          
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // will CRASH (std::terminate) if:
    // 1. resource is NULL (add NULL-check!)
    // 2. resource is already released
    if (resource != nullptr) 
    {
        free_resource(resource);
    } 
    else 
    {
        std::cerr << "Attempted free on NULL" << std::endl;
    }
}

int main(int ac, char* av[])
{
    constexpr int repetitions = 32;

    for (int i = 0; i < repetitions; ++i) { kernel_stress_test(); }

    // the program will CRASH (std::terminate) if:
    // 1. there are resources not yet released on exit
    return 0;
}
