#include <bitset>
#include <cctype>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

void printConversions(std::int32_t number)
{
    std::uint32_t unsignedNumber = static_cast<std::uint32_t>(number);

    std::cout << "\nConversions:\n";
    std::cout << "Signed decimal:   " << std::dec << number << '\n';
    std::cout << "Unsigned decimal: " << std::dec << unsignedNumber << '\n';
    std::cout << "Binary:           " << std::bitset<32>(unsignedNumber) << '\n';
    std::cout << "Octal:            " << std::oct << unsignedNumber << '\n';
    std::cout << "Hexadecimal:      " << std::hex << std::uppercase
              << unsignedNumber << std::nouppercase << '\n';
    std::cout << std::dec;

    if (number >= 0 && number <= 127)
    {
        if (number == 0)
        {
            std::cout << "ASCII:            NUL (0)\n";
        }
        else if (number >= 32 && number <= 126)
        {
            std::cout << "ASCII:            '" << static_cast<char>(number) << "'\n";
        }
        else
        {
            std::cout << "ASCII:            non-printable control character\n";
        }
    }
    else
    {
        std::cout << "ASCII:            not in the 0-127 range\n";
    }
}

bool readDecimal(std::int32_t& number)
{
    std::string input;
    std::getline(std::cin, input);

    std::size_t parsedCharacters;
    std::int64_t value;
    try
    {
        value = std::stoll(input, &parsedCharacters, 10);
    }
    catch (const std::exception&)
    {
        std::cout << "Invalid input. Please enter an integer.\n";
        return false;
    }

    if (parsedCharacters != input.size())
    {
        std::cout << "Invalid input. Please enter an integer.\n";
        return false;
    }

    if (value < std::numeric_limits<std::int32_t>::min() ||
        value > std::numeric_limits<std::int32_t>::max())
    {
        std::cout << "That value is outside the 32-bit signed range "
                  << "(" << std::numeric_limits<std::int32_t>::min()
                  << " to " << std::numeric_limits<std::int32_t>::max() << ").\n";
        return false;
    }

    number = static_cast<std::int32_t>(value);
    return true;
}

bool parseReverse(std::uint32_t& number)
{
    std::cout << "Choose source base (2, 8, or 16): ";
    int base;
    std::cin >> base;

    if (!std::cin || (base != 2 && base != 8 && base != 16))
    {
        std::cout << "Invalid base. Choose 2, 8, or 16.\n";
        return false;
    }

    std::string input;
    std::cout << "Enter the value: ";
    std::cin >> input;

    if (input.empty())
    {
        std::cout << "Invalid value.\n";
        return false;
    }

    std::uint64_t value = 0;
    for (char character : input)
    {
        char digit = static_cast<char>(std::tolower(
            static_cast<unsigned char>(character)));

        unsigned int digitValue;
        if (digit >= '0' && digit <= '9')
        {
            digitValue = static_cast<unsigned int>(digit - '0');
        }
        else if (digit >= 'a' && digit <= 'f')
        {
            digitValue = static_cast<unsigned int>(digit - 'a' + 10);
        }
        else
        {
            std::cout << "Invalid character in source value.\n";
            return false;
        }

        if (digitValue >= static_cast<unsigned int>(base))
        {
            std::cout << "Invalid digit for base " << base << ".\n";
            return false;
        }

        if (value > (std::numeric_limits<std::uint32_t>::max() - digitValue) /
                        static_cast<std::uint32_t>(base))
        {
            std::cout << "That value is outside the 32-bit unsigned range.\n";
            return false;
        }

        value = value * static_cast<std::uint32_t>(base) + digitValue;
    }

    number = static_cast<std::uint32_t>(value);
    return true;
}

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    while (true)
    {
        std::cout << "\nNumber System Converter\n";
        std::cout << "1. Convert a signed 32-bit decimal integer\n";
        std::cout << "2. Convert from binary, octal, or hexadecimal\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";

        int option;
        std::cin >> option;

        if (!std::cin)
        {
            clearInput();
            std::cout << "Invalid option.\n";
            continue;
        }

        if (option == 3)
        {
            std::cout << "Goodbye!\n";
            break;
        }

        if (option == 1)
        {
            clearInput();
            std::cout << "Enter a decimal integer: ";

            std::int32_t number;
            if (readDecimal(number))
            {
                printConversions(number);
            }
        }
        else if (option == 2)
        {
            clearInput();
            std::uint32_t number;
            if (parseReverse(number))
            {
                std::cout << "\nDecimal: " << number << '\n';
                printConversions(static_cast<std::int32_t>(number));
            }
        }
        else
        {
            clearInput();
            std::cout << "Invalid option. Choose 1, 2, or 3.\n";
        }
    }

    return 0;
}
