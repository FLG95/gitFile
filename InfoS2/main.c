/*#include <stdio.h>
#include <math.h>


struct Point{
    float x;
    float y;
};

struct Point  ConstructeurPoint(){
    struct Point p;
    float x, y;
    printf("enter cord x et y");
    scanf("%f %f", &x, &y);
    p.x = x;
    p.y = y;
    return(p);
}

void affiche_Point(struct Point a){
    printf(" %f %f", a.x, a.y);
}

struct Point ajouter_Point(struct Point a, struct Point b){
    struct Point p;
    p.x = a.x + b.x;
    p.y = a.y + b.y;
    return(p);
}

float longueur(struct Point a, struct Point b){

    float d = sqrt(pow((a.x - b.x), 2)  + pow((a.y - b.y),2));
    return(d);
}

int estCarre(struct Point a, struct Point b, struct Point c, struct Point d){

    float d1 = sqrt(pow((a.x - b.x), 2)  + pow((a.y - b.y),2));
    float d2 = sqrt(pow((b.x - c.x), 2)  + pow((b.y - c.y),2));
    float d3 = sqrt(pow((c.x - d.x), 2)  + pow((c.y - d.y),2));
    float d4 = sqrt(pow((d.x - a.x), 2)  + pow((d.y - a.y),2));

    if(d1 == d2 && d2 == d3 && d3 == d4 && d4 == d1){
        printf("1");
        return(1);
    }
    else{ return(0);}
}

int sontAlignes(struct Point a, struct Point b, struct Point c){

    struct Point v1;
    struct Point v2;
    v1.x = b.x - a.x;
    v1.y = b.y - a.y;
    v2.x = c.x - b.x;
    v2.y = c.y - b.y;

    if(((v1.x  * v2.y) - (v1.y * v2.x)) == 0){
        return(1);
    }
    else{
        return(0);
    }



}

int main() {
    struct Point p1 = ConstructeurPoint();
    struct Point p2 = ConstructeurPoint();
    struct Point p3 = ConstructeurPoint();
    //struct Point p4 = ConstructeurPoint();

    struct Point s = ajouter_Point(p1, p2);

    //printf("%f %f", s.x, s.y);
    //printf(" l = %f", longueur(p1, p2));
    //printf(" l = %f", longueur(p2, p3));

    //int a = estCarre(p1, p2, p3, p4);
    //printf("%d", a);

    int b = sontAlignes(p1, p2, p3);
    printf("%d", b);
}*/


//EX 2 pas fini grosse flemme
/*#include <stdio.h>

struct date{
    int j;
    int m;
    int a;
};

int mois(struct date a) {
    switch(a.m){
        case 1: return 31;
        case 2:
            if((a.a % 4) == 0){
                return(29);
            }
            else{
                return(28);
            }
        case 3: return(31);
        case 4: return(30);
        case 5: return(31);
        case 6: return(30);
        case 7: return(31);
        case 8: return(31);
        case 9: return(30);
        case 10: return(31);
        case 11: return(30);
        case 12: return(31);
        default : return 0;
    }
}

struct date constructeur_date(){
    struct date a;

    printf("jour : ");
    scanf("%d", &a.j);
    printf("mois : ");
    scanf("%d", &a.m);
    printf("anné : ");
    scanf("%d", &a.a);
    return(a);
}

void affiche_Date(struct date a){

    printf("%d / %d / %d", a.j , a.m, a.a);
}

struct date ajoute_jour(struct date a, int jour){
    struct date b;
    int tj;
    int ta;
    if((a.a%4) == 0)
        ta = 366;
    else{
        ta = 365;
    }
    if((a.j + jour) < mois(a)){
        b = a;
        b.j = b.j + jour;
        return (b);
    }
    else{
        tj = a.j + a.m * mois(a) + a.a * ta;

    }
}


int main(){

    struct date d;
    d = constructeur_date();
    affiche_Date(d);
}*/

//EX 3
/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct ninja{
    float atk;
    float def;
    float dodge;
    float pv;
    char name[100];
};


void fight(struct ninja a, struct ninja b){
    int c = 0;
    float n = 0, damage = 0;
    printf("\n%s\n", a.name);

    while(a.pv > 0 && b.pv > 0){
        c++;
        printf("Round : %d \n", c);

        //Ninja A attaque
        printf("%s", a.name);

        n = ((1 - 0) * ((float)rand() / RAND_MAX)) + 0;
        printf("n: %f \n", n);

        if( n > a.dodge){// on touche
            damage = a.atk - b.def;
            if(damage < 0){
                damage = 0;
            }
            printf("damages : %f \n", damage);
            b.pv = b.pv - damage;
            if(b.pv <= 0){
                printf("%s win", a.name);
            }
            else{
                printf("pv restant : %f \n", b.pv);
            }
        }
        else{
            printf("%s miss \n", a.name);
        }

        if( b.pv > 0){
            //Ninja B attaque
            printf("%s attaque \n", b.name);

            n = ((1 - 0) * ((float)rand() / RAND_MAX)) + 0;
            printf("n: %f \n", n);

            if( n > b.dodge){// on touche
                damage = b.atk - a.def;
                if(damage < 0){
                    damage = 0;
                }
                printf("damages : %f \n", damage);
                a.pv = a.pv - damage;
                if(a.pv <= 0){
                    printf("%s win", b.name);
                }
                else{
                    printf("pv restant : %f \n", a.pv);
                }
            }
            else{
                printf("%s miss \n", b.name);
            }

        }
    }
}

int main(){

    srand(time(NULL));

    struct ninja p1;
    struct ninja p2;

    printf("Player 1 choose name");
    scanf("%s", p1.name);
    p1.atk = ((10 - 5) * ((float)rand() / RAND_MAX)) + 5;
    printf("ATK: %f\n", p1.atk);
    p1.def = ((4 - 2) * ((float)rand() / RAND_MAX)) + 2;
    printf("DEF: %f\n", p1.def);
    p1.dodge = ((0.2 - 0.1) * ((float)rand() / RAND_MAX)) + 0.1;
    printf("DODGE: %f\n", p1.dodge);
    p1.pv = ((100 - 80) * ((float)rand() / RAND_MAX)) + 80;
    printf("PV: %f\n", p1.pv);

    printf("Player 2 choose name");
    scanf("%s", p2.name);
    p2.atk = ((10 - 5) * ((float)rand() / RAND_MAX)) + 5;
    printf("ATK: %f\n", p2.atk);
    p2.def = ((4 - 2) * ((float)rand() / RAND_MAX)) + 2;
    printf("DEF: %f\n", p2.def);
    p2.dodge = ((0.2 - 0.1) * ((float)rand() / RAND_MAX)) + 0.1;
    printf("DODGE: %f\n", p2.dodge);
    p2.pv = ((100 - 80) * ((float)rand() / RAND_MAX)) + 80;
    printf("PV: %f\n", p2.pv);

    fight(p1, p2);

}*/

//EX4
/*
#include<stdio.h>

const int cst = 3;

struct date{
    int j;
    int m;
    int a;
};

struct Personne{
    char name[100];
    struct date date_aniv;
};

struct date constructeur_date(){
    struct date a;

    printf("jour : ");
    scanf("%d", &a.j);
    printf("mois : ");
    scanf("%d", &a.m);
    printf("anné : ");
    scanf("%d", &a.a);
    return(a);
}

void bonAniv(struct Personne a[], struct date date){

    for(int i=0; i<cst; i++){
        if(a[i].date_aniv.j == date.j && a[i].date_aniv.m == date.m){
            printf("Bon aniv %s", a[i].name);
        }
    }
}

int main(){

    struct Personne tab[cst];
    struct date date;

    for(int i = 0; i<cst; i++){
        printf("Nom : ");
        scanf("%s", tab[i].name);
        printf("Date : ");
        tab[i].date_aniv = constructeur_date();
    }
    printf("date du jour : ");
    date = constructeur_date();

    bonAniv(tab, date);
}*/




//TD2
//EX3 pas compris
/*
#include<stdio.h>

int ajouteSeconde(int h, int min, int s, int somme){

    int* h1;
    int* min1;
    int* s1;



}



int main(){

    int h = 0, min = 0, s = 0, somme = 0;

    printf("Entrer les heure");
    scanf("%d", &h);

    printf("Entrer les minutes");
    scanf("%d", &min);

    printf("Entrer les secondes");
    scanf("%d", &s);

    printf("Combien de seconde à ajouter");
    scanf("%d", s);

    ajouteSeconde(time, s);

}*/

//EX4
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
    int tab[20];
    int somme = 0;

    int* p = tab;
    for(int i = 0; i<20;i++){

        tab[i] = (int)rand() % 11;
        printf(" %d", tab[i]);
    }

    for(int i = 0; i<20;i++){

        somme += *p;
        printf(" %d\n", somme);
        p += 1;
    }

    printf(" %d", somme);
}*/



//EX5
/*
#include <stdio.h>
#include <math.h>

int resoudre1(float a, float b, float *res){

    if(a == 0 && b == 0){
        return -1;
    }
    else if (a == 0 && b != 0){

        return 0;
    }
    else{
        *res = -b/a;
        return 1;
    }
}

int resoudre2(float a, float b, float c, float* res1, float* res2){

    int delta = pow(b, 2) - 4 * a * c;

    if(delta < 0){
        return 0;
    }
    else if(delta == 0){
        *res1 = -b/2*a;
        return 1;
    }
    else{
        *res1 = (-b + sqrt(delta)) /2*a;
        *res2 = (-b - sqrt(delta)) /2*a;
        return 2;
    }
}

int main(){
    float a = 0, b = 0, c = 0;
    int sol = 0;
    int sol2 = 0;
    float res;
    float res1;
    float res2;
    float* pres = &res;
    printf("a : ");
    scanf("%f", &a);

    printf("b : ");
    scanf("%f", &b);

    printf("c : ");
    scanf("%f", &c);

    //sol = resoudre1(a, b, &res);
    sol2 = resoudre2(a, b, c, &res1, &res2);

    if(sol==0){
        printf("pas de solution");
    }
    else if ( sol == -1){
        printf ("tout x est solution");
    }
    else if(sol == 1){
        printf("1 solution : %f", res);
    }



    switch(sol2){
        case 0:
            printf(("pas de solution"));
            break;
        case 1:
            printf("1 solution : %f", res1);
            break;
        case 2:
            printf("2 solutions : %f", res2);
            break;
        default:
            printf("error");
            break;
    }
}*/

//EX6
/*
#include <stdio.h>
#include <math.h>

void cartesian2polar(float x, float y, float* radius, float* angle){

        *radius = sqrt(pow(x,2) + pow(y,2));

        if(radius == 0){
            *angle = 0;
        }
        else{
            *angle = atan2(y,x);
        }
}

void polar2cartesian(float radius, float angle, float* x, float* y){
    *x = radius * cos(angle);
    *y = radius * sin((angle));

}


int main(){
    float a = 0, b = 0;
    float radius, angle;

    printf("x : ");
    scanf("%f", &a);
    printf("y : ");
    scanf("%f", &b);

    cartesian2polar(a, b,&radius, &angle);
    printf("(%f, %f)", radius, angle);

    polar2cartesian(radius, angle, &a, &b);
    printf("(%f, %f)", a, b);

}*/

//EX7
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 10;

int getExtrenums(int tab[], int* max, int *min){
    *max = tab[0];
    *min = tab[0];

    for(int i = 0; i < N; i++){
        if(tab[i] > *max){
            *max = tab[i];
        }

        if(tab[i] < *min){
            *min = tab[i];
        }
        printf("%d", i);
    }

    if(*max == '0' || *min == '0'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    int tab[N];
    int max, min, res;

    srand((time(NULL)));

    for (int i = 0; i < N; ++i) {
        tab[i] = rand() % 20;
        printf("%d ", tab[i]);
    }

    res = getExtrenums(tab, &max, &min);
    if( res == 1){
        printf(" Erreur");
    }
    else if (res == 0){
        printf("Max : %d \nMin : %d", max, min);
    }
}*/

//EX8
/*
#include <stdio.h>
#include <string.h>

int main(){

    char tab[100];
    char tab2[100];
    int length, bool = 1;
    printf("Enter le contenue");
    scanf("%s", tab);

    length = strlen(tab);
    printf("%d\n", length);

    int k = length - 1;
    char* p1 = &tab[0];
    char* p2 = &tab[length -1];

    for(int i = 0; i< length; i++){

        //tab2[k] = tab[i];
        *p1 = *p2;
        //k--;
        printf("%c", *p1);

        if(*p1 != *p2){
            if(p1 != p2){
                bool = 0;
            }
        }

        p1++;
        p2--;
    }
    printf("%c", *p1);


    switch(bool){
        case 0:
            printf(" pas palindrome");
            break;
        case 1:
            printf(" palindrome");
            break;

    }

}*/


//TD3

//EX2

/*
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int *randtab(int n, int x, int y){



    int *tab = NULL;

    tab = malloc(n*sizeof(int));

    if(tab==NULL) {
        printf("Allocation échouée !");
        exit(1);
    }

    for (int i = 0; i < n; ++i) {
        tab[i] = (rand() % ((y-x) +1) + x);
    }
    return tab;
}


int* tabpair(int tab[], int taille, int* pcase){
    int* pair =NULL;
    int j = 0;
    for (int k = 0; k < taille; ++k) {

        if ((tab[k] % 2) == 0) {
            j++;
        }
    }
    pair = malloc((j)*sizeof(int));

    if(pair==NULL){
        printf("Allocation échoué");
        exit(1);
    }
    int k = 0;
    for (int i = 0; i < taille; ++i) {
        if((tab[i] %2) == 0){
            pair[k] = tab[i];
            k++;
        }
    }
    *pcase = k;
    return pair;
}

int main(){
    int n = 0, x = 0, y = 0;
    int pn;
    srand(time(NULL));

    printf("n: ");
    scanf("%d", &n);
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);


    int* tab=NULL;
    int* pair=NULL;

    tab = randtab(n, x, y);
    pair = tabpair(tab, n, &pn);

    for (int i = 0; i < n; ++i) {
        printf("%d", tab[i]);
    }

    printf("\n");

    for (int k = 0; k < pn; ++k) {
        printf("%d", pair[k]);
    }

    free(pair);
    free(tab);
}*/


// EX3
/*
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void afficheName(char **tab, int n){

    for (int i = 0; i < n; ++i) {
        printf("%s \n", tab[i]);
    }
}


void corrName(char **tab, int n){
    for (int i = 0; i < n; ++i) {
      l  if(tab[i][0] >= 'a' && tab[i][0] <= 'z'){
            tab[i][0]=tab[i][0] + 'A' - 'a';
        }
    }
}

int main(){
    int n = 0, nl = 0;
    char name[100];
    char *p = NULL;
    char **tabPrenom = NULL;

    printf("nb nom : ");
    scanf("%d", &n);

    tabPrenom = malloc(n*sizeof(char*));
    if(tabPrenom == NULL){
        exit(1);
    }

    for (int i = 0; i < n; ++i) {

        printf("name");
        scanf("%s", name);
        nl = strlen((name));
        p = malloc(nl+1*sizeof (char*));
        if(p == NULL){
            printf("??");
            exit(2);
        }
        int j = 0;
        while(name[j] != '\0'){
            p[j]=name[j];
            j++;
        }
        p[j] ='\0';
        tabPrenom[i]=p;
    }

    corrName(tabPrenom, n);
    afficheName(tabPrenom, n);

    free(p);
    free(tabPrenom);
}*/

//EX 4

/*
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int main(int argc, char **argv){

    switch (*argv[2]){// ne fonctionne pas??
        case 43:
            printf("%d + %d = %d", atoi(argv[1]), atoi(argv[3]),atoi(argv[1]) + atoi(argv[3]));
            break;
        case 45:
            printf("%d - %d = %d", atoi(argv[1]), atoi(argv[3]),atoi(argv[1]) - atoi(argv[3]));
            break;
        case 120:
            printf("%d x %d = %d", atoi(argv[1]), atoi(argv[3]),atoi(argv[1]) * atoi(argv[3]));
            break;
        case 47:
            printf("%d / %d = %d", atoi(argv[1]), atoi(argv[3]),atoi(argv[1]) / atoi(argv[3]));
            break;
        default:
            printf("default");


    }

    return(0);
}*/

//EXC 5
/*
#include "stdio.h"
#include "stdlib.h"

void choixNMax(int *n_max){
    int ok = -1;
    while(ok < 0) {

        printf("entrer le nb max");
        scanf("%d", &ok);
    }
    *n_max = ok;
}

int creerTriangle(int n_max, int ***tab){
    printf("up\n");
    //int *p = NULL;

    *tab = malloc((n_max+1) * sizeof(int));
    if(*tab == NULL) {
        printf("tab null");
        exit(1);
    }

    for (int n = 0; n < n_max+1; ++n) {



        (*tab)[n] = malloc((n+1) * sizeof(int));
        if((*tab)[n] == NULL){
            printf("*tab NULL");
            exit(1);
        }

        for (int k = 0; k < n +1; ++k) {
            if(n == k)
            {
                (*tab)[n][k] = 1;
                //p[k] = 1;
                //printf("%d ", p[k]);
            }
            else{
                (*tab)[n][k] = (*tab)[n-1][k-1] + (*tab)[n-1][k];
                //p[k] = *(tab)[n-1][k-1] + *(tab)[n-1][k];
                //printf("%d ", p[k]);
            }
        }
        //(tab)[n] = p;


        //printf("%d", tab[0][0]);
    }
    printf("tab in creer %p\n", tab);
}

void affichePascal(int **tab, int n_max, int n1, int k1){
    int pute;
    printf("tab in affiche %p\n", tab);

    if(tab == NULL){
        printf("affiche : tab null");
        exit(1);
    }
    for (int n = 0; n < n_max+1; ++n) {
        for (int k = 0; k < n+1; ++k) {
            printf("%d ", tab[n][k]);

            if(n1 == n && k1 == k){
                pute = tab[n][k];
            }
        }
        printf("\n");
    }

    printf("pute : %d", pute);
}

int main(){
    int n_max;
    int n, k;

    int **tab = NULL;

    choixNMax(&n_max);

    creerTriangle(n_max, &tab);

    //printf("tab in main %p\n", tab);  // tab ne se transmet pas au main / il est null dans le main

    printf("n et k : ");
    scanf("%d %d", &n, &k);



    affichePascal(tab, n_max, n, k);

}*/

//TD4

//EX1
/*
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"


struct Complex {
    float im;
    float re;
};

int résoudre(float a, float b, float c, struct Complex *res1, struct Complex *res2){

    int delta = pow(b, 2) - 4*a*c;

    if( delta < 0){
        (*res1).im = sqrt(abs(delta)) / 2*a;
        (*res1).re = -b / 2*a;

        if((*res1).im < 0) {

            printf("%f %f i\n", (*res1).re, (*res1).im);
        }
        else{
            printf("%f +%f i\n", (*res1).re, (*res1).im);

        }

        (*res2).im = -sqrt(abs(delta)) / 2*a;
        (*res2).re = -b / 2*a;

        if((*res2).im < 0 ){

            printf("%f %f i\n", (*res2).re, (*res2).im);
        }
        else{
            printf("%f +%f i\n", (*res2).re, (*res2).im);

        }


        return(2);
    }
    else if(delta == 0){

        (*res1).im = 0;
        (*res1).re = -b / 2*a;
        printf("%f\n", (*res1).re);
        return(1);
    }
    else{
        (*res1).im = 0;
        (*res1).re = (-b-sqrt(delta)) / 2*a;
        printf("%f\n", (*res1).re);

        (*res2).im = 0;
        (*res1).re = (-b+sqrt(delta)) / 2*a;;
        printf("%f\n", (*res2).re);

        return(2);
    }
}



int main(){

    struct Complex res1;
    struct Complex res2;

    résoudre(-7,2,-6, &res1, &res2);
}*/

// EX2
/*
#include "stdio.h"

struct nmb_rationel{
    int num;
    int den;
};

typedef struct nmb_rationel nmb_rationel;

void add_mult(struct nmb_rationel *num1, struct nmb_rationel *num2){
    struct nmb_rationel a;
    struct nmb_rationel b;
    (*num1).num = (*num1).num * (*num2).num;
    (*num1).den = (*num1).den * (*num2).den;
    printf("%d/%d\n", (*num1).num, (*num1).den);

    (*num2).num = ((*num1).num*(*num2).den) + ((*num2).num*(*num1).den);
    (*num2).den = (*num1).den * (*num2).den;

    if((*num2).den == 0){
        printf("%d/%d\n", (*num2).num, 0);
    }
    else{
        printf("%d/%d\n", (*num2).num, (*num2).den);

    }
}


nmb_rationel creer_rationel(){
    int n = 0;
    int d = -1;
    struct nmb_rationel cc;
    printf("num den  pls");
    scanf("%d %d", &n, &d);

    if(n < 0 && d < 0){
        cc.num = -n;
        cc.den = -d;
    }
    else if(n < 0 && d >= 0){
        cc.num = n;
        cc.den = d;
    }
    else if(n >= 0 && d < 0){
        cc.num = -n;
        cc.den = d;
    }
    else if(n >= 0 && d >=0){
        cc.num = n;
        cc.den = d;
    }

    return cc;
}


int main(){

    nmb_rationel a;
    nmb_rationel b;

    a =  creer_rationel();
    b =  creer_rationel();

    add_mult(&a, &b);
}*/

//EX 3
/*
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

struct etudiant{
    char* prenom;
    char* nom;
    int nb;
    float* tab_note;
};

typedef struct etudiant etudiant;

etudiant creer_etu(){
    etudiant a;
    a.prenom = NULL;
    a.nom = NULL;

    int gnum = 0;
    char name[100];
    char last_name[100];

    printf("Prenom pls \n");
    scanf("%s", name);
    printf("Nom de famille pls \n");
    scanf("%s", last_name);

    a.prenom = malloc(strlen(name) * sizeof(char));
    a.nom = malloc(strlen(name) * sizeof(char));

    strcpy(a.nom, name);
    strcpy(a.prenom, last_name);


    printf("num groupe pls \n");
    scanf("%d", &gnum);
    int attemp = 0;
    while(gnum <= 0 && attemp < 5){
        printf("erreur num groupe doit être > 0\n");
        scanf("%d", &gnum);
        attemp++;
    }
    a.nb = gnum;

    a.tab_note = malloc(6 * sizeof (int));
    if(!a.tab_note){
        printf("a.tab note null \n");
        exit(1);
    }

    for (int i = 0; i < 6; ++i) {
        a.tab_note[i] = (float)rand() / ((float)(RAND_MAX / 20));
    }

    return a;
}

void affich_etudiant(etudiant a){
    printf("prénom : %s \n", a.prenom);
    printf("nom : %s \n",a.nom);
    printf("num groupe : %d \n", a.nb);
    for (int i = 0; i < 6; ++i) {
        printf("note : %f \n", a.tab_note[i]);
    }
    printf("\n");
}

etudiant* creer_Promo(int* TP){
    etudiant* promo = NULL;
    int taillePromo = 0;
    printf("Taille promo?");

    scanf("%d", &taillePromo);

    while(taillePromo  <= 0){
        printf("erreur la taile de la promo doit être > 0");
        scanf("%d", &taillePromo);
    }

    promo = malloc( taillePromo * sizeof (etudiant));

    for (int i = 0; i < taillePromo; ++i) {
        promo[i] = creer_etu();
    }
    for (int i = 0; i < taillePromo; ++i) {
        affich_etudiant(promo[i]);
    }
    *TP = taillePromo;
    return promo;
}

float MoyGroupe(etudiant* tab, int grp, int taillePromo){
    int n = 0;
    float moy = 0, sum;


    for (int i = 0; i < taillePromo; ++i) {
        if(tab[i].nb == grp){
            for (int j = 0; j < 6; ++j) {
                sum += tab[i].tab_note[j];
                n++;
            }
        }
    }

    moy= sum/n;

    if(n == 0){
        return 0;
    }
    else {
        return moy;
    }
}

void VerifMaj(etudiant* tab, int taille){
    for (int i = 0; i < taille; ++i) {

        if(tab[i].prenom[0] > 97){
            tab[i].prenom[0] = tab[i].prenom[0] - 32;
        }

        if(tab[i].nom[0] > 97){
            tab[i].nom[0] = tab[i].nom[0] - 32;
        }

        affich_etudiant(tab[i]);
    }
}

void tri(etudiant* promo, int taillePromo){
    int a = 0, bool = 0;

    etudiant* holder = NULL;

    holder = malloc(taillePromo * sizeof (etudiant));
    if(!holder){
        exit(1);
    }
    
        for (int i = 1; i < taillePromo; ++i) {
            for (int j = 0; j < taillePromo; ++j) {
                if(promo[i].nom[0] > promo[i - j].nom[0]){


                }
            }

        }


}


int main(){
    int groupe, taillePromo;
    etudiant* promo  = NULL;
    srand(time(NULL));

    promo = creer_Promo(&taillePromo);

    printf("groupe pour la moyenne?\n");
    scanf("%d", &groupe);
    printf("%f\n",MoyGroupe(promo, groupe, taillePromo));
    VerifMaj(promo, taillePromo);

    tri(promo, taillePromo);
}*/

//EX4

/*
#include <stdio.h>
#include "stdlib.h"
#include <time.h>

struct Stats{
    int heure;
    int mobile;
    int ordinateur;

};

typedef struct  Stats Stats;

Stats* creerStats(){
    Stats* stats = NULL;

    stats = malloc(24 * sizeof (Stats));
    if(!stats)
        exit(1);

    for (int i = 0; i < 24; ++i) {
        stats[i].heure = i;
        stats[i].mobile = (int)rand() % 101;
        stats[i].ordinateur = (int)rand() % 101;
    }

    return stats;
}

void showStats(Stats* stats){


    for (int i = 23; i > 0; --i) {
        for (int j = 0; j < stats[i].mobile / 10; ++j) {
            printf("#");
        }
        printf(" |%d|", i);
        for (int j = 0; j < stats[i].ordinateur / 10; ++j) {
            printf("#");
        }
        printf("\n");
    }
}



int main(){
    Stats* Stats = NULL;

    srand(time((NULL)));

    Stats = creerStats();

    showStats(Stats);

    free(Stats);
}*/

//TD 5


//EX1

/*
#include "stdio.h"

int powerIt(int a, int b){

    for (int i = 0; i < b-1; ++i) {
        a = a*a;
    }
    return a;
}

int powerRec(int a, int b){

    if(b == 0){
        a = 1;
    }
    else{
        b--;
        a = a*powerRec(a,b);

    }
    return a;
}

int main(){
    int a = 2, b = 6;
    printf("%d", powerRec(a,b));
}*/


//EX 2
/*
#include "stdio.h"

int bin(int n, int p) {

    int a;

    if (p == 0)
        a = 1;
    else if (n == p){
        a = 1;
    }
    else{
        a = bin(n-1, p-1) + bin(n-1, p);
    }

    return a;

}



int main(){

    int n = 3, p = 2;

    printf("%d", bin(n, p));

}*/


//EX3
/*
#include "stdio.h"
#include "stdlib.h"
#include "time.h"


int* randTab(){
    int* tab;

    int n = 10;

    tab = malloc(n * sizeof (int));
    if(!tab)
        exit(1);

    for (int i = 0; i < n; ++i) {
        tab[i] = rand() % 100;
        printf("%d ", tab[i]);
    }
    printf("\n");

    return tab;
}


void showTab(int* tab, int taille, int lim){

    if(lim < taille){
        printf("%d ", tab[lim]);
        showTab(tab, taille, lim+1);
    }

}

int maxTab(int* tab, int taille, int i, int max){
    if(i < taille){
        if( max < tab[i]){
            max = tab[i];
        }
        return maxTab(tab, taille, i+1, max);


    }
    return max;
}


int divid(int* tab, int taille, int i, int n){

    if(i >0){
        if(tab[i]%3 == 0){
            n++;
        }
        printf("%d", n);

        return divid(tab, taille, i - 1, n);
    }

    return n;
}


int main(){
    int* tab;
    srand(time(NULL));

    tab = randTab();

    showTab(tab, 10, 0);

    printf("\n%d  \n", maxTab(tab, 10, 1, tab[0]));

    printf("%d", divid(tab, 10, 10, 0));

    free(tab);
}*/

//EX4
/*
#include "stdio.h"
#include "stdlib.h"

int sumInt(int a, int b, int s){

    if(a <= b){
        s = a + sumInt(a+1, b, s);
    }
    return s;
}

int sumIntC(int a, int b, int s){

    if(b > a){
        s = b + sumInt(a, b-1, s);
    }
    return s;
}


int main(){
    int a = (rand() % 201) + 100;
    int b = (rand() % 201) + 100;
    printf("%d\n", sumInt(a, b, 0));
    printf("%d\n", sumIntC(a, b, 0));
}*/

//EX5

/*
#include "stdio.h"
#include "math.h"

int sumInt(int a, int length, int s, int n) {

    // Terminale
    if(n < length){
        int c = pow(10,n+1);
        int b = a%c;
        b = b/pow(10, n);
        s = s + b;
        printf("b : %d \n",b);

        a -= b;
        printf("a: %d \n", a);
        printf("s : %d\n", s);
        n++;

        return sumInt(a, length, s, n);

    }
    #END IF

    //non terminale
    if(n < length) {
        int c = pow(10, n + 1);
        int b = a % c;
        b = b / pow(10, n);
        //s = s + b;
        printf("b : %d \n", b);

        a -= b;
        printf("a: %d \n", a);
        printf("s : %d\n", s);
        n++;

        return b + sumInt(a, length, s, n);
    }

    //itératif
    for (int i = 0; i < length; ++i) {
        int c = pow(10,i+1);
        int b = a%c;
        b = b/pow(10, i);
        s = s + b;
        printf("b : %d \n",b);

        a -= b;
        printf("a: %d \n", a);
        printf("s : %d\n", s);

    }
    return s;
}


int main(){
    printf("%d\n", sumInt(3807, 4, 0, 0));
}
*/


//TD7 compléxité sur papier

//TD8


//EX1
/*
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(){
    FILE* file = NULL;
    int letter = 0;
    char phrase[200];
    int a, b;
    float c;
    file = fopen( "texte.txt", "r+");

    if(!file){
        exit(15);
    }



    letter = fgetc(file );

    fscanf(file, "%d %d %f", &a, &b, &c);

    float f = a + c;
    printf("f : %f, a : %d , b : %d\n", f, a, b);
    //printf("%s", fgets(phrase, 199, file));// récuperes pas le prmier caractères

}*/


//EX2

#include "stdlib.h"
#include "stdio.h"



int nmbCharactere(FILE* file, char a){

    int count = 0;

    fseek(file, 0, 0);

    while(fgetc(file) != EOF){
        if(fgetc(file) == a){
            count++;
        }
    }

    return count;
}

int main(){

    FILE* file = NULL;
    char content[200];
    char space[1] = {' '};
    int bool = 1, count = 0;
    int tab[27];


    file = fopen("HarryPotter.txt", "w+");


    if(!file){
        exit(12);
    }

    printf("Tape 0 quand finie d'entrer\n");
    printf("entre le text a écrire\n");
    while(bool){

        scanf("%s", content);

        fputs(content, file);

        scanf("%d", &bool);

        if(bool){
            content[0] = '\0';
            fputs(space, file);
        }
    }

    fseek(file, 0, 0);


    while(fgetc(file) != EOF){
        count++;
    }



    fflush(stdin);
    printf("nb character : %d \n", count);


    for (int i = 0; i < 26; ++i) {
        tab[i] = nmbCharactere(file, i + 65) + nmbCharactere(file, i + 97);
        printf(" %c : %d ;      ", i+97, tab[i]);
        printf("prob %c : %d ; \n", i+97, tab[i] / count);
    }

    tab[26] = nmbCharactere(file, 8);
    printf(" space : %d ;      ", tab[26]);
    printf("prob space : %d ; \n",tab[26] / count);

    //Compter les espaces aussi


    while(fgetc(file) != EOF){
        fscanf(file, "%s", content);
        printf("content : %s; \n", content);


    }



}




