#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LENGTH 5

void 
reccur(FILE* file, char* line, char* characters, size_t line_index, size_t char_index, size_t number_of_chars)
{
    if (char_index == number_of_chars)
      {
          return;
      }
    line[line_index] = characters[char_index];
    if (line_index == LENGTH-1 && char_index == number_of_chars-1) 
      {
          fprintf(file, "%s\n", line);
          line[line_index] = characters[0];
          return;
      }
    else if (line_index == LENGTH-1)
      {
          fprintf(file, "%s\n", line);
          reccur(file, line, characters, line_index, char_index+1, number_of_chars);
      }
    else
      {
          reccur(file, line, characters, line_index+1, 0, number_of_chars);
          reccur(file, line, characters, line_index, char_index+1, number_of_chars);
      }
}

int 
main(void) 
{
    FILE *file = fopen("res.txt", "w");
    char upper_case[] = {'A','B','C','D','E','F','G','H','J','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char lower_case[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char numbers[] = {'0','1','2','3','4','5','6','7','8','9'};

    size_t number_of_chars = sizeof(upper_case)+sizeof(lower_case)+sizeof(numbers);

    char *character_set = (char*) malloc(number_of_chars * sizeof(char));
    memcpy(character_set, &upper_case, sizeof(upper_case));
    memcpy(character_set+sizeof(upper_case), &lower_case, sizeof(lower_case));
    memcpy(character_set+sizeof(upper_case)+sizeof(lower_case), &numbers, sizeof(numbers));

    char permutation[LENGTH+1];
    memset(permutation, character_set[0], LENGTH);
    permutation[LENGTH] = '\0';
    
    reccur(file, permutation, character_set, 0, 0, number_of_chars);

    return 0;
}