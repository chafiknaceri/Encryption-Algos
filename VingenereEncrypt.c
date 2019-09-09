#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int shift(char c);
bool checkIsAlpha(string c);
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (checkIsAlpha(argv[1]))
        {
            string plainText = get_string("plaintext: ");
            int Extrakey = 0;

            for (int i = 0, n = strlen(plainText); i < n; i++)
            {
                // using modulo to wraparound the key so that it wraps
                // back to first letter when it is all used
                int key = shift(argv[1][Extrakey % strlen(argv[1])]);
                // checking if cgaracter is alpha if yes than encrypt
                // else just leave the char the way
                if (isalpha(plainText[i]))
                {
                    if (islower(plainText[i]))
                    {
                        plainText[i] = (plainText[i] - 'a' + key) % 26 + 97;
                    }
                    else
                    {
                        plainText[i] = (plainText[i] - 'A' + key) % 26 + 65;
                    }
                    Extrakey += 1;

                }

            }
            printf("ciphertext: %s\n", plainText);
        }
        else
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}

int shift(char c)
{
    c = tolower(c);
    return c - 'a'; // calculating the shift number
}

// Creating a function that returns true or false
// takes in a string and checks if any non alpha characters
bool checkIsAlpha(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isalpha(s[i]))
        {
            // returns false and gets out of function
            return false;
        }
    }
    return true;
}
