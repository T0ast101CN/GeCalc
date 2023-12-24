// @@@         @@@        @
//@   @       @   @       @        TM
//@      @@@  @      @@@  @   @@@
//@ @@@ @   @ @         @ @  @   @
//@   @ @@@@@ @      @@@@ @  @
//@   @ @     @   @ @   @ @  @   @   by T0astForeveR & Faver
// @@@   @@@@  @@@   @@@@  @  @@@    (c) MMXXIII

#include <cstdio>
#include <cmath>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cfloat>

time_t timeStamp = time(nullptr);

double x1, x2, prevResult = DBL_MAX; //Solutions to quadratic equation, floating numbers.
int crossSolveResult[2][2]={{0, 0}, {0, 0}}; //Cross-solve solutions to quadratic equation, floating numbers.

void vPrint(const std::vector<double>& vec){   //Vector printing, used for debugging
    for(double i : vec) printf("%lf ", i);
    printf("\n");
}

void ePrint(double a,double b,double c){    //Equation printing
    printf("%lfx ^ 2 ",a);
    if(b>0) printf("+ %lfx ",b);
    else if(b<0) printf("- %lfx ",-b);
    if((b==0&&c==0)||c==0) printf("= 0\n");
    else if(c>0) printf("+ %lf = 0\n",c);
    else if(c<0) printf("- %lf = 0\n",-c);
}

void quadEquationSolve(double a,double b,double c){
    double d=pow(b,2)-4*a*c;
    x1=(-b+std::sqrt(d))/2*a;
    x2=(-b-std::sqrt(d))/2*a;
}

void crossSolve(int a,int b,int c){
    for(int i=-abs(int(std::sqrt(a)));i<=abs(int(std::sqrt(a)));i++){
        if((i!=0)&&(a%i==0)){
            for(int j=-abs(c);j<=abs(c);j++){
                if((j!=0)&&(c%j==0)){
                    if(i*(c/j)+j*(a/i)==b){
                        crossSolveResult[0][0]=i;
                        crossSolveResult[0][1]= a / i;
                        crossSolveResult[1][0]=j;
                        crossSolveResult[1][1]= c / j;
                        break;
                    }
                }
            }
        }
    }
}

void clearScreen() {
    system("CLS");
    //printf("--------------------------------\n");
}

void init(){    //Initializing splash
    clearScreen();
    printf(" @@@         @@@        @          \n");
    printf("@   @       @   @       @        TM\n");
    printf("@      @@@  @      @@@  @   @@@    \n");
    printf("@ @@@ @   @ @         @ @  @   @   \n");
    printf("@   @ @@@@@ @      @@@@ @  @       \n");
    printf("@   @ @     @   @ @   @ @  @   @   \n");
    printf(" @@@   @@@@  @@@   @@@@  @  @@@    \n");
    printf("--------------------------------\n");
    printf("General Calculator by T0astForeveR & Faver\nVersion 0.1.9\tBuild 2312233\tSystemTime %lld\n", timeStamp);
    Sleep(1500);
    clearScreen();
}

void about(){   //About page
    clearScreen();
    printf(" @@@         @@@        @          \n");
    printf("@   @       @   @       @        TM\n");
    printf("@      @@@  @      @@@  @   @@@    \n");
    printf("@ @@@ @   @ @         @ @  @   @   \n");
    printf("@   @ @@@@@ @      @@@@ @  @       \n");
    printf("@   @ @     @   @ @   @ @  @   @   \n");
    printf(" @@@   @@@@  @@@   @@@@  @  @@@    \n");
    printf("--------------------------------\n");
    printf("General Calculator by T0astForeveR & Faver\nVersion 0.1.9\tBuild 2312233\tSystem Time %lld\n", timeStamp);
    printf("--------------------------------\n");
    printf("CrossSolve - by Faver @ https://space.bilibili.com/501018696\n");
    printf("C++ Coding - by T0astForeveR @ https://space.bilibili.com/225255578\n");
    printf("--------------------------------\n");
    printf("Project URL - https://github.com/T0ast101CN/GeCalc\n");
    printf("This calculator follows CC BY-SA 4.0 license.\n");
    system("pause");
}

double rad(double a){   //Angle to radian
    const double PI = 3.14159265;
    return a*PI/180;
}

bool isInt(double a){
    double b = pow(10,-6.0);
    if((a-(int)a<b) && (a-(int)a>-b)) return true;
    else return false;
}

double variance(const std::vector<double>& data){
    double accumulate = 0;
    for(double i : data) accumulate += i;
    double m = 0, average = accumulate / data.size();
    for(double i : data) m += pow(i-average,2);
    return m / data.size();
}

double median(std::vector<double>& data){
    if(!data.size()%2) return ((data[data.size()/2-1]+data[data.size()/2])/2);
    else return data[(data.size()+1)/2-1];
}

int main() {
    init();
    while("false"){
        printf("Enter calculation type\n> 1 | arithmetics\n> 2 | tri-function\n> 3 | quad-equation\n> 4 | statistics\n> 9 | about\n> 0 | exit\n\n> ");
        int t; scanf("%d", &t);
        switch (t) {
            case 0: return 0;
            case 9: {
                about();
                break;
            }
            case 1: {   //Arithmetics
                arith:
                clearScreen();
                if(prevResult != DBL_MAX) printf("Previous result = %lf\n--------------------------------\n", prevResult);
                printf("Enter arithmetic type\n> 1 | add(+)\n> 2 | subtract(-)\n> 3 | multiply(*)\n> 4 | divide(/)\n> 5 | power(^)\n> 6 | sq-root(^(1/2))\n> 7 | cb-root(^(1/3))\n> 0 | return\n\n> ");
                int u; scanf("%d", &u);
                switch (u) {
                    case 0: break;
                    case 1: {
                        clearScreen();
                        printf("Enter data\n> ");
                        scanf("%lf", &prevResult);
                        clearScreen();
                        add:
                        printf("%lf + ", prevResult);
                        double b;
                        scanf("%lf", &b);
                        clearScreen();
                        opAdd:
                        printf("%lf + %lf = %lf\n", prevResult, b, prevResult + b);
                        prevResult += b;
                        printf("--------------------------------\n");
                        printf("> 1 | add(+) again\n> 0 | return\n\n> ");
                        int v;
                        scanf("%d",&v);
                        switch(v){
                            case 0:{
                                clearScreen();
                                goto arith;
                            }
                            case 1:{
                                clearScreen();
                                goto add;
                            }
                            default: {
                                clearScreen();
                                printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                                system("pause");
                                goto opAdd;
                            }
                        }
                    }
                    case 2: {
                        clearScreen();
                        printf("Enter data\n> ");
                        scanf("%lf", &prevResult);
                        clearScreen();
                        min:
                        printf("%lf - ", prevResult);
                        double b;
                        scanf("%lf", &b);
                        clearScreen();
                        opMin:
                        printf("%lf - %lf = %lf\n", prevResult, b, prevResult - b);
                        prevResult -= b;
                        printf("--------------------------------\n");
                        printf("> 1 | subtract(-) again\n> 0 | return\n\n> ");
                        int v;
                        scanf("%d",&v);
                        switch(v){
                            case 0:{
                                clearScreen();
                                goto arith;
                            }
                            case 1:{
                                clearScreen();
                                goto min;
                            }
                            default: {
                                clearScreen();
                                printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                                system("pause");
                                goto opMin;
                            }
                        }
                    }
                    case 3: {
                        clearScreen();
                        printf("Enter data\n> ");
                        scanf("%lf", &prevResult);
                        clearScreen();
                        mul:
                        printf("%lf * ", prevResult);
                        double b;
                        scanf("%lf", &b);
                        clearScreen();
                        opMul:
                        printf("%lf * %lf = %lf\n", prevResult, b, prevResult * b);
                        prevResult *= b;
                        printf("--------------------------------\n");
                        printf("> 1 | multiply(*) again\n> 0 | return\n\n> ");
                        int v;
                        scanf("%d",&v);
                        switch(v){
                            case 0:{
                                clearScreen();
                                goto arith;
                            }
                            case 1:{
                                clearScreen();
                                goto mul;
                            }
                            default: {
                                clearScreen();
                                printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                                system("pause");
                                goto opMul;
                            }
                        }
                    }
                    case 4: {
                        clearScreen();
                        printf("Enter data\n> ");
                        scanf("%lf", &prevResult);
                        clearScreen();
                        div:
                        printf("%lf / ", prevResult);
                        double b;
                        scanf("%lf", &b);
                        clearScreen();
                        opDiv:
                        printf("%lf / %lf = %lf\n", prevResult, b, prevResult / b);
                        prevResult /= b;
                        printf("--------------------------------\n");
                        printf("> 1 | divide(/) again\n> 0 | return\n\n> ");
                        int v;
                        scanf("%d",&v);
                        switch(v){
                            case 0:{
                                clearScreen();
                                goto arith;
                            }
                            case 1:{
                                clearScreen();
                                goto div;
                            }
                            default: {
                                clearScreen();
                                printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                                system("pause");
                                goto opDiv;
                            }
                        }
                    }
                    case 5: {
                        clearScreen();
                        printf("Enter data\n> ");
                        scanf("%lf", &prevResult);
                        clearScreen();
                        pow:
                        printf("%lf ^ ", prevResult);
                        double b;
                        scanf("%lf", &b);
                        clearScreen();
                        opPow:
                        printf("%lf ^ %lf = %lf\n", prevResult, b, pow(prevResult, b));
                        prevResult = pow(prevResult, b);
                        printf("--------------------------------\n");
                        printf("> 1 | power(^) again\n> 0 | return\n\n> ");
                        int v;
                        scanf("%d",&v);
                        switch(v){
                            case 0:{
                                clearScreen();
                                goto arith;
                            }
                            case 1:{
                                clearScreen();
                                goto pow;
                            }
                            default: {
                                clearScreen();
                                printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                                system("pause");
                                goto opPow;
                            }
                        }
                    }
                    case 6: {
                        clearScreen();
                        printf("Enter data\n> ");
                        scanf("%lf", &prevResult);
                        clearScreen();
                        printf("%lf ^ (1/2) = %lf\n", prevResult, std::sqrt(prevResult));
                        prevResult = std::sqrt(prevResult);
                        system("pause");
                        goto arith;
                    }
                    case 7: {
                        clearScreen();
                        printf("Enter data\n> ");
                        scanf("%lf", &prevResult);
                        clearScreen();
                        printf("%lf ^ (1/3) = %lf\n", prevResult, std::cbrt(prevResult));
                        prevResult = std::sqrt(prevResult);
                        system("pause");
                        goto arith;
                    }
                    default: {
                        clearScreen();
                        printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                        system("pause");
                        goto arith;
                    }
                }
                break;
            }
            case 2:{
                tri:
                clearScreen();
                printf("Enter function type\n> 1 | sine\n> 2 | cosine\n> 3 | tangent\n> 4 | cotangent\n> 5 | secant\n> 6 | cosecant\n> 0 | return\n\n> ");
                int u; scanf("%d",&u);
                switch (u) {
                    case 0: break;
                    case 1:{    //Tri-functions
                        clearScreen();
                        printf("Enter data\n> ");
                        double a; scanf("%lf", &a);
                        clearScreen();
                        printf("sin(%lf) = %lf\n", a, sin(rad(a)));
                        system("pause");
                        goto tri;
                    }
                    case 2:{
                        clearScreen();
                        printf("Enter data\n> ");
                        double a; scanf("%lf", &a);
                        clearScreen();
                        printf("cos(%lf) = %lf\n", a, cos(rad(a)));
                        system("pause");
                        goto tri;
                    }
                    case 3:{
                        clearScreen();
                        printf("Enter data\n> ");
                        double a; scanf("%lf", &a);
                        clearScreen();
                        printf("tan(%lf) = %lf\n", a, tan(rad(a)));
                        system("pause");
                        goto tri;
                    }
                    case 4:{
                        clearScreen();
                        printf("Enter data\n> ");
                        double a; scanf("%lf", &a);
                        clearScreen();
                        printf("cot(%lf) = %lf\n", a, 1/tan(rad(a)));
                        system("pause");
                        goto tri;
                    }
                    case 5:{
                        clearScreen();
                        printf("Enter data\n> ");
                        double a; scanf("%lf", &a);
                        clearScreen();
                        printf("sec(%lf) = %lf\n", a, 1/cos(rad(a)));
                        system("pause");
                        goto tri;
                    }
                    case 6:{
                        clearScreen();
                        printf("Enter data\n> ");
                        double a; scanf("%lf", &a);
                        clearScreen();
                        printf("csc(%lf) = %lf\n", a, 1/sin(rad(a)));
                        system("pause");
                        goto tri;
                    }
                    default: {
                        clearScreen();
                        printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                        system("pause");
                        goto tri;
                    }
                }
                break;
            }
            case 3:{    //Equations
                clearScreen();
                printf("The Original Formula : ax^2+bx+c (a!=0)\n");
                double a,b,c;
                printf("Enter a: "); scanf("%lf",&a);
                if(a==0){
                    clearScreen();
                    printf("Are you stupid or something?  (Exception.invalidQuadraticCoefficient)\n");
                    system("pause");
                    break;
                }
                printf("Enter b: "); scanf("%lf",&b);
                printf("Enter c: "); scanf("%lf",&c);
                double d=pow(b,2)-4*a*c;
                if(d<0){
                    clearScreen();
                    printf("There's no real solution to this equation (Exception.deltaUnderZero)\nwith delta value %lf\n",d);
                    system("pause");
                    break;
                }
                clearScreen();
                quad:
                ePrint(a,b,c);
                printf("with delta value %lf\n--------------------------------\n",d);
                if(!isInt(a)||!isInt(b)||!isInt(c)) printf("Enter solving type\n> 1 | numeric\n> - cross-solve (disabled: integer coefficients only)\n> 0 | return\n\n> ");
                else if(c==0) printf("Enter solving type\n> 1 | numeric\n> - cross-solve (disabled: c = 0)\n> 0 | return\n\n> ");
                else printf("Enter solving type\n> 1 | numeric\n> 2 | cross-solve\n> 0 | return\n\n> ");
                int u; scanf("%d",&u);
                switch (u) {
                    case 0: break;
                    case 1:{
                        clearScreen();
                        ePrint(a,b,c);
                        quadEquationSolve(a,b,c);
                        printf("Solution: ");
                        if(x1==x2) printf("x1 = x2 = %lf\n",x1);
                        else printf("x1 = %lf , x2 = %lf\n",x1,x2);
                        system("pause");
                        clearScreen();
                        goto quad;
                    }
                    case 2:{
                        if(c==0||!isInt(c)){
                            clearScreen();
                            printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                            system("pause");
                            clearScreen();
                            goto quad;
                        }
                        clearScreen();
                        ePrint(a,b,c);
                        crossSolve((int)a,(int)b,(int)c);
                        printf("Solution:\n");
                        printf("%d\t%d\n%d\t%d\n", crossSolveResult[0][0], crossSolveResult[1][0], crossSolveResult[0][1], crossSolveResult[1][1]);
                        system("pause");
                        clearScreen();
                        goto quad;
                    }
                    default: {
                        clearScreen();
                        printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                        system("pause");
                        clearScreen();
                        goto quad;
                    }
                }
                break;
            }
            case 4:{    //Statistics
                clearScreen();
                printf("Enter amount of data: ");
                int inputCount=0,amount=0;
                scanf("%d",&amount);
                if (!amount) {
                    clearScreen();
                    printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                    system("pause");
                    break;
                }
                clearScreen();
                printf("Enter data\n");
                double data[amount];
                for(double & i : data){
                    printf("data[%d/%d] = ",++inputCount,amount);
                    scanf("%lf", &i);
                }
                clearScreen();
                int weighted = 0;
                stat:
                std::vector<double> vecData (data, data+amount);
                if(!weighted) printf("Data:\n");
                else printf("Data(%d):\n",weighted+1);
                for(int i=0;i<amount;i++) printf("data[%d] = %lf\n",i+1,data[i]);
                if(amount-1){
                    printf("--------------------------------\n");
                    double accumulate = 0, var = variance(vecData);
                    for (double i: vecData) accumulate += i;
                    printf("Accumulate = %lf\n", accumulate);
                    printf("Average = %lf\n", accumulate / amount);
                    printf("Variance = %lf\n", var);
                    printf("Std. Deviation = %lf\n", std::sqrt(var));
                    printf("Median = %lf\n", median(vecData));
                    if (weighted) {
                        printf("--------------------------------\n");
                        printf("> 1 | set weightings again\n> 0 | return\n\n> ");
                    } else {
                        printf("--------------------------------\n");
                        printf("> 1 | set weightings\n> 0 | return\n\n> ");
                    }
                }
                else{
                    if (weighted) {
                        printf("--------------------------------\n");
                        printf("> 1 | go multiplying again\n> 0 | return\n\n> ");
                    } else {
                        printf("--------------------------------\n");
                        printf("> 1 | go multiplying\n> 0 | return\n\n> ");
                    }
                }
                int v;
                scanf("%d",&v);
                switch(v){
                    case 0: break;
                    case 1:{
                        clearScreen();
                        for(int i=0;i<amount;i++){
                            double alt;
                            printf("data[%d] = %lf * ",i+1,data[i]);
                            scanf("%lf",&alt);
                            data[i] *= alt;
                        }
                        weighted++;
                        clearScreen();
                        goto stat;
                    }
                    default: {
                        clearScreen();
                        printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                        system("pause");
                        clearScreen();
                        goto stat;
                    }
                }
                break;
            }
            default: {
                clearScreen();
                printf("Are you stupid or something? (Exception.unexpectedInput)\n");
                system("pause");
                break;
            }
        }
        printf("\n");
        clearScreen();
    }
}
