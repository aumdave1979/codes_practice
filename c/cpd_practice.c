#include<stdio.h>

void problem1(int n){
    printf("C programing");
}

void problem2(int n){
    printf("Aum Dave");
}

void problem3(int n){
    printf("Oscar sky park");
}

void problem4(int n){
    printf("Enter the integer: ");
    scanf("%d",&n);
    printf("%d",n);
}

void problem5(int n){
    if(n>0){
        printf("It is greater than 0");
    }
    else if(n==0){
        printf("It is equal to 0");
    }
    else{
        printf("It is less than 0");
    }
}

void problem6(int x,int y){
    int square1 =x*x;
    int square2 = y*y;
    int cube1 = x*x*x;
    int cube2 = y*y*y;
    printf("square of 1st is: %d",square1);
    printf("square of 2nd is: %d",square2);
    printf("cube of 1st is: %d",cube1);
    printf("cube of 2nd is: %d",cube2);

}

void problem7(int x,int y){
    printf("The addittion: %d",x+y);
    printf("The multiplication: %d",x*y);
    printf("the substraction: %d",x-y);
    printf("The divition: %d",x/y);
}

void problem8(int c,int d,int g, int h){
    int l=(c+d)*(g+h);
    printf("the answer: %d",l);
}

void problem9(int k,int a){
    int z = ((k-4)*(a*4)/100);
    printf("The answer is %d",z);
}

void problem10(int a,int b,int c){
    int s=((4*a+c)-2*a*b)/100;
    printf("The answer is %d",s);
}

void problem11(int p,int r,int n){
    int a = p*(1+(r/100)/n)-p;
    printf("The answer is %d",a);
}

void problem12(int v,int s,int l,int m){
    int t = ((v+s)+(l-m)*l);
    printf("The answer is %d",t);
}

void problem13(int r){
    float area = 3.14*r*r;
    printf("The area is %f",area);
}

void problem14(int hieght , int base){
    float area = 0.5*base*hieght;
    printf("The area is %f",area);
}

void problem15(int a,int b){
    int c = (a+b)*(a+b);
    printf("The answer is %d",c);
}

 void problem16(int p,int r,int t){
    float interest = (p*r*t)/100;
    printf("the SI is %d",interest);
}

void problem17(int rupees){
    float dollar = 90*rupees;
    printf("The dollar is %d",dollar);
}

void problem18(int number , int cost){
    int total_cost = number*cost;
    printf("Total cost is %d",total_cost);
}

void problem19(int n){
    scanf("%d",n);
    if(n>0){
        printf("Greater");
    }
    else if (n==0){
        printf("Equal to zero");
    }
    else{
        printf("less than 0");
    }
}

void problem20(int x,int y){
    scanf("Enter numbes %d %d",&x,&y);
    if(x>y){
        printf("X is greater");
    }
    else{
        printf("Y is greater");
    }
}

void problem21(int x,int y){
    printf("");
}

void problem22(int x,int y){
    if(x>y){
        printf("Y is minimum");
    }
    else{
        printf("x is minimum");
    }
}

void problem23(int x,int y){

}

void problem24(int x,int y,int z){
    if(x>y && x>z){
        printf("x is greater");
    }
    else if(y>x && y>z){
        printf("Y is greater");
    }
    else{
        printf("z is greater");
    }
}

void problem84(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d",j);
        }
    printf("\n");
    }
}

void problem85(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d",i);
        }
    printf("\n");
    }
}

void problem86(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d",i*j);
        }
    }
}

void problem87(int n){
    char ch ='A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c",ch);
        }
    ch++;
    printf("\n");
    }
}

void problem88(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d",i);
        }
    printf("\n");
    }
}

void problem89(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
    printf("\n");
    }
}

void problem90(int n){
    for(int i=n;i>=1;i--){
        for(int j=n;j>=i;j--){
            printf("%d",j);
        }
    printf("\n");
    }
}

void problem91(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            printf("%d",j);
        }
    printf("\n");
    }
}

void problem92(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            printf("%d",i+j);
        }
    printf("\n");
    }
}

void problem93(int n){
    for(int i=1;i<=n;i++){
    printf("1");
        for(int j=1;j<=i;j++){
            printf("0");
        }
    }
}

void problem94(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            printf("%d",(i+j)%2);
        }
    printf("\n");
    }
}

void problem95(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d",j%2);
        }
    printf("\n");
    }
}

void problem96(int n){
    char ch ='a';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%c",ch);
        }
    ch++;
    printf("\n");
    }
}

void problem97(int n){
    char ch='a';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%c ",ch);
            ch++;
        }
    printf("\n");
    }
}

void problem98(int n){
    char ch='z';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%c ",ch);
            ch--;
        }
    printf("\n");
    }
}

void problem99(int n){
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            printf("%d",j);
        }
    printf("\n");
    }
}

void problem100(int n){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
    printf("\n");
    }
}

void problem101(int n){
    int k=1;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("%d ",k*j);
        }
    k++;
    printf("\n");
    }
}

void problem102(int n){
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            printf("%d ",j);
        }
    printf("\n");
    }
}

void problem103(int n){
    for(int i=n;i>=1;i--){
        for(int j=i;j>=1;j--){
            printf("%d ",j);
        }
    printf("\n");
    }
}

void problem104(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            printf("%d",j);
        }
    printf("\n");
    }
}

void problem105(int n){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("%d",i);
        }
    printf("\n");
    }
}

void problem106(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            printf("%d ",j*2);
        }
    printf("\n");
    }
}

void problem107(int n){
    char ch='a';
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            printf("%c ",ch+j);
        }
    ch='a';
    printf("\n");

    }
}

void problem108(int n){
   printf("1\n");
   int k=3;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",k);
            k++;
        }
    k++;
    printf("\n");
    }
}

void problem109(int n){
    printf("*\n");
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
    printf("\n");
    }
}

void problem110(int n){
    for(int i=1;i<=n;i++){
        //for space
        for(int j=n;j>=i;j--){
            printf("  ");
        }
        //for numbers
        for(int k=1;k<=i;k++){
            printf("%d   ",k);
        }
    printf("\n");
    }
}

void problem111(int n){
    for(int i=1;i<=n;i++){
        //spaces
        for(int j=n;j>=i;j--){
            printf("  ");
        }
        //for number;
        for(int k=1;k<=i;k++){
            printf("%d   ",k%2);
        }
    printf("\n");
    }
}

void problem112(int n){
    for(int i=1;i<=n;i++){
    printf("%d",i);
        for(int j=1;j<2*i;j++){
            printf(" * ");
        }
    printf("\n");
    }
}

void problem113(int n){

}

void problem114(){

}

void problem115(){
    int arr[5];
    printf("Enter 5 numbers: ");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<5;j++){
        printf("%d ",arr[j]);
    }
    printf("%d",arr[5]);
}

void problem116(){
    int arr[5];
    int temp;
    printf("Enter 5 numbers to sort: ");
    for(int i=1;i<=10;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<5;i++){
        if(arr[i]>arr[i+1]){
            
        }
    }

}

int main(){
    problem115();
}