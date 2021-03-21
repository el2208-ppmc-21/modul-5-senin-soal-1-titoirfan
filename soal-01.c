#include <stdio.h>

int isEven(int x)
{
    if (x % 2 == 0)
        return 1;
    else
        return 0;
}

int tileCount(int m, int n)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    else if (isEven(m) && isEven(n))
    {
        return tileCount(m / 2, n / 2); // kalo sama sama genap, berarti jumlah tile sama aja kayak kalo ukuran dibagi 2
                                        // contoh: jumlah ubin untuk 10,10 == jumlah ubin untuk 5,5
    }

    else if (isEven(m) && !isEven(n))
    {
        return m + tileCount(m / 2, n / 2); // contoh: 6x5; di sisi paling kiri diisi penuh 1x1
                                            // jadi 5 + tileCount(6, 4),
                                            // karena sama sama genap jadi 5 + tileCount(3,2)
    }

    else if (!isEven(m) && isEven(n))
    {
        return n + tileCount(m / 2, n / 2); // ^sama
    }

    else
        return n + m - 1 + tileCount(m / 2, n / 2); // Sama kayak satu ganjil, tapi ini sekeliling ukuran genap
                                                    // di isi 1x1 jadi n+m-1
}

int main()
{
    int m, n;

    printf("Masukkan panjang ruangan: ");
    scanf("%d", &m);
    printf("Masukkan lebar ruangan: ");
    scanf("%d", &n);

    printf("Jumlah ubin minimum: %d", tileCount(m, n));
}
