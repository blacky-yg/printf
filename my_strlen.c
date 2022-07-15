int my_strlen(char const *str)
{
    int compt;

    compt = 0;
    while (str[compt] != '\0') {
        compt++;
    }
    return (compt);
}
