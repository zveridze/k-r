# include <stdio.h>
#define MAXIMUM 1000

void update_line(char original[], char new[], char new_line[]);
int any(char start_line[], char exclude[]);

int main()
{
    char start_line[] = "abcd";
    char exclude[] = "a";
    char new_line[MAXIMUM];
    int position;
    // update_line(start_line, exclude, new_line);
    // printf("%s\n", new_line);
    // any(start_line, exclude);
    position = any(start_line, exclude);
    printf("%i\n", position);
    return 0;
}

void update_line(char start_line[], char exclude[], char new_line[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    int excluded;
    while (start_line[i] != '\0')
    {
        excluded = 0;
        while(exclude[j] != '\0')
        {
            if (start_line[i] == exclude[j])
            {
                excluded = 1;
                break;
            }
            j++;
        }
        if (excluded == 0)
        {
            new_line[k] = start_line[i];
            k++;
        }
        i++;
        j = 0;
    }
}

int any(char start_line[], char exclude[])
{
    int i = 0;
    int j = 0;
    int position = -1;
    while (start_line[i] != '\0')
    {
        while(exclude[j] != '\0')
        {
            // printf("%c", start_line[i]);
            // printf("%c", exclude[j]);
            if (start_line[i] == exclude[j] && position == -1)
            {
                position = i;
                return position;
            }
            j++;
        }
        i++;
        j = 0;
    }
    return position;
}