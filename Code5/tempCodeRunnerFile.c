/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    typedef struct 
    {
        float radius;
        
        
    }
    CIRCLE;
    
    typedef struct
    {
        float side;
        
    }
    SQUARE;
    
    typedef struct 
    {
        float side1;
        float side2;
        
    }
    RECTANGLE;
    
    typedef struct
    {
        float base;
        float height;
    }
    TRIANGE;
    
    union shape
    {
        CIRCLE circle;
        SQUARE square;
        RECTANGLE rectangle;
        TRIANGE triangle;
    };
    
    enum 
    {
        circle = 1, square, rectangle, triangle
    };
    
    int MyShape;
    union shape Enteredshape;
    
    printf("Find the are of shape\n\n");
    printf("1. Circle\n2. Square\n3. Rectangle\n4. Triangle\n\nEnter Choice: ");
    scanf("%d", &MyShape);
    switch (MyShape)
    {
        case (circle): 
            printf("Enter radius: ");
            scanf("%f", &Enteredshape.circle.radius);
            printf("The area of your cicle is: %f\n", 3.14 * pow(Enteredshape.circle.radius,2));
            break;
        case (rectangle):
            printf("Enter side 1: ");
            scanf("%f", &Enteredshape.rectangle.side1);
            printf("Enter side 2: ");
            scanf("%f", &Enteredshape.rectangle.side2);
            printf("The area of your square is %f\n", Enteredshape.rectangle.side1*Enteredshape.rectangle.side2);
            break;
        case (square) :
            printf("Enter length of one side: ");
            scanf("%f", &Enteredshape.square.side);
            printf("The area of your square is: %f", pow(Enteredshape.square.side,2));
            break;
        case (triangle) :
            printf("Enter the length of the base ");
            scanf("%f", &Enteredshape.triangle.base);
            printf("Enter the length of the height ");
            scanf("%f", &Enteredshape.triangle.height);
            printf("The area of your triangle is %f\n",(Enteredshape.triangle.base * Enteredshape.triangle.height) / 2);
            break;
        default : 
            printf("You are out of shape\n");
    }
        
}
    
