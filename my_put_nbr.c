void my_putchar(char c);

int my_put_nbr(int nb)
{
    int modulo = 0;

    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        modulo = nb % 10;
        my_put_nbr(nb / 10);
        my_putchar(modulo + 48);
    }
    return (0);
}

int my_put_nbr_a(unsigned int nb)
{
    int modulo = 0;

    if (nb  && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        modulo = nb % 10;
        my_put_nbr(nb / 10);
        my_putchar(modulo + 48);
    }
    return (0);
}
