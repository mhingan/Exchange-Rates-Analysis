#include <stdio.h>
#include <stdlib.h>

struct RateSchimb {
    float data;
    float eur;
    float usd;
    float gbp;
};

void val_medie(struct RateSchimb *rateSchimb, int n);
void scriere_val_minima(struct RateSchimb *rateSchimb, int n);

int main() {
    int n;
    FILE *fp;
    char nume_fisier[] = "rate_de_schimb.txt";

    fp = fopen(nume_fisier, "r");

    if (fp == NULL) {
        printf("Eroare la deschiderea fisierului!");
        return 1;
    }

    fscanf(fp, "%d", &n);

    // Alocare memorie pentru structura
    struct RateSchimb *rateSchimb = (struct RateSchimb *) malloc(n * sizeof(struct RateSchimb));

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%f%f%f%f", &rateSchimb[i].data, &rateSchimb[i].eur, &rateSchimb[i].usd, &rateSchimb[i].gbp);
    }

    fclose(fp);

    // Apelarea funcției de valoare medie
    val_medie(rateSchimb, n);

    // Apelarea funcției de scriere a valorilor minime în fișier
    scriere_val_minima(rateSchimb, n);

    // Eliberarea memoriei alocate dinamic
    free(rateSchimb);

    return 0;
}

void val_medie(struct RateSchimb *rateSchimb, int n) {
    float suma_eur = 0;
    float suma_usd = 0;
    float suma_gbp = 0;

    for (int i = 0; i < n; i++) {
        suma_eur += rateSchimb[i].eur;
        suma_usd += rateSchimb[i].usd;
        suma_gbp += rateSchimb[i].gbp;
    }

    float result_eur = suma_eur / n;
    float result_usd = suma_usd / n;
    float result_gbp = suma_gbp / n;

    printf("\nAfișare curs mediu:\n");
    printf("EUR %.3f\n", result_eur);
    printf("USD %.3f\n", result_usd);
    printf("GBP %.4f\n", result_gbp);
}

void scriere_val_minima(struct RateSchimb *rateSchimb, int n) {
    FILE *fp;
    char nume[] = "rate_minime.txt";
    fp = fopen(nume, "w");

    if (fp == NULL) {
        printf("Eroare la deschiderea fisierului de scriere!");
        exit(1);
    }

    // Inițializarea minimelor cu valorile din prima zi
    float min_eur = rateSchimb[0].eur;
    float min_usd = rateSchimb[0].usd;
    float min_gbp = rateSchimb[0].gbp;

    // Căutarea minimelor
    for (int i = 1; i < n; i++) {
        if (rateSchimb[i].eur < min_eur) {
            min_eur = rateSchimb[i].eur;
        }
        if (rateSchimb[i].usd < min_usd) {
            min_usd = rateSchimb[i].usd;
        }
        if (rateSchimb[i].gbp < min_gbp) {
            min_gbp = rateSchimb[i].gbp;
        }
    }

    // Scrierea minimelor în fișier
    fprintf(fp, "\nValori minime:\n");
    fprintf(fp, "EUR %.3f\n", min_eur);
    fprintf(fp, "USD %.3f\n", min_usd);
    fprintf(fp, "GBP %.4f\n", min_gbp);  // Am adăugat un zero suplimentar pentru a obține precizia specificată

    // Închidere fișier de scriere
    fclose(fp);
}
