#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void cevap_anahtari_uret(char cevap_anahtari[], int S)
{
    srand(time(0));
    printf("\nCevap anahtari:\n");

    for (int i = 0; i < S; i++)
    {
        cevap_anahtari[i] = rand() % 5 + 65;
    }
}
void cevap_anahtari_yazdir(char cevap_anahtari[], int S)
{
    for (int i = 0; i < S; i++)
    {
        printf(" %0.3d: %c  |", i + 1, cevap_anahtari[i]);
    }
    printf("\n\n");

}
void sinavi_uygula(char ogrenci_cevaplari[][100], char cevap_anahtari[], int N, int S, double B, double D)
{
    int i, j;
    srand(time(0));
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < S; j++)
        {
            double a = rand() % 100;
            if (a / 100 > B)
            {
                double c = rand() % 100;
                if (c / 100 < D)
                {
                    ogrenci_cevaplari[i][j] = cevap_anahtari[j];
                }
                else
                {
                    ((ogrenci_cevaplari[i][j] != 'X') && (ogrenci_cevaplari[i][j] != cevap_anahtari[j]) && (ogrenci_cevaplari[i][j] = rand() % 5 + 65));

                }

            }
            else
                ogrenci_cevaplari[i][j] = 'X';
        }
    }
}

void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100], int ogrenci_ID, int S)
{
    for (int i = 0; i < S; i++) {
        printf("%0.3d: %c  |", i + 1, ogrenci_cevaplari[ogrenci_ID][i]);
    }
    printf("\n");
}
void ogrencileri_puanla(char ogrenci_cevaplari[][100], char cevap_anahtari[], double HBN[], int N, int S)
{
    int i, j;
    double a = 100 / (double)S;


    for (i = 0; i < N; i++)
    {
        double pozitif = 0, negatif = 0;

        HBN[i] = 0;

        for (j = 0; j < S; j++)
        {
            if (cevap_anahtari[j] == ogrenci_cevaplari[i][j])
            {

                HBN[i] += a;

            }
            else if (ogrenci_cevaplari[i][j] == 'X')
            {
                ;
            }
            else
            {
                HBN[i] -= a / 4;
            }

        }
        if (HBN[i] <= 0)
            HBN[i] = 0;

    }

}
double sinif_ortalamasi_hesapla(double HBN[], int N)
{
    printf("\n\n");
    double ortalama = 0;
    double ort = 0.0;
    for (int i = 0; i < N; i++)
    {
        ort += HBN[i];
    }
    ortalama = ort / (double)N;
    return ortalama;
}
double standart_sapma_hesapla(double ortalama, double HBN[], int N)
{
    int i;
    double stdsapma = 0.0;
    for (i = 0; i < N; i++)
    {
        stdsapma = sqrt(pow((HBN[i] - ortalama), 2) / (N));
    }
    return stdsapma;
}
void T_skoru_hesapla(double ortalama, double HBN[], int N, double std, double T_skoru[])
{
    int i;

    for (i = 0; i < N; i++)
    {
        T_skoru[i] = 60 + 10 * ((HBN[i] - ortalama) / std);
        if (T_skoru[i] > 100)
        {
            T_skoru[i] = 100;
        }
        else if (T_skoru[i] < 0)
        {
            T_skoru[i] = 0;
        }

        if ((100 >= ortalama) && (ortalama > 80.0))
        {

            if (T_skoru[i] >= 67)
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: AA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 62) && (T_skoru[i] <= 66.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 57) && (T_skoru[i] <= 61.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 52) && (T_skoru[i] <= 56.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 47) && (T_skoru[i] <= 51.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 42) && (T_skoru[i] <= 46.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 37) && (T_skoru[i] <= 41.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 32) && (T_skoru[i] <= 36.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] < 32))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FF\n", i + 1, HBN[i], T_skoru[i]);


        }
        else if ((80.0 >= ortalama) && (ortalama > 70.0))
        {

            if (T_skoru[i] >= 69)
                printf(" T-skoru: %0.2lf  ,Harf Notu: AA\n", T_skoru[i]);
            else if ((T_skoru[i] >= 64) && (T_skoru[i] <= 68.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 59) && (T_skoru[i] <= 63.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 54) && (T_skoru[i] <= 58.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 49) && (T_skoru[i] <= 53.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 44) && (T_skoru[i] <= 48.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 39) && (T_skoru[i] <= 43.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 34) && (T_skoru[i] <= 38.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] < 34))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FF\n", i + 1, HBN[i], T_skoru[i]);

        }
        else if ((70.0 >= ortalama) && (ortalama > 62.5))
        {

            if (T_skoru[i] >= 71)
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: AA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 66) && (T_skoru[i] <= 70.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 61) && (T_skoru[i] <= 65.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 56) && (T_skoru[i] <= 60.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 51) && (T_skoru[i] <= 55.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 46) && (T_skoru[i] <= 50.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 41) && (T_skoru[i] <= 45.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 36) && (T_skoru[i] <= 40.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] < 36))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FF\n", i + 1, HBN[i], T_skoru[i]);


        }
        else if ((57.5 < ortalama) && (ortalama <= 62.5))
        {

            if (T_skoru[i] >= 73)
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: AA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 68) && (T_skoru[i] <= 72.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 63) && (T_skoru[i] <= 67.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 58) && (T_skoru[i] <= 62.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 53) && (T_skoru[i] <= 57.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 48) && (T_skoru[i] <= 52.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 43) && (T_skoru[i] <= 47.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 38) && (T_skoru[i] <= 42.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] < 38))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FF\n", i + 1, HBN[i], T_skoru[i]);

        }
        else if ((52.5 < ortalama) && (ortalama <= 57.5))
        {

            if (T_skoru[i] >= 75)
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: AA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 70) && (T_skoru[i] <= 74.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 65) && (T_skoru[i] <= 69.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 60) && (T_skoru[i] <= 64.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 55) && (T_skoru[i] <= 59.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 50) && (T_skoru[i] <= 54.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 45) && (T_skoru[i] <= 49.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 40) && (T_skoru[i] <= 44.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] < 40))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FF\n", i + 1, HBN[i], T_skoru[i]);

        }
        else if ((47.5 < ortalama) && (ortalama <= 52.5))
        {
            if (T_skoru[i] >= 77)
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: AA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 72) && (T_skoru[i] <= 76.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 67) && (T_skoru[i] <= 71.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 62) && (T_skoru[i] <= 66.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 57) && (T_skoru[i] <= 61.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 52) && (T_skoru[i] <= 56.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 47) && (T_skoru[i] <= 51.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 42) && (T_skoru[i] <= 46.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] < 42))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FF\n", i + 1, HBN[i], T_skoru[i]);

        }
        else if ((42.5 < ortalama) && (ortalama <= 47.5))
        {

            if (T_skoru[i] >= 79)
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: AA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 74) && (T_skoru[i] <= 78.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 69) && (T_skoru[i] <= 73.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 64) && (T_skoru[i] <= 68.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 59) && (T_skoru[i] <= 63.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 54) && (T_skoru[i] <= 58.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 49) && (T_skoru[i] <= 53.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 44) && (T_skoru[i] <= 48.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] < 44))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FF\n", i + 1, HBN[i], T_skoru[i]);

        }
        else if (ortalama <= 42.5)
        {

            if (T_skoru[i] >= 81)
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: AA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 76) && (T_skoru[i] <= 80.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BA\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 71) && (T_skoru[i] <= 75.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 66) && (T_skoru[i] <= 70.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: BB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 61) && (T_skoru[i] <= 65.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CB\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 56) && (T_skoru[i] <= 60.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: CC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 51) && (T_skoru[i] <= 55.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DC\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] >= 46) && (T_skoru[i] <= 50.99))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: DD\n", i + 1, HBN[i], T_skoru[i]);
            else if ((T_skoru[i] < 46))
                printf(" %0.2d. ogrencinin HBN: %0.2lf  , T-skoru: %0.2lf  ,Harf Notu: FF\n", i + 1, HBN[i], T_skoru[i]);

        }
    }



}

int main()
{
    int N, S, i, j;

    double B, D;
    char cevap_anahtari[100];
    int ogrenci_ID;
    char ogrenci_cevaplari[100][100];
    double HBN[100];
    char sinifin_duzeyi;
    double std;
    double T_skoru[100];

    printf("Ogrenci sayisini giriniz (max 100): ");
    scanf("%d", &N);

    printf("Soru sayisini giriniz(max 100): ");
    scanf("%d", &S);

    printf("Bos birakma ihtimalini giriniz(0.0~1.0): ");
    scanf("%lf", &B);

    printf("Dogru cevap verme ihtimalini giriniz(0.0~1.0): ");
    scanf("%lf", &D);

    cevap_anahtari_uret(cevap_anahtari, S);
    cevap_anahtari_yazdir(cevap_anahtari, S);
    sinavi_uygula(ogrenci_cevaplari, cevap_anahtari, N, S, B, D);
    printf("----- Ogrenci Cevaplari ----\n");
    for (int k = 0; k < N; k++) {
        printf("%0.3d. Ogrencinin cevaplari: \n", k + 1);
        ogrenci_cevabini_yazdir(ogrenci_cevaplari, k, S);
    }
    printf("\n\n\n");
    ogrencileri_puanla(ogrenci_cevaplari, cevap_anahtari, HBN, N, S);


    double ortalama = sinif_ortalamasi_hesapla(HBN, N);
    double stdsapma = standart_sapma_hesapla(ortalama, HBN, N);
    printf(" Sinif ortalamasi: %0.2lf ,standart sapma: %0.2lf\n", ortalama, stdsapma);
    if ((100 >= ortalama) && (ortalama > 80.0))
    {
        printf(" Sinifin duzeyi: Ustun Basari\n\n");
    }
    else if ((80.0 >= ortalama) && (ortalama > 70.0))
    {
        printf(" Sinifin duzeyi: Mukemmel\n\n");
    }
    else if ((70.0 >= ortalama) && (ortalama > 62.5))
    {
        printf(" Sinifin duzeyi: Cok Iyý\n\n");
    }
    else if ((57.5 < ortalama) && (ortalama <= 62.5))
    {
        printf(" Sinifin duzeyi: Iyý\n\n");
    }
    else if ((52.5 < ortalama) && (ortalama <= 57.5))
    {
        printf(" Sinifin duzeyi: Ortanin Ustu\n\n");
    }
    else if ((47.5 < ortalama) && (ortalama <= 52.5))
    {
        printf(" Sinifin duzeyi: Orta\n\n");
    }
    else if ((42.5 < ortalama) && (ortalama <= 47.5))
    {
        printf(" Sinifin duzeyi: Zayif\n\n");
    }
    else if (ortalama <= 42.5)
    {
        printf(" Sinifin duzeyi: Kotu\n\n");
    }


    T_skoru_hesapla(ortalama, HBN, N, stdsapma, T_skoru);


    return 0;
}

