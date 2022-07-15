char *my_revstr(char *str)
{
    int compt;
    char permut;
    int div;
    int i = 0;

    compt = 0;
    while (str[compt] != '\0') {
        compt++;
    }
    div = compt / 2;
    compt--;
    for (i = 0; i < div; i++) {
        permut = str[i];
        str[i] = str[compt];
        str[compt] = permut;
        compt--;
    }
    return (str);
}
