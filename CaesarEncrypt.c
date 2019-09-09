#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // need to check if exactly one extra argument is given
    if (argc == 2)
    {
        // turn the argument into an int if its text than return false
        int k = atoi(argv[1]);
        string plainText = get_string("plaintext: ");

        for (int i = 0, n = strlen(plainText); i < n; i++)
        {
            // checking if cgaracter is alpha if yes than encrypt
            // else just leave the char the way
            if (isalpha(plainText[i]))
            {
                if (islower(plainText[i]))
                {
                    plainText[i] = (plainText[i] - 'a' + k) % 26 + 97;
                }
                else
                {
                    plainText[i] = (plainText[i] - 'A' + k) % 26 + 65;
                }

            }
        }
        printf("ciphertext: %s\n", plainText);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
